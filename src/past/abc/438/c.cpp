# include <bits/stdc++.h>
using namespace std;

int main() {
    long int N;
    cin >> N;
    vector<long int> A(N + 1, 0);
    for (int i = 1; i < N + 1; i++) {
        cin >> A[i];
    }
    vector<bool> clear(N + 1, false);
    long int flag = 0;
    while (flag < 1000000) {
        int count = 0;
        for (int i = 2; i < N + 1; i++) {
            if (count == 3) {
                count = 0;
                clear[i] = true;
                clear[i - 1] = true;
                clear[i - 2] = true;
                clear[i - 3] = true;
            }
            if (A[i] == A[i - 1] && clear[i] == false) {
                count++;
            } else if (A[i] != A[i - 1] && clear[i] == false) {
                count = 0;
            }
        }
        flag += 1;
    }
    int ans = 0;
    for (int i = 1; i < N + 1; i++) {
        if (clear[i] == false) {
            ans += 1;
        }
    }
    if (ans > 4) {
        cout << ans - 4 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}