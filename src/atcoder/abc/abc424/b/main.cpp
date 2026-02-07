#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> A(K);
    rep(i, K) cin >> A[i];
    vector<P> B(K);
    rep(i, K) cin >> B[i].first >> B[i].second;
    vector<bool> used(N + 1, false);
    rep(i, K) {
        used[B[i].first] = true;
        used[B[i].second] = true;
    }
    
    return 0;
}
