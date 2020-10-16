#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e6 + 1;
int sieve[N + 1];
int dp[N + 1];

void solve() {
    int n = 0; cin >> n;
    cout << 1 + dp[n] - dp[int(sqrt(n))] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(sieve, 0, sizeof sieve);
    for (int i = 2; i <= N; i++) {
        if (sieve[i]) continue;
        for (int j = i * 2; j <= N; j += i) {
            sieve[j] = 1;
        }
    }
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= N; i++) {
        dp[i] = dp[i - 1] + (sieve[i] == 0 ? 1 : 0);
    }
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}