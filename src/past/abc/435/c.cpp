# include <bits/stdc++.h>
using namespace std;

int main() {
    long int N;
    cin >> N;
    vector<long int> A(N + 1, 0);
    vector<long int> B(N + 1, 0);
    for (int i = 1; i < N + 1; i++) {
        cin >> A[i];
        B[i] = A[i] + i;
    }
    long int k = 0;
    long int i = 1;
    while (k != B[i]) {
        k = B[i];
        sort(B.begin(), B.begin() + i);
        if (k < N + 1) i = k - 1;
        else break;
    }
    if (k > N) cout << N << endl;
    else cout << k - 1 << endl;
    return 0;
}