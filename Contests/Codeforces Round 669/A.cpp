#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

void solve() {
    int n = 0; cin >> n;
    int cnt_zeros = 0, cnt_ones = 0;
    int element;
    for (int i = 0; i < n; i++) {
        cin >> element;
        if (element == 0) cnt_zeros++;
        if (element == 1) cnt_ones++;
    }
    if (cnt_zeros >= n / 2) {
        cout << n / 2 << '\n';
        for (int i = 0; i < n / 2; i++) {
            cout << 0 << ' ';
        }
        cout << '\n';
    } else {
        int len = (n / 2);
        if (len % 2 != 0)
            len++;
        cout << len << '\n';
        for (int i = 0; i < len; i++) {
            cout << 1 << ' ';
        }
        cout << '\n';
    }
}

int main() {
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}