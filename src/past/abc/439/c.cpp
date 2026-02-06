# include <bits/stdc++.h>
using namespace std;

int main() {
    long int N;
    cin >> N;
    vector<int> count(N + 1, 0);
    for (long int x = 1; x * x < N; ++x) {
        for (long int y = x + 1; x * x + y * y <= N; ++y) {
            count[x * x + y * y]++;
        }
    }
    vector<long int> ans;
    for (int i = 1; i <= N; ++i) {
        if (count[i] == 1) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << ans[i] << (i == ans.size() - 1 ? "" : " ");
    }
    cout << endl;
    return 0;
}