#include <bits/stdc++.h>

using namespace std;

void solve() {
    map<int, vector<string>> ranks;
    int v = 0;
    string page;
    for (int i = 0; i < 10; i++) {
        cin >> page; cin >> v;
        ranks[v].push_back(page);
    }
    int maximum = -1;
    for (const auto &rank : ranks) {
        maximum = max(maximum, rank.first);
    }
    for (const auto &page : ranks[maximum]) {
        cout << page << '\n';
    }
}

int main() {
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case #" << (i + 1) << ":\n";
        solve();
    }
    return 0;
}