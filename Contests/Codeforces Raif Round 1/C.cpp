#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s; cin >> s;
    int n = (int) s.length();
    int res = n;
    if (n == 0) {
        cout << 0 << '\n';
    } else if (n == 1) {
        cout << 1 << '\n';
        return;
    } else if (n == 2) {
        if ((s[0] == 'A' && s[1] == 'B') || (s[0] == 'B' && s[1] == 'B')) {
            cout << 0 << '\n';
        } else {
            cout << 2 << '\n';
        }
        return;
    } else if (n == 3) {
        bool ok = false;
        for (int i = 0; i < n - 1; i++) {
            if ((s[i] == 'A' && s[i + 1] == 'B') || (s[i] == 'B' && s[i + 1] == 'B')) {
                ok = true; break;
            }
        }
        if (ok) {
            cout << 1 << '\n';
        } else {
            cout << 3 << '\n';
        }
        return;
    }
    int prev = -1;
    vector<bool> used(n, false);
    while (res != prev) {
        prev = res;
        for (int i = 1; i < n - 1; i++) {
            bool find = false;
            if (used[i]) continue;
            int index = i + 1;
            while (used[index] && index < n - 1) index++;
            if ((s[i] == 'A' && s[index] == 'B') || (s[i] == 'B' && s[index] == 'B') && !used[index]) {
                res -= 2;
                used[i] = true; used[index] = true;
                break;
            }
        }
    }
    for (int i = 0; i < n - 1; i++) {
        if (used[i]) continue;
        int index = i + 1;
        while (used[index] && index < n - 1) index++;
        if (!used[index]) {
            if ((s[i] == 'A' && s[index] == 'B') || (s[i] == 'B' && s[index] == 'B')) {
                res -= 2;
                used[i] = true; used[index] = true;
            }
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