# include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A(N + 1, 0);
    vector<long int> count(N + 1, 0);
    long long int combo = 0;
    for (int i = 1; i < N + 1; i++) {
        cin >> A[i];
        count[A[i]] += 1;
    }
    for (int i = 1; i < N + 1; i++) {
        if (count[i] > 1) {
            long long int n = 0;
            n = (((count[i]) * (count[i] - 1)) / 2) * (N - (count[i]));
            combo += n;
        }
    }
    cout << combo << endl;
    return 0;
}