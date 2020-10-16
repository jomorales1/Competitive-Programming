#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0; cin >> n;
    int res = n;
    cout << "2\n";
    for (int i = n - 1; i >= 1; i--) {
        cout << res << ' ' << i << '\n';
        res = (res + i + 1) / 2;
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}