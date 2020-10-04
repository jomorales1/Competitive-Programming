#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    int n = 0; cin >> n;
    string s; cin >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = (int) (s[i] - '0');
    }
    vector<ll> pref_sum(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        pref_sum[i] = sum;
    }
    vector<ll> dp(n);
    map<ll, ll> occ;
    occ[0]++;
    occ[a[0] - 1]++;
    dp[0] = occ[a[0] - 1] - 1;
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i - 1];
        occ[pref_sum[i] - i - 1]++;
        dp[i] += occ[pref_sum[i] - i - 1] - 1;
    }
    cout << dp[n - 1] << '\n';
}

int main() {
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}