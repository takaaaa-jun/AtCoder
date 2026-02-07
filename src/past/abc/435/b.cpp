# include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N + 1, 0);
    vector<int> sum(N + 1, 0);
    for (int i = 1; i < N + 1; i++) {
        cin >> A[i];
        sum[i] = sum[i - 1] + A[i];
    }
    int ans = 0;
    for (int l = 1; l < N + 1; l++) {
        for (int r = l; r < N + 1; r++) {
            int s = sum[r] - sum[l - 1];
            int k = r - l + 1;
            int count = 0;
            for (int i = 0; i < k; i++) {
                if (s % (A[l + i]) == 0) count++;
            }
            if (count == 0) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}