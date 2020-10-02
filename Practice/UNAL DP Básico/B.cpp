#include <bits/stdc++.h>

using namespace std;

int main() {
    string s; cin >> s;
    int n = (int) s.length();
    vector<pair<int, int>> dp(n);
    int res = 0;
    if (s[0] == 'Q') {
        dp[0].first++;
    }
    for (int i = 1; i < n; i++) {
        if (s[i] == 'Q') {
            if (dp[i - 1].first > 0) {
                res += dp[i - 1].second;
            }
            dp[i] = {dp[i - 1].first + 1, dp[i - 1].second};
        } else if (s[i] == 'A') {
            dp[i] = {dp[i - 1].first, dp[i - 1].second + dp[i - 1].first};
        } else {
            dp[i] = dp[i - 1];
        }
    }
    cout << res << '\n';
    return 0;
}