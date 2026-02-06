# include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> u(M);
    vector<int> v(M);
    vector<vector<int>> uv(N + 1);
    for (int i = 1; i < M + 1; i++) {
        cin >> u[i] >> v[i];
        uv[u[i]].push_back(v[i]);
        uv[v[i]].push_back(u[i]);
    }

    return 0;
}
