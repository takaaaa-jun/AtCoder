# include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    char t;
    int count = 0;
    cin >> s;
    int slen = s.length();
    t = s[0];
    vector<bool> used(slen, false);
    for (int i = 0; i < slen; i++) {
        if (s[i] == t) {
            used[i] = true;
            count += 1;
        }
    }
    if (count == 1) {
        for (int i = 0; i < slen; i++) {
            if (used[i] == true) cout << s[i] << endl;
        }
    } else {
        for (int i = 0; i < slen; i++) {
            if (used[i] == false) cout << s[i] << endl;
        }
    }
}