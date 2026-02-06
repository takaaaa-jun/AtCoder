#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int K, A, B;
    cin >> K >> A >> B;
    bool ok = false;
    for (int i = A; i <= B; ++i) {
        if (i % K == 0) {
            ok = true;
        }
    }
    if (ok) {
        cout << "OK" << endl;
    } else {
        cout << "NG" << endl;
    }
    return 0;
}
