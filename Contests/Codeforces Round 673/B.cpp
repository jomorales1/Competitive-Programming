#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, T;
    cin >> n >> T;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> group;
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        if (a[i] != abs(T - a[i])) {
            if (group[a[i]] == 0) {
                group[(abs(T - a[i]))] = 1;
            } else {
                group[(abs(T - a[i]))] = 0;
            }
            res[i] = group[a[i]];
        } else {
            res[i] = group[a[i]];
            group[a[i]] = (group[a[i]] == 0 ? 1 : 0);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}