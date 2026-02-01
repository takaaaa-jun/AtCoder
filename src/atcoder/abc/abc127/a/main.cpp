#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int A, B;
    cin >> A >> B;
    if (A <= 5) {
        cout << 0 << endl;
    } else if (A <= 12) {
        cout << B / 2 << endl;
    } else {
        cout << B << endl;
    }
    return 0;
}
