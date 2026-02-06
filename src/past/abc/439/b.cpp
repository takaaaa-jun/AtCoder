# include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int k = N;
    while ((k / 10) > 0) {
        int a, b, c, d;
        a = k / 1000;
        b = (k / 100) % 10;
        c = (k / 10) % 10;
        d = k % 10;
        int n;
        n = pow(a, 2) + pow(b, 2) + pow(c, 2) + pow(d, 2);
        k = n;
    }
    if (k == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}