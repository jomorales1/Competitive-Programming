#include <bits/stdc++.h>

using namespace std;

int mod(int a, int b) {
    int c = a % b;
    return (c < 0) ? c + b : c;
}

void solve() {
    int n = 0; cin >> n;
    string s; cin >> s;
    int res = 0;
    bool full = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == '-' || s[mod(i - 1, n)] == '-') {
            res++;
        } else {
            int steps = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == '<') break;
                else steps++;
            }
            if (steps == n) {
                full = true;
            }
            int steps2 = 0;
            for (int i = n - 1; i >= 0; i--) {
                if (s[i] == '>') break;
                else steps2++;
            }
            if (steps2 == n) {
                full = true;
            }
        }
        if (full) {
            res = n; break;
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}