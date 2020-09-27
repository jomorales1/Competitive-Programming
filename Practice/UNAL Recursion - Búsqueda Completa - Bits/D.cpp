#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long x; cin >> x;
    long long accum = 1;
    long long res = 1;
    long long sum = 1;
    while (sum + ((accum * 2 + 1) * (accum * 2 + 2) / 2) <= x) {
        accum = (accum * 2 + 1);
        sum += accum * (accum + 1) / 2;
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