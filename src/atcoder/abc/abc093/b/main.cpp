#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    ll A, B, K;
    cin >> A >> B >> K;
    vector<ll> ans;
    if (K < B - A) {
        rep(i, K) {
            ans.push_back(A + i);
        }
        rep(i, K) {
            if (A + i != B - i) {
                ans.push_back(B - i);
            }
        }
    } else {
        rep(i, B - A + 1) {
            ans.push_back(A + i);
        }
    }
    sort(ans.begin(), ans.end());
    rep(i, ans.size()) {
        cout << ans[i] << endl;
    }
    return 0;
}
