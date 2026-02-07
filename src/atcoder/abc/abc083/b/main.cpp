#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int a, b, c, d, e;
        a = i / 10000;
        b = (i / 1000) % 10;
        c = (i / 100) % 10;
        d = (i / 10) % 10;
        e = i % 10;
        if (a + b + c + d + e >= A && a + b + c + d + e <= B) {
            ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}
