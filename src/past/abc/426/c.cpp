# include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    int x, y;
    cin >> N >> Q;
    vector<int> os(N + 1, 1);
    os[0] = 0;

    int o = 1;
    for (int q = 0; q < Q; q++) {
        int count = 0;
        cin >> x >> y;
        while (o <= x) {
            count += os[o];
            os[y] += os[o];
            o++;
        }
        cout << count << endl;
    }
}