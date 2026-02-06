# include <bits/stdc++.h>
using namespace std;

int main() {
    long int N;
    cin >> N;
    vector<long int> A(N + 1, 0);
    vector<bool> ai(N + 1, false);
    vector<bool> aj(N + 1, false);
    vector<bool> ak(N + 1, false);
    for (long int i = 1; i <= N; i++) {
        cin >> A[i];
        if (A[i] % 7 == 0) {
            ai[i] = true;
        } if (A[i] % 5 == 0) {
            aj[i] = true;
        } if (A[i] % 3 == 0) {
            ak[i] = true;
        }
    }
    int ans = 0;
    for (long int i = 1; i <= N; i++) {
        int counti = 0;
        int countk = 0;
        if (aj[i] == true) {
            for (long int j = 1; j < i; j++) {
                if (ak[j] == true) {
                    countk++;
                } if (ai[j] == true && ak[j] != true) {
                    counti++;
                }
                ans += counti * countk;
                counti = 0;
                countk = 0;
            }
            for (long int j = i + 1; j <= N; j++) {
                if (ak[j] == true) {
                    countk++;
                } if (ai[j] == true && ak[j] != true) {
                    counti++;
                }
                ans += counti * countk;
                counti = 0;
                countk = 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}