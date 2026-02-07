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
    cout << max(A + B, max(A - B, A * B)) << endl;
    return 0;
}
