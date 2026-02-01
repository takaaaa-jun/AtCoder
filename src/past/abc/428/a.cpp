# include <bits/stdc++.h>
using namespace std;

int main() {
    int S, A, B, X;
    cin >> S >> A >> B >> X;

    int n = X / (A + B);
    int m = X % (A + B);
    int len = S * A * n;
    if (A >= m) len += S * m;
    else len += S * A;
    cout << len << endl;
}