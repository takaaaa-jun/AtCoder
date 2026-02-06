# include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    int k = 0;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    vector<vector<int>> query(Q, vector<int> (3));
    for (int i = 0; i < Q; i++) {
        cin >> query[i][0];
        if (query[i][0] == 1) {
            for (int j = 1; j < 2; j ++) {
                cin >> query[i][j];
            }
            query[i][2] = 0;
        } else {
            for (int j = 1; j < 3; j ++) {
                cin >> query[i][j];
            }
        }
    }

    for (int i = 0; i < Q; i++) {
        int sum = 0;
        if (query[i][0] == 1) {
            k += query[i][1];
        } else {
            int start = ((query[i][1] - 1) + (k % N)) % N;
            for (int j = start; j < (start + (query[i][2] - query[i][1] + 1)); j++) {
                sum += A[j % N];
            }
            cout << sum << endl;
        }
    }
}