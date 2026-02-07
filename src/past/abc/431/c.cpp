# include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    vector<int> B(M);
    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }
    sort(H.begin(), H.end());
    sort(B.begin(), B.end());

    int i = 0;
    int j = 0;
    int count = 0;
    while (i < N && j < M && count < K)
    {
        if (H[i] <= B[j]) {
            count += 1;
            i += 1;
            j += 1;
        } else {
            j += 1;
        }
    }
    if (count >= K) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}