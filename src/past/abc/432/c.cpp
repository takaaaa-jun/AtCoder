# include <bits/stdc++.h>
using namespace std;

int main() {
    long int N, X, Y;
    cin >> N >> X >> Y;
    vector<long int> A(N, 0);
    long int l = 0;
    long int r = numeric_limits<long>::max();
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (X * A[i] > l) {l = X * A[i];}
        if (X * A[i] < r) {r = X * A[i];}
    }
    for (int i = l; i < (r + 1); i++) {
        
    }
    
}