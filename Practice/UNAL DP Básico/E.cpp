#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

const int N = (ll) 1e5 + 1;
ll dp[N][2];

ll mod(ll a, ll m) {
    ll c = a % m;
    return (c < 0) ? (c + m) : c;
}

int main() {
    int n = 0; cin >> n;
    vector<int> a(n);
    int min_neg = INT_MIN, min_pos = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (mod((ll) a[i], 2LL) != 0) {
            if (a[i] > 0) {
                min_pos = min(min_pos, a[i]);
            } else {
                min_neg = max(min_neg, a[i]);
            }
        }
    }
    memset(dp, 0, sizeof dp);
    dp[0][0] = 0;
    dp[0][1] = a[0];
    for (int i = 1; i < n; i++) {
        ll best = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][0] = best;
        dp[i][1] = best + a[i];
    }
    ll res = max(dp[n - 1][0], dp[n - 1][1]);
    if (mod(res, 2LL) == 0) {
        if (min_neg != INT_MIN && min_pos != INT_MAX) {
            res -= min(abs(min_neg), min_pos);
        } else if (min_neg != INT_MIN) {
            res += min_neg;
        } else {
            res -= min_pos;
        }
    }
    cout << res << '\n';
    return 0;
}