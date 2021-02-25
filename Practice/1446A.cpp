#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, long long> &a, pair<int, long long> &b) {
    return a.second > b.second;
}

void solve() {
    int n = 0; cin >> n;
    long long W = 0LL; cin >> W;
    vector<pair<int, long long>> items(n);
    long long element;
    for (int i = 0; i < n; i++) {
        cin >> element;
        items[i] = {i + 1, element};
    }
    sort(items.begin(), items.end(), compare);
    long long lower = (W / 2) + (W % 2);
    vector<int> result;
    long long acc = 0LL;
    for (auto item : items) {
        long long possible = acc + item.second;
        if (possible <= W) {
            acc = possible;
            result.push_back(item.first);
        }
    }
    if (acc >= lower && acc <= W) {
        cout << (int) result.size() << '\n';
        for (auto res : result) {
            cout << res << ' ';
        }
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}