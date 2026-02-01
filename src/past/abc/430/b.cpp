# include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    string s;
    vector<vector<string>> S(N, vector<string>(N));
    vector<string> ans((N - M + 1) * (N - M + 1));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> s;
            S[i][j] = s;
        }
    }

    int n1 = 0;
    int n2 = 0;
    for (int i = 0; i < ((N - M + 1) * (N - M + 1)); i++) {
        s = "";
        if (n1 > (N - M)) {
            n1 = 0;
            n2 += 1;
        }
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < M; k++) {
                s += S[n2 + j][n1 + k];
            }
        }
        ans[i] = s;
        n1 += 1;
    }

    int count = (N - M + 1) * (N - M + 1);
    for (int i = 0; i < ((N - M + 1) * (N - M + 1) - 1); i++) {
        if (ans[i] == ans[i + 1]) count -= 1;
    }
    cout << count << endl;
    return 0;
}