#include <bits/stdc++.h>

using namespace std;

const int MOD = (int) 1e9 + 7;

void solve() {
    int x, n, pos;
    cin >> n >> x >> pos;
    long long res = 1LL;
    for (long long i = 2; i < n; i++) {
        res = (res * i) % MOD;
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    solve();
    return 0;
}