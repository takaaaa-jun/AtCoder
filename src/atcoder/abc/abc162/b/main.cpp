#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    ll N;
    cin >> N;
    ll ans = 0;
    for (ll i = 1; i <= N; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            continue;
        } else {
            ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}
