#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    int distance = abs(b - a);
    int res = distance / 10;
    if (distance % 10 != 0) {
        res++;
    }
    cout << res << '\n';
}

int main() {
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}