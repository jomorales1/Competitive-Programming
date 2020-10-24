#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 0 << '\n';
    } else if (a < b) {
        if ((b - a) % 2 == 0) {
            cout << 2 << '\n';
        } else {
            cout << 1 << '\n';
        }
    } else {
        if ((a - b) % 2 != 0) {
            cout << 2 << '\n';
        } else {
            cout << 1 << '\n';
        }
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