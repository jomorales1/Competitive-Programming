#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        int m = INT_MAX;
        for (int j = 0; j <= m; j++) {
            m = min(m, a[i] & b[j]);
        }
        c[i] = a[i] & b[0];
    }
    int res = c[0];
    for (int i = 1; i < n; i++) {
        res |= c[i];
    }
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}