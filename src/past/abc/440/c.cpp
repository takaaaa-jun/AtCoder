#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long N, W;
    cin >> N >> W;
    vector<long long> C(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
    int MOD = 2 * W;
    vector<long long> bucket(MOD, 0);
    for (int i = 0; i < N; i++) {
        bucket[(i + 1) % MOD] += C[i];
    }
    vector<long long> D = bucket;
    D.insert(D.end(), bucket.begin(), bucket.end());
    long long current_sum = 0;
    for (int i = 0; i < W; i++) {
        current_sum += D[i];
    }
    long long ans = current_sum;
    for (int i = 0; i < MOD; i++) {
        current_sum -= D[i];
        current_sum += D[i + W];
        if (current_sum < ans) {
            ans = current_sum;
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}