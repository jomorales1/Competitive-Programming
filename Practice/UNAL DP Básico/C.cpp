#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

int main() {
    int n = 0; cin >> n;
    ll dp[n + 1];
    memset(dp, 0, sizeof dp);
    dp[1] = 1;
    for (int i = 2; i < n + 1; ++i) {
        dp[i] = dp[i - 1] + 4 * (i - 1);
    }
    cout << dp[n] << '\n';
    return 0;
}