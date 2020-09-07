#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s; cin >> s;
    for (int i = 0; i < n - k + 1; i++) {
        int replace = 0;
        int ones = 0;
        int zeros = 0;
        for (int j = i; j < i + k; j++) {
            if (s[j] == '?') replace++;
            if (s[j] == '1') ones++;
            if (s[j] == '0') zeros++;
        }
        if (replace == 0 && (ones != zeros)) {
            cout << "NO\n";
            return;
        }
        if ((ones > k / 2) || (zeros > k / 2)) {
            cout << "NO\n";
            return;
        }
        int need_ones = (k / 2) - ones;
        int need_zeros = (k / 2) - zeros;
        for (int index = i; index < i + k; index++) {
            if (s[index] == '?') {
                // if (need_zeros > 0) {
                //     need_zeros--;
                //     s[index] = '0';
                // } else {
                //     need_ones--;
                //     s[index] = '1';
                // }
                if (index % 2 == 0 && need_ones > 0) {
                    need_ones--;
                    s[index] = '1';
                } else {
                    need_zeros--;
                    s[index] = '0';
                }
            }
        }
    }
    cout << "YES\n";
}

int main() {
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}