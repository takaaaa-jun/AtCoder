# include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> NM(N, vector<int> (M, 0));
    vector<int> A(K);
    vector<int> B(K);
    for (int i = 0; i < K; i++) {
        cin >> A[i] >> B[i];
        NM[A[i] - 1][B[i] - 1] = 1;
        int count = 0;
        int j = 0;
        while (NM[A[i] - 1][j] == 1 && j < M) {
            j += 1;
            count += 1;
        }
        if (count == M) cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}