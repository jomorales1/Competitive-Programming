#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> piles(n);
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }
    sort(piles.begin(), piles.end());
    int minimum = piles.front();
    if (minimum == k) {
        cout << 0 << '\n';
        return;
    }
    long long moves = 0;
    for (int i = 1; i < n; i++) {
        if (piles[i] < k) {
            int can = k - piles[i];
            moves += can / minimum;
        } else {
            break;
        }
    }
    cout << moves << '\n';
}

int main() {
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}