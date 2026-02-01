# include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> T(N + 1, 0);
    vector<vector<int>> num(N + 1, vector<int>(2, 0));
    for (int i = 1; i < N + 1; i++) {
        cin >> T[i];
        num[i][0] = i;
        num[i][1] = T[i];
    }
    sort(num.begin(), num.end(), [](const vector<int> &alpha, const vector<int> &beta) { return alpha[1] < beta[1]; });
    for (int i = 1; i < 4; i++) {
        cout << num[i][0] << " ";
    }
    cout << endl;
    return 0;
}