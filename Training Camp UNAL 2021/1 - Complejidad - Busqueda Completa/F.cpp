#include <bits/stdc++.h>

using namespace std;

int main() {
    string a; getline(cin, a);
    string res = "";
    res += a[0];
    for (int i = 1; i < a.length(); i++) {
        if (a[i] == ' ') {
            if (a[i - 1] != ' ') res += a[i];
        } else if (a[i] == ',' || a[i] == '.' || a[i] == '?' || a[i] == '!') {
            if (a[i - 1] == ' ') res.pop_back();
            res += a[i];
        } else {
            if (a[i - 1] == ',' || a[i - 1] == '.' || a[i - 1] == '?' || a[i - 1] == '!') {
                res += " ";
            }
            res += a[i];
        }
    }
    cout << res << '\n';
    return 0;
}