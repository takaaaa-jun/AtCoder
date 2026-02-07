# include <bits/stdc++.h>
using namespace std;

int main() {
    int X;
    cin >> X;
    string s = to_string(X);
    int n = s.size();
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        int k = int(s[i]-'0');
        ans[i] = k;
    }
    sort(ans.begin(), ans.end());
    int p = -1;
    int j = 0;
    while(p == -1) {
        if (ans[j] != 0) {
            p = j;
        }
        j++;
    }
    int temp = ans[p];
    ans[p] = ans[0];
    ans[0] = temp;
    for (int i = 0; i < n; i++) {
        cout << ans[i];
    }
    cout << endl;
    return 0;
}