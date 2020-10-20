#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0; cin >> n;
    int index_max = -1, maximum = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] >= maximum) {
            index_max = i;
            maximum = a[i];
        }
    }
    int can = 0;
    if (index_max == 0) {
        if (a[1] < maximum) can++;
    } else if (index_max == n - 1) {
        if (a[n - 2] < maximum) can++;
    } else {
        if (a[index_max - 1] < maximum) can++;
        if (a[index_max + 1] < maximum) can++;
    }
    for (int i = 0; i < n; i++) {
        if (i == 0 && a[i] == maximum && i != index_max) {
            int can2 = (a[i + 1] < a[i] ? 1 : 0);
            if (can2 > can) {
                index_max = i;
                can = can2;
            }
        } else if (i == n - 1 && a[i] == maximum && i != index_max) {
            int can2 = (a[i - 1] < a[i] ? 1 : 0);
            if (can2 > can) {
                index_max = i;
                can = can2;
            }
        } else if (a[i] == maximum && i != index_max) {
            int can2 = 0;
            if (a[i - 1] < a[i]) can2++;
            if (a[i + 1] < a[i]) can2++;
            if (can2 > can) {
                index_max = i;
                can = can2;
            }
        }
    }
    if (can > 0) {
        cout << index_max + 1 << '\n';
    } else {
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