# include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    vector<long long> Asum(N + 1, 0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (i == 0) Asum[i + 1] = A[i];
        else Asum[i + 1] = A[i] + Asum[i];
    }

    vector<vector<int>> query(Q, vector<int> (3));
    for (int i = 0; i < Q; i++) {
        cin >> query[i][0];
        if (query[i][0] == 1) {
            cin >> query[i][1];
            query[i][2] = 0;
        } else {
            cin >> query[i][1] >> query[i][2];
        }
    }
    long long start = 0;
    for (int i = 0; i < Q; i++) {
        if (query[i][0] == 1) {
            start += query[i][1];
        } else {
            long long l = (start + query[i][1] - 1) % N;
            long long r = (l + query[i][2] - query[i][1]) % N;
            if (l <= r) {
                cout << Asum[r + 1] - Asum[l] << endl;
            } else {
                cout << Asum[N] - (Asum[l] - Asum[r + 1]) << endl;
            }
        }
    }
    return 0;
}