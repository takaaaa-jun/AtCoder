#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    int k = N % 2;
    if (k == 0) {
        cout << N / 2 << endl;
    } else {
        cout << (N / 2) + 1 << endl;
    }
    return 0;
}
