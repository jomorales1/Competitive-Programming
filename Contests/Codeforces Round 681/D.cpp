#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool decreasing = true;
    for (int i = 0; i < n - 1; i++) {
        if (!(a[i] >= a[i + 1])) {
            decreasing = false;
            break;
        }
    }
    if (decreasing) {
        cout << "YES\n";
        return;
    }
    bool increasing = true;
    for (int i = 0; i < n - 1; i++) {
        if (!(a[i] <= a[i + 1])) {
            increasing = false;
            break;
        }
    }
    if (increasing) {
        cout << "YES\n";
        return;
    }
    bool inc = false;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] >= a[i + 1]) {
            if (inc) {
                cout << "NO\n";
                return;
            }
        } else {
            inc = true;
        }
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0); cout.tie(0);
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}