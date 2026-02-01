# include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> W(N);
    vector<long int> H(N);
    vector<long int> B(N);
    int Hsum = 0;
    int Bsum = 0;
    for (int i = 0; i < N; i++) {
        cin >> W[i] >> H[i] >> B[i];
        Hsum += H[i];
        Bsum += B[i];
    }
    long long int p;
}