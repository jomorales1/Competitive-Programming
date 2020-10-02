#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    int n = (int) s.length();
    for (int i = 1; i < n - 1; i++) {
        if (s[i] == s[i - 1]) {
            if (s[i - 1] != 'a' && s[i + 1] != 'a') {
                s[i] = 'a';
            } else if (s[i - 1] != 'b' && s[i + 1] != 'b') {
                s[i] = 'b';
            } else {
                s[i] = 'c';
            }
        }
    }
    if (n > 1) {
        if (s[n - 2] == s[n - 1]) {
            if (s[n - 2] != 'a') {
                s[n - 1] = 'a';
            } else {
                s[n - 1] = 'b';
            }
        }
    }
    cout << s << '\n';
    return 0;
}