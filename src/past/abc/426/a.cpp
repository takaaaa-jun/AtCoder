# include <bits/stdc++.h>
using namespace std;

int main() {
    string o = "Ocelot";
    string s = "Serval";
    string l = "Lynx";
    string sx, sy;
    cin >> sx;
    cin >> sy;
    if (
        (sx == "Ocelot" && sy == "Ocelot") ||
        (sx == "Serval" && (sy == "Serval" || sy == "Ocelot")) ||
        (sx == "Lynx")
    ) cout << "Yes" << endl;
    else cout << "No" << endl;
}