#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0; cin >> n;
    if (n < 3 || n == 4) {
        cout << -1 << '\n';
        return;
    }
    if (n % 3 == 0) {
        cout << n / 3 << " 0 0\n";
    } else if (n % 5 == 0) {
        cout << "0 " << n / 5 << " 0\n";
    } else if (n % 7 == 0) {
        cout << "0 0 " << n / 7 << '\n';
    } else {
        for (int i = 0; i < 334; i++) {
            for (int j = 0; j < 201; j++) {
                for (int k = 0; k < 143; k++) {
                    if (i * 3 + j * 5 + k * 7 == n) {
                        cout << i << ' ' << j << ' ' << k << '\n';
                        return;
                    }
                }
            }
        }
        cout << -1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}