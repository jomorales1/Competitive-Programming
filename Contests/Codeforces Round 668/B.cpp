#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0; cin >> n;
    long long cur = 0;
    long long element;
    for (int i = 0; i < n; i++) {
        cin >> element;
        cur = max(0LL, cur + element);
    }
    cout << cur << '\n';
}

int main() {
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}