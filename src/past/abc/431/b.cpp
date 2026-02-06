# include <bits/stdc++.h>
using namespace std;

int main() {
    int X, N, Q;
    cin >> X >> N;
    vector<int> W(N);
    vector<int> w(N, false);
    for (int i = 0; i < N; i++) {
        cin >> W[i];
    }
    cin >> Q;
    vector<int> P(Q);
    for (int i = 0; i < Q; i++) {
        cin >> P[i];
    }

    for (int i = 0; i < Q; i++) {
        if (w[P[i] - 1] == false) {
            X += W[P[i] - 1];
            w[P[i] - 1] = true;
        } else if (w[P[i] - 1] == true) {
            X -= W[P[i] - 1];
            w[P[i] - 1] = false;
        }
        cout << X << endl;
    }
    return 0;
}