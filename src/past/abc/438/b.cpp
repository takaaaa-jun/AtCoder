#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    if (!(cin >> N >> M)) return 0;
    string S, T;
    cin >> S >> T;
    int min_diff = 2147483647;
    for (int i = 0; i < (N - M + 1); i++) {
        int current_diff = 0;
        for (int j = 0; j < M; j++) {
            int s_val = S[i + j] - '0';
            int t_val = T[j] - '0';
            if ((s_val - t_val) >= 0) {
                current_diff += s_val - t_val;  
            } else {
                current_diff += ((s_val - t_val) + 10);
            }
        }
        if (current_diff < min_diff) {
            min_diff = current_diff;
        }
    }
    cout << min_diff << endl;
    return 0;
}