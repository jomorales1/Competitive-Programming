#include <bits/stdc++.h>

using namespace std;

void solve() {
    int l = 0, r = 0;
    long long m = 0;
    cin >> l >> r >> m;
    bool aux = false;
    for (int a = l; a <= r; a++) {
        long long n = (m / a);
        if (n == 0)
            n = 1;
        else if (m - n * a >= (l - r - 1))
            n++;
        if (m - n * a >= (l - r) && m - n * a <= (r - l)) {
            for (int b = l; b <= r; b++) {
                int c = m - (n * a) - b;
                if (abs(c) >= l && abs(c) <= r) {
                    cout << a << " " << b << " " << abs(c) << '\n';
                    aux = true;
                    break;
                }
            }
        }
        if (aux)
            break;
    }
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}