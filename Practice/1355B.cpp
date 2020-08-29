#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0;
    cin >> n;
    vector<int> explorers(n);
    for (int i = 0; i < n; i++) {
        cin >> explorers[i];
    }
    sort(explorers.begin(), explorers.end());
    int groups = 0;
    int current = 0;
    for (int i = 0; i < n; i++) {
        current++;
        if (explorers[i] <= current) {
            groups++; current = 0;
        }
    }
    cout << groups << '\n';
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}