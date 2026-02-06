# include <bits/stdc++.h>
using namespace std;

int main() {
    double N, M;
    cin >> N >> M;
    vector<double> A(N, 0), B(N, 0);
    vector<double> count(M + 1,0), sum(M + 1,0);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        cin >> B[i];
        count[A[i]] += 1;
        sum[A[i]] += B[i];
    }
    for (int i = 1; i < M + 1; i++){
        double n = 0.0;
        n = sum[i] / count[i];
        cout << fixed << setprecision(20) << n << endl;
    }
    return 0;
}