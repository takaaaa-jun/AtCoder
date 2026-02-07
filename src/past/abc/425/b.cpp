#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    vector<int> p(N, 0);
    vector<bool> used(N + 1, false);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        if (a[i] != -1) {
            if (used[a[i]]) {
                cout << "No" << endl;
                return 0;
            }
            p[i] = a[i];
            used[a[i]] = true;
        }
    }
    vector<int> unused_nums;
    for (int i = 1; i <= N; i++) {
        if (!used[i]) {
            unused_nums.push_back(i);
        }
    }
    int unused_idx = 0;
    for (int i = 0; i < N; i++) {
        if (a[i] == -1) {
            p[i] = unused_nums[unused_idx];
            unused_idx++;
        }
    }
    cout << "Yes" << endl;
    for (int i = 0; i < N; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
    return 0;
}