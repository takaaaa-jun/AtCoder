# include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N + 1);
    vector<int> B(N + 1);
    A[0] = -1;
    B[0] = -1;
    vector<bool> F(N + 1, false);
    int skill = 0;
    for (int i = 1; i < N + 1; i++) {
        cin >> A[i] >>B[i];
        if (A[i] == 0 && B[i] == 0) {
            F[i] = true;
            skill += 1;
        }
    }
    for (int i = 1; i < N + 1; i++) {
        if (F[A[i]] == true || F[B[i]] == true) {
            F[i] = true;
            skill += 1;
        }
    }
    cout << skill << endl;
}