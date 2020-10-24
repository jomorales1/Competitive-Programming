#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        a[i][i] = 1;
    }
    for (int i = 0; i < n; i++) {
        a[n - (i + 1)][i] = 1;
    }
    if (n % 2 != 0) {
        a[0][n / 2] = 1;
        a[n / 2][0] = 1;
        a[n / 2][n - 1] = 1;
        a[n - 1][n / 2] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
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