#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int x = 0;
    cin >> x;
    vector<char> w(s.length(), '1');
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '0') {
            if (i - x >= 0 && i - x < s.length()) {
                w[i - x] = '0';
            }
            if (i + x >= 0 && i + x < s.length()) {
                w[i + x] = '0';
            }
        }
    }
    vector<char> s2(s.length(), '0');
    for (int i = 0; i < s.length(); i++) {
        if (i - x >= 0 && i - x < s.length()) {
            if (w[i - x] == '1') {
                s2[i] = '1';
                if (s2[i] != s[i]) {
                    cout << -1 << '\n';
                    return;
                }
            }
        }
        if (i + x >= 0 && i + x < s.length()) {
            if (w[i + x] == '1') {
                s2[i] = '1';
                if (s2[i] != s[i]) {
                    cout << -1 << '\n';
                    return;
                }
            }
        }
        if (s2[i] != s[i]) {
            cout << -1 << '\n';
            return;
        }
    }
    for (char &c : w) {
        cout << c;
    }
    cout << '\n';
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}