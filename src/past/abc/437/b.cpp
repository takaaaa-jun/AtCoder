# include <bits/stdc++.h>
using namespace std;

int main() {
    int H, W, N;
    cin >> H >> W >> N;
    vector<vector<int>> A(H + 1, vector<int>(W + 1, 0));
    for (int i = 1; i < H + 1; i++) {
        for (int j = 1; j < W + 1; j++) {
            cin >> A[i][j];
        }
    }
    vector<int> B(N + 1, 0);
    for (int i = 1; i < N + 1; i++) {
        cin >> B[i];
    }
    sort(B.begin(), B.end());
    vector<int> ans(H + 1, 0);
    for (int i = 1; i < H + 1; i++) {
        int counterA = 1;
        int counterB = 1;
        int n = 0;
        while (counterA < W + 1 && counterB < N + 1) {
            sort(A[i].begin(), A[i].end());
            if (A[i][counterA] > B[counterB]) {
                counterB++;
            } else if (A[i][counterA] < B[counterB]) {
                counterA++;
            } else {
                n++;
                counterA++;
                counterB++;
            }
        }
        ans[i] = n;
    }
    sort(ans.begin(), ans.end());
    cout << ans[H] << endl;
    return 0;
}