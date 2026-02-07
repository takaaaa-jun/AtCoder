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
    if (B % A == 0) {
        cout << B + A << endl;
    } else {
        cout << B - A << endl;
    }
    return 0;
}
