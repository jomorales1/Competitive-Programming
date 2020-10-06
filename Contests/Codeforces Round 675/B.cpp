#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    ll a[n][m];
    ll sum1 = 0, sum2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if ((i == 0 && j == 0) || (i == 0 && j == m - 1) || (i == n - 1 && j == 0) || (i == n - 1 && j == m - 1)) {
                sum1 += a[i][j];
            } else {
                sum2 += a[i][j];
            }
        }
    }
    bool ok = true;
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            if (a[i][j] != a[i][m - j - 1]) {
                ok = false;
                break;
            }
            if (a[i][j] != a[n - i - 1][j]) {
                ok = false;
                break;
            }
        }
    }
    if (ok) {
        cout << 0 << '\n';
        return;
    }
    ll corners = (ll) ceil(sum1 / 4.0);
    ll others = (ll) ceil(sum2 / (double) (n * m - 4));
    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i == 0 && j == 0) || (i == 0 && j == m - 1) || (i == n - 1 && j == 0) || (i == n - 1 && j == m - 1)) {
                res += abs(a[i][j] - corners);
            } else {
                res += abs(a[i][j] - others);
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