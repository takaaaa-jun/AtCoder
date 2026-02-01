#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int X, A, B;
    cin >> X >> A >> B;
    int k = (X - A) % B;
    cout << k << endl;
    return 0;
}
