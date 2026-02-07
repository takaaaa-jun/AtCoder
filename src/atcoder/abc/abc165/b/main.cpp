#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    ll X;
    cin >> X;
    int count = 0;
    ll tmp = 100;
    while (tmp < X) {
        tmp += tmp / 100;
        count++;
    }
    cout << count << endl;
    return 0;
}
