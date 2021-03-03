#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<pair<tuple<int, int, int>, int>> dp(n);
    dp[0] = {make_tuple(-1, -1, -1), n};
    if (s[0] == '1') {
        get<0>(dp[0].first) = 0;
    } else if (s[0] == '2') {
        get<1>(dp[0].first) = 0;
    } else {
        get<2>(dp[0].first) = 0;
    }
    for (int i = 1; i < n; i++) {
        if (s[i] == '1') {
            int two = get<1>(dp[i - 1].first);
            int three = get<2>(dp[i - 1].first);
            get<0>(dp[i].first) = i;
            get<1>(dp[i].first) = two;
            get<2>(dp[i].first) = three;
            if (two != -1 && three != -1) {
                int len = min(dp[i - 1].second, i - min(two, three) + 1);
                dp[i].second = len;
            } else {
                dp[i].second = dp[i - 1].second;
            }
        } else if (s[i] == '2') {
            int one = get<0>(dp[i - 1].first);
            int three = get<2>(dp[i - 1].first);
            get<0>(dp[i].first) = one;
            get<1>(dp[i].first) = i;
            get<2>(dp[i].first) = three;
            if (one != -1 && three != -1) {
                int len = min(dp[i - 1].second, i - min(one, three) + 1);
                dp[i].second = len;
            } else {
                dp[i].second = dp[i - 1].second;
            }
        } else {
            int one = get<0>(dp[i].first);
            int two = get<1>(dp[i].first);
            get<0>(dp[i - 1].first) = one;
            get<1>(dp[i - 1].first) = two;
            get<2>(dp[i - 1].first) = i;
            if (one != -1 && two != -1) {
                int len = min(dp[i - 1].second, i - min(one, two) + 1);
                dp[i].second = len;
            } else {
                dp[i].second = dp[i - 1].second;
            }
        }
    }
    bool can = (get<0>(dp[n - 1].first) != -1) && (get<1>(dp[n - 1].first) != -1) && (get<2>(dp[n - 1].first) != -1);
    if (can) cout << dp[n - 1].second << '\n';
    else cout << 0 << '\n';
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
}