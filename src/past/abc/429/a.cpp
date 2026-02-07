# include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        if (i > M - 1) cout << "Too Many Requests" << endl;
        else cout << "OK" << endl;
    }
    return 0;
}