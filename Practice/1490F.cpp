#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0; cin >> n;
    map<int, int> occ;
    for (int i = 0; i < n; i++) {
        int el; cin >> el;
        occ[el]++;
    }
    map<int, int> cnt;
    for (auto el : occ) {
        cnt[el.second]++;
    }
    int res = n;
    int left = 0, right = n, right_c = (int) occ.size();
    for (auto el : cnt) {
        res = min(res, left + right - right_c * el.first);
        left += el.first * el.second;
        right -= el.first * el.second;
        right_c -= el.second;
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