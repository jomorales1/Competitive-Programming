#include <bits/stdc++.h>

using namespace std;

void solve2() {
    int l, r;
    cin >> l >> r;
    long long m;
    cin >> m;
}

void solve() {
    int l, r;
    long long m;
    cin >> l >> r >> m;
    int b, c;
    for (int a = l; a <= r; a++) {
        for (int n = 1; n <= (int) 2 * 1e5; n++) {
            int x = m - n * a;
            if (x >= (l - r) && x <= (r - l)) {
                bool flag = false;
                for (int j = l; j <= r; j++) {
                    for (int k = l; k <= r; k++) {
                        if (j - k == x) {
                            b = j; c = k;
                            break;
                        }
                    }
                    if (flag)
                        break;
                }
                cout << a << " " << b << " " << c << "\n";
                return;
            }
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}