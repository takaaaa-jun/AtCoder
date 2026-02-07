# include <iostream>
using namespace std;

int main() {
    string S;
    cin >> S;

    int n = (int)(S.length()) / 2 + 1;
    for (int i = 0; i < (int)(S.length()); i++) {
        if (i == n - 1) {}
        else cout << S[i];
    }
    cout << endl;
    return 0;
}