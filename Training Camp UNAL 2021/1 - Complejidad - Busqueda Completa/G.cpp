#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int x, y;
    for (int i = 0; i < 2 * k; i++) {
        cin >> x >> y;
    }
    int res = n * m + n + m - 3;
    cout << res << '\n';
    for (int i = 0; i < m - 1; i++) cout << "L";
    for (int i = 0; i < n - 1; i++) cout << "U";
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int i = 0; i < m - 1; i++) cout << "R";
        } else {
            for (int i = 0; i < m - 1; i++) cout << "L";
        }
        if (i != n - 1) cout << "D";
    }
    cout << '\n';
    return 0;
}