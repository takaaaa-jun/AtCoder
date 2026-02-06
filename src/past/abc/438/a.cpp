# include <bits/stdc++.h>
using namespace std;

int main() {
    int D, F;
    cin >> D >> F;
    while(D >= F) {
        F += 7;
    }
    cout << F - D << endl;
    return 0;
}