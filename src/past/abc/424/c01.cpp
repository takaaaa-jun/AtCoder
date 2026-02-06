#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N + 1), B(N + 1);
    A[0] = B[0] = -1;
    vector<bool> F(N + 1, false);
    int skill = 0;

    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
        if (A[i] == 0 && B[i] == 0) {
            F[i] = true;
            skill++;
        }
    }

    bool updated = true;
    while (updated) {
        updated = false;
        for (int i = 1; i <= N; i++) {
            if (!F[i] && (F[A[i]] || F[B[i]])) {
                F[i] = true;
                skill++;
                updated = true;
            }
        }
    }

    cout << skill << endl;
    return 0;
}
