#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, m, sx, sy;
    cin >> n >> m >> sx >> sy;
    cout << sx << " " << sy << "\n";
    int c = sy;
    for (int i = 1; i <= m; i++) {
        if (i != sy) {
            cout << sx << " " << i << "\n";
            c = i;
        }
    }
    int r = sx + 1;
    while (r != sx) {
        cout << r << " " << c << "\n";
        int last;
        for (int i = 1; i <= m; i++) {
            if (i != c) {
                cout << r << " " << i << "\n";
                last = i;
            }
        }
        c = last;
        r++;
        if (r > n)
            r = 1;
    }
}

int main() {
    solve();
    return 0;
}