# include <bits/stdc++.h>
using namespace std;

int main() {
    int X, C;
    cin >> X >> C;
    int count = X / (1000 + C);
    cout << 1000 * count << endl;
    return 0;
}
