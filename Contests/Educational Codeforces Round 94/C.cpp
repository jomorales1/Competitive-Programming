#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int x = 0;
    cin >> x;
    vector<char> w(s.length(), '-');
    for (int i = 0; i < s.length(); i++) {
        if(s[i] == '1') {
            if (i - x >= 0 && i - x < s.length()) {
                if (w[i - x] == '0') {
                    cout << -1 << '\n';
                    return;
                }
                if (w[i - x] == '-')
                    w[i - x] = '1';
            }
            if (i + x >= 0 && i + x < s.length()) {
                if (w[i + x] == '0') {
                    cout << -1 << '\n';
                    return;
                }
                if (w[i + x] == '-')
                    w[i + x] = '1';
            }
        } else {
            if (i - x >= 0 && i - x < s.length()) {
                if (w[i - x] == '1') {
                    cout << -1 << '\n';
                    return;
                }
                if (w[i - x] == '-')
                    w[i - x] = '0';
            }
            if (i + x >= 0 && i + x < s.length()) {
                if (w[i + x] == '1') {
                    cout << -1 << '\n';
                    return;
                }
                if (w[i + x] == '-')
                    w[i + x] = '0';
            }
        }
    }
    string res = "";
    for (int i = 0; i < s.length(); i++) {
        if (w[i] == '-') {
            cout << -1 << '\n';
            return;
        }
        res += w[i];
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