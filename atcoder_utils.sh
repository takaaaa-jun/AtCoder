# AtCoder Workflow Tools
# Usage: source /app/atcoder_utils.sh

# --- Configuration ---
TEMPLATE_PATH="/app/templates/atcoder.cpp"
# Compile flags
CXX_FLAGS="-std=c++20 -DLOCAL"

# --- Helper Functions ---

_check_contest_id() {
    if [ -z "$1" ]; then
        echo "Usage: $0 <contest_id> (e.g. abc424)"
        return 1
    fi
}

# --- Commands ---

mkc() {
    contest_id=$1
    if [ -z "$contest_id" ]; then
        echo "Usage: mkc <contest_id> (e.g. mkc abc424)"
        return 1
    fi

    echo "=== Setting up Contest: $contest_id ==="

    # 1. Use acc to create the contest directory structure
    if command -v acc &> /dev/null; then
        echo "Running acc new $contest_id..."
        # Running in a subshell or jumping back might be needed if we want to stay in root, 
        # but typically users want to go into the directory. 
        # But acc new creates the directory in the CURRENT dir.
        # We should probably go to src/atcoder/abc or similar if we want to organize.
        # However, to be safe and simple, let's just create it where the user is 
        # OR follow the pattern from abc_dl.sh: src/atcoder/abc/$CONTEST_ID
        
        # Let's try to stick to the abc_dl.sh pattern if we can, or just current dir.
        # The user's prompt implies "loading problems", which usually implies downloading.
        # Let's check if we are in the root or deeper.
        
        # If we are at /app, let's try to put it in src/atcoder/abc if it looks like an ABC
        if [[ "$contest_id" =~ ^abc[0-9]+$ ]]; then
             target_base="/app/src/atcoder/abc"
             mkdir -p "$target_base"
             cd "$target_base" || return
        fi

        acc new "$contest_id"
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
            # Note: User's abc_dl.sh used ${CONTEST_ID}_${problem_dir}.cpp, 
            # but standardizing on main.cpp is often easier for tools. 
            # I will stick to main.cpp as seen in the active document /app/src/atcoder/abc/abc424/a/main.cpp
            
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
        fi
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
        # Check if test directory exists
        if [ ! -d "test" ] && [ ! -d "tests" ]; then
             echo "Downloading tests..."
             # We need the URL. acc usually puts it in contest.json or we can guess.
             # Or we assume the user has already downloaded them via acc new.
             # If not, 'oj d' might verify login.
             # Simple fallback: prompt or just run oj t and let it fail/warn.
             echo "Warning: 'test' directory not found. 'oj t' might fail if tests aren't downloaded."
        fi
        oj t -c "./a.out"
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
    else
        echo "Directory ../$target not found."
    fi
}

atcoder_help() {
    echo "AtCoder Utils:"
    echo "  mkc <contest_id>  : Create/Download contest (e.g., mkc abc300)"
    echo "  cptest            : Compile main.cpp and run oj tests"
    echo "  next              : Go to next problem (a -> b)"
    echo "  prev              : Go to previous problem (b -> a)"
    echo "  goto <char>       : Go to specific problem (goto c)"
}
