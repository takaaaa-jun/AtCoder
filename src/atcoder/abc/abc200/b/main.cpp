#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    ll N, K;
    cin >> N >> K;
    while (K > 0) {
        if (N % 200 == 0) {
            N = N / 200;
            K = K - 1;
        } else {
            ll a, b, c, d, e;
            a = N / 10000;
            b = (N % 10000) / 1000;
            c = (N % 1000) / 100;
            d = (N % 100) / 10;
            e = N % 10;
            N = a * 10000000 + b * 1000000 + c * 100000 + d * 10000 + e * 1000 + 200;
            K = K - 1;
        }
    }
    cout << N << endl;
    return 0;
}
