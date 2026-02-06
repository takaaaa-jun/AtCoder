# include <bits/stdc++.h>
using namespace std;

int main() {
  int num = 0;
  int sum = 0;
  cin >> num;
  for (int i = 1; i < num + 1; i++){
    sum += (pow(-1, i)) * (pow(i, 3));
  }
  cout << sum << endl;
}
