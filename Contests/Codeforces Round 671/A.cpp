#include <bits/stdc++.h>

using namespace std;

void solve() {
    int digits; cin >> digits;
    string n;
    cin >> n;
    if (digits % 2 != 0) {
        for (int i = 0; i < digits; i += 2) {
            if ((int) (n[i] - '0') % 2 != 0) {
                cout << 1 << '\n';
                return;
            }
        }
        cout << 2 << '\n';
    } else {
        for (int i = 1; i < (int) digits; i += 2) {
            if ((int) (n[i] - '0') % 2 == 0) {
                cout << 2 << '\n';
                return;
            }
        }
        cout << 1 << '\n';
    }
}

int main() {
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}