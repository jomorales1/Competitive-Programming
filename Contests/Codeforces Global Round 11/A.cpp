#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0; cin >> n;
    vector<int> a(n);
    int sum_pos = 0, sum_neg = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] >= 0) sum_pos += a[i];
        else sum_neg += a[i];
    }
    if (sum_pos > abs(sum_neg))
        sort(a.rbegin(), a.rend());
    else
        sort(a.begin(), a.end());
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum == 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}