#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if ((x1 == x2) && (y1 == y2)) {
        cout << 0 << '\n';
    } else if (x1 == x2) {
        cout << abs(y2 - y1) << '\n';
    } else if (y1 == y2) {
        cout << abs(x2 - x1) << '\n';
    } else {
        int res = (abs(x2 - x1) + abs(y2 - y1)) + 2;
        cout << res << '\n';
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