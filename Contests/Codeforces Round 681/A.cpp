#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0; cin >> n;
    int needed = n;
    for (int i = 4 * n; i >= 1; i -= 2) {
        cout << i << ' ';
        needed--;
        if (needed == 0) break;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0); cout.tie(0);
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}