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
    int day, sum;
    sum = 0;
    rep(i, N + 1) {
        sum += i;
        if (sum >= N) {
            day = i;
            break;
        }
    }
    cout << day << endl;
    return 0;
}
