# include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int start = 0;
    int end = 0;
    vector<int> L(N + 1);
    L[0] = 0;
    for (int i = 1; i < N + 1; i++) {
        cin >> L[i];
    }

    for (int i = 0; i < N + 1; i++) {
        if (L[i] == 1 && start == 0) {
            start = i;
            end = i;
        } else if (L[i] == 1 && start != 0) {
            end = i;
        } else {}
    }
    cout << end - start << endl;
}
