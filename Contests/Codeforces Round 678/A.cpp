#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0;
    long long m;
    cin >> n >> m;
    vector<int> a(n);
    long long sum = 0LL;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if (sum == m) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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