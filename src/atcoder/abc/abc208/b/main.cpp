#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    ll P;
    cin >> P;
    vector<ll> fact(12, 0);
    fact[1] = 1;
    for (ll i = 2; i <= 11; i++) {
        fact[i] = fact[i - 1] * i;
    }
    ll ans = 0;
    for (ll i = 11; i >= 1; i--) {
        ans += P / fact[i];
        P %= fact[i];
    }
    cout << ans << endl;
    return 0;
}
