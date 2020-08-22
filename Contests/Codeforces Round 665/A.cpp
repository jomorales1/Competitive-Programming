#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (n < k) {
        cout << (k - n) << '\n';
    } else if (n % 2 == k % 2) {
        cout << 0 << '\n';
    } else {
        cout << 1 << '\n';
    }
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
    return 0;
}