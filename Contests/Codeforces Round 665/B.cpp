#include <bits/stdc++.h>

using namespace std;

void solve() {
    int x1, y1, z1;
    cin >> x1 >> y1 >> z1;
    int x2, y2, z2;
    cin >> x2 >> y2 >> z2;
    long long res = 0;
    res += min(z1, y2) * 2;
    z1 -= min(z1, y2);
    if (z2 > (x1 + z1))
        res -= min(z2 - x1 - z1, y1) * 2;
    cout << res << '\n';
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; ++i)
        solve();
    return 0;
}