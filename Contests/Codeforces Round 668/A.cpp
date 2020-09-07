#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0; cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    reverse(p.begin(), p.end());
    for (int i = 0; i < n; i++) {
        cout << p[i] << ' ';
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