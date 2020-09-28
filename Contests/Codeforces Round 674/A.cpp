#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    if (n == 1 || n == 2) {
        cout << 1 << '\n';
        return;
    }
    n -= 2;
    int floor = 1 + (int) ceil((double) n / x);
    cout << floor << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}