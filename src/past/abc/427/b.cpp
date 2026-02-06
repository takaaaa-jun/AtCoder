# include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> ans(101,0);
    ans[0] = 1;
    ans[1] = 1;
    int a, b, c, d;
    for (int i = 2; i < N + 1; i++) {
        a = ans[i - 1] / 1000;
        b = (ans[i - 1] / 100) % 10;
        c = (ans[i - 1] / 10) % 10;
        d = ans[i - 1] % 10;
        ans[i] = ans[i - 1] + (a + b + c + d);
    }
    cout << ans[N] << endl;
    return 0;
}
