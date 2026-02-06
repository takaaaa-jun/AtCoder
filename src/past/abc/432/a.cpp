# include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C;
    vector<int> vec(3);
    cin >> A >> B >> C;
    vec[0] = A, vec[1] = B, vec[2] = C;
    sort(vec.rbegin(), vec.rend());
    for(int i = 0; i < 3; i++){
        cout << vec[i];
    }
    cout << endl;
    return 0;
}