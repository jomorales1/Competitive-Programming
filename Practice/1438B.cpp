#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0; cin >> n;
    map<int, int> b;
    int element;
    bool res = false;
    for (int i = 0; i < n; i++) {
        cin >> element;
        b[element]++;
        if (b[element] > 1)
            res = true;
    }
    cout << (res ? "YES" : "NO") << '\n';
}

int main() {
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}