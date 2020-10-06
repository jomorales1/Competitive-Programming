#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

void solve() {
    vector<ll> a(3);
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll first = a[1];
    ll second = a[2] - a[0];
    ll res = (ll) ceil(sqrt(pow((long double) first, 2LL) + pow((long double) second, 2LL)));
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}