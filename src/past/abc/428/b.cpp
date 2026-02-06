# include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    string S;
    cin >> N >> K;
    cin >> S;
    vector<string> str(N - (K - 1));
    int count = 0;
    for (int i = 0; i < N - (K - 1); i++) {
        for (int j = 0; j < K; j++) {
            if ((j + count) > (N - 1));
            else str[i] += S.at(j + count);
        }
        count += 1;
    }
    sort(str.begin(), str.end());

    string s1 = str[0];
    int n = 1;
    int n_max = 0;
    vector<bool> f(N - (K - 1), false);
    for (int i = 1; i < (N - (K - 1)); i++) {
        if (s1 == str[i]) {
            n += 1;
            if (n > n_max) n_max = n;
        } else {
            n = 1;
            s1 = str[i];
        }
    }
    cout << n_max << endl;
    s1 = str[0];
    for (int i = 0; i < N - (K - 1); i++) {
        if (f[i] == true && s1 != str[i]) cout << str[i] << ' ';
        else {;}
    }
    return 0;
}