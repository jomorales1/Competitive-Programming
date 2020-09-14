#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long x, y, k;
    cin >> x >> y >> k;
    long long res = (long long) ceil((k + (y * k) - 1) / (long double) (x - 1)) + k;
    cout << res << '\n';
}

int main() {
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}