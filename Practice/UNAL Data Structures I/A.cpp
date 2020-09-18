#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long a, b;
    cin >> a >> b;
    if (a > b) {
        cout << ">\n";
    } else if (a < b) {
        cout << "<\n";
    } else {
        cout << "=\n";
    }
}

int main() {
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}