#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    int n = 100 * r + 10 * g + b;
    if (n % 4 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
