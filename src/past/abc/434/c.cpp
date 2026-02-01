# include <bits/stdc++.h>
using namespace std;

int main() {
    int T, N;
    cin >> T;
    long int H;
    vector<int> nlist(T, 0);
    for (int i = 0; i < T; i++) {
        cin >> N >> H;
        vector<long int> t(N + 1, 0) , l(N + 1, 0), u(N + 1, 0);
        vector<long double> la(N + 1, 0), ua(N + 1, 0);
        nlist[i] = N;
        l[0] = H;
        u[0] = H;
        for (int j = 1; j < N + 1; j++) {
            long double d = 0;
            cin >> t[j] >> l[j] >> u[j];
            d = l[j]  + (-1 * t[j]);
            if ((l[j]  + (-1 * t[j])) < 0) d = 0;
            la[j] = d;
            d = u[j] + t[j];
            ua[j] = d;
        }
        int count = 0;
        for (int j = 0; j < nlist[i]; j++) {
            if (l[j] >= la[j] && u[j] <= ua[j]) {
                count++;
            } else if (l[j] < la[j] && u[j] >= la[j]) {
                count++;
            } else if (l[j] > la[j] && l[j] <= ua[j]) {
                count++;
            } 
        }
        if (count == nlist[i]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}