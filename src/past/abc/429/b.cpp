# include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    int sum = 0;
    int f = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    for (int i = 0; i < N; i++) {
        if ((sum - A[i]) == M) {
            f = 1;
        }
    }
    if (f == 0) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}