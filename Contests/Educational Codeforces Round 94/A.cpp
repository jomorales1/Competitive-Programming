#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0;
    cin >> n;
    string s;
    cin >> s;
    string res = "";
    for (int i = 0; i < 2 * n - 1; i += 2) {
        res += s[i];
    }
    cout << res << '\n';
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}