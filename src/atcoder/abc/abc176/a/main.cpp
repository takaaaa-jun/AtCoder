#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int N, X, T;
    cin >> N >> X >> T;
    int k = N % X;
    if (k == 0) {
        cout << N / X * T << endl;
    } else {
        cout << ((N / X )+ 1) * T << endl;
    }
    return 0;
}
