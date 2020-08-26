#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
    if (a.second == b.second)
        return a.first > b.first;
    return a.second > b.second;
}

void solve() {
    int n = 0;
    cin >> n;
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    if (n <= 3) {
        cout << 1 << '\n';
        return;
    }
    vector<pair<int, int>> participants(51);
    int p;
    for (int i = 0; i < n; i++) {
        cin >> p;
        participants[p].first = p;
        participants[p].second++;
    }
    sort(participants.begin(), participants.end(), compare);
    int res = 0;
    int value = participants[0].first + participants[n - 1].first;
    res += min(participants[0].second, participants[n - 1].second);
    for (int i = 1; i < n / 2; i++) {
        if (participants[i].first + participants[n - i - 1].first == value)
            res += min(participants[i].second, participants[n - i - 1].second);
    }
    cout << res << '\n';
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; ++i)
        solve();
    return 0;
}