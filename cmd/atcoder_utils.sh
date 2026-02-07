# AtCoder Workflow Tools
# Usage: source /app/atcoder_utils.sh

# --- Configuration ---
TEMPLATE_PATH="/app/templates/cpp/main(template).cpp"
# Compile flags
CXX_FLAGS="-std=c++20 -DLOCAL"

# --- Helper Functions ---


_open_editor() {
    local file="${1:-main.cpp}"
    local cmd=""

    # 1. Try to detect VS Code command support
    if command -v code &> /dev/null; then
        cmd="code"
    elif command -v agy &> /dev/null; then
        cmd="agy"
    elif [ -n "$VSCODE_GIT_ASKPASS_NODE" ]; then
        local base_dir=$(dirname "$VSCODE_GIT_ASKPASS_NODE")
        if [ -x "$base_dir/bin/remote-cli/agy" ]; then
            cmd="$base_dir/bin/remote-cli/agy"
        fi
    fi

    # 2. Execute or Fallback
    if [ -n "$cmd" ]; then
        # VS Code Dev Container mode detected
        "$cmd" -r "$file" 2>/dev/null &
    else
        # Login.bat (Raw Docker) mode detected
        # Print a clickable link for VS Code terminal
        # Convert absolute path to relative path from workspace root for cleaner display
        local abs_path="$(pwd)/$file"
        # Assuming /app is the workspace root
        local rel_path="${abs_path#/app/}"
        
        echo -e "\n\033[1;36m[OPEN] Click to open: $rel_path\033[0m\n"
    fi
}

mkc() {
    contest_id=$1
    if [ -z "$contest_id" ]; then
        echo "Usage: mkc <contest_id> (e.g. mkc abc424)"
        return 1
    fi

    # Load credentials from .env
    if [ -f /app/.env ]; then
        # Use export variables from .env if in KEY=VALUE format
        export $(grep -v '^#' /app/.env | xargs)
    fi

    echo "=== Setting up Contest: $contest_id ==="

    # 1. Use acc to create the contest directory structure
    if command -v acc &> /dev/null; then
        echo "Running acc new $contest_id..."
        
        # Navigate to appropriate directory
        if [[ "$contest_id" =~ ^abc[0-9]+$ ]]; then
             target_base="/app/src/atcoder/abc"
             mkdir -p "$target_base"
             cd "$target_base" || return
        fi

        # Check if user/pass are set
        if [ -n "$ATCODER_USERNAME" ] && [ -n "$ATCODER_PASSWORD" ]; then
             echo "Using credentials from .env..."
             # Export again to be sure expect sees them (already exported above, but good for clarity)
             export ATCODER_USERNAME ATCODER_PASSWORD
             
             # Use expect to handle prompts
             # We use $env(VAR) to safely access variables inside expect without shell interpolation issues
             # We use glob patterns (*...*) to handle potential color codes and variations
             expect -c "
                set timeout 30
                spawn acc new $contest_id
                expect {
                    \"*username:*\" { send \"\$env(ATCODER_USERNAME)\r\"; exp_continue }
                    \"*password:*\" { send \"\$env(ATCODER_PASSWORD)\r\"; exp_continue }
                    \"*select tasks*\" { send \"\r\"; exp_continue }
                    eof
                }
             "
        else
             acc new "$contest_id"
        fi

    else
        echo "Warning: 'acc' command not found. Creating directory manually."
        mkdir -p "$contest_id"
    fi

    # 2. Enter and Setup Templates
    if [ -d "$contest_id" ]; then
        cd "$contest_id" || return
        echo "Entered contest directory: $(pwd)"
        
        # Copy templates to tasks (a, b, c, c2, d, e, f, g, h or similar)
        # acc usually creates subdirectories like "a", "b", "c".
        for dir in */; do
            problem_dir=${dir%/}
            dest_file="${problem_dir}/main.cpp" 
            
            if [ ! -f "$dest_file" ]; then
                if [ -f "$TEMPLATE_PATH" ]; then
                    cp "$TEMPLATE_PATH" "$dest_file"
                    echo "Created $dest_file"
                else
                    echo "Warning: Template not found at $TEMPLATE_PATH"
                    touch "$dest_file"
                fi
            fi
        done
        
        # Go to 'a' by default
        if [ -d "a" ]; then
            cd "a"
        # If 'a' doesn't exist (maybe numeric tasks?), just try first dir
        elif [ -d "A" ]; then
            cd "A"
        fi
        
        # Open editor for main.cpp in current dir
        _open_editor "main.cpp"
        
    else
        echo "Error: Contest directory not created."
        return 1
    fi
}

cptest() {
    # Check if main.cpp exists
    if [ ! -f "main.cpp" ]; then
        # Try to find any .cpp file
        cpp_file=$(find . -maxdepth 1 -name "*.cpp" | head -n 1)
        if [ -z "$cpp_file" ]; then
            echo "Error: No .cpp file found in current directory."
            return 1
        fi
    else
        cpp_file="main.cpp"
    fi

    echo "Compiling $cpp_file..."
    g++ $CXX_FLAGS "$cpp_file" -o a.out
    if [ $? -ne 0 ]; then
        echo "Compilation Failed."
        return 1
    fi

    echo "Running Tests (oj)..."
    if command -v oj &> /dev/null; then
        # Check if tests directory exists (acc default is 'tests')
        TEST_DIR=""
        if [ -d "tests" ]; then
            TEST_DIR="tests"
        elif [ -d "test" ]; then
            TEST_DIR="test"
        fi

        if [ -z "$TEST_DIR" ]; then
             echo "Tests not found. Downloading..."
             # Assumes we are in a contest problem directory (e.g. atcoder/abc/abc169/a)
             # Try to construct URL. acc usually downloads tests, verifying why they are missing.
             # If manual created or acc failed.
             
             # Fallback: prompt implies "reading problems" was done, maybe just not passed to oj?
             # Let's try to infer URL.
             # PWD: .../abc169/a
             prob_char=$(basename "$PWD")
             contest_dir=$(dirname "$PWD")
             contest_id=$(basename "$contest_dir")
             
             # Basic heuristic for AtCoder URL
             url="https://atcoder.jp/contests/${contest_id}/tasks/${contest_id}_${prob_char}"
             echo "Attempting download from $url"
             oj d "$url"
             
             # Re-check
             if [ -d "tests" ]; then TEST_DIR="tests"; elif [ -d "test" ]; then TEST_DIR="test"; fi
        fi
        
        if [ -n "$TEST_DIR" ]; then
            oj t -c "./a.out" -d "$TEST_DIR"
        else
            # Try running without -d, maybe it just downloaded
            oj t -c "./a.out"
        fi
    else
        echo "Error: 'oj' command not found."
    fi
}

next() {
    current=$(basename "$PWD")
    # a -> b, b -> c, etc.
    if [[ "$current" =~ ^[a-z]$ ]]; then
        next_prob=$(python3 -c "print(chr(ord('$current')+1))")
        if [ -d "../$next_prob" ]; then
            cd "../$next_prob" || return
            echo "Moved to: $next_prob"
            _open_editor "main.cpp"
        else
            echo "Next problem ($next_prob) not found."
        fi
    else
        echo "Not in a problem directory (single letter)."
    fi
}

prev() {
    current=$(basename "$PWD")
    if [[ "$current" =~ ^[a-z]$ ]]; then
        prev_prob=$(python3 -c "print(chr(ord('$current')-1))")
        if [ -d "../$prev_prob" ]; then
            cd "../$prev_prob" || return
            echo "Moved to: $prev_prob"
            _open_editor "main.cpp"
        else
            echo "Prev problem ($prev_prob) not found."
        fi
    else
        echo "Not in a problem directory (single letter)."
    fi
}

goto() {
    target=$1
    if [ -z "$target" ]; then
        echo "Usage: goto <prob_char> (e.g., goto b)"
        return 1
    fi
    if [ -d "../$target" ]; then
        cd "../$target" || return
        echo "Moved to: $target"
        _open_editor "main.cpp"
    else
        echo "Directory ../$target not found."
    fi
}

home() {
    cd "/app/src/atcoder/abc" || return
    echo "Moved to: $(pwd)"
}


atcoder_help() {
    echo "AtCoder Utils:"
    echo "  mkc <contest_id>  : Create/Download contest (e.g., mkc abc300)"
    echo "  cptest            : Compile main.cpp and run oj tests"
    echo "  next              : Go to next problem (a -> b)"
    echo "  prev              : Go to previous problem (b -> a)"
    echo "  goto <char>       : Go to specific problem (goto c)"
    echo "  home              : Go to contest root (/app/src/atcoder/abc)"
}
