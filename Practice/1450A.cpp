#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0; cin >> n;
    string a; cin >> a;
    sort(a.begin(), a.end());
    cout << a << '\n';
}

int main() {
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}