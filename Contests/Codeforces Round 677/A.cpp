#include <bits/stdc++.h>

using namespace std;

int digits(int a) {
    int res = 0;
    while (a > 0) {
        a = a / 10;
        res += 1;
    }
    return res;
}

void solve() {
    int x = 0; cin >> x;
    int last = x % 10;
    int d = digits(x);
    int res = (last - 1) * 10 + (d * (d + 1)) / 2;
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