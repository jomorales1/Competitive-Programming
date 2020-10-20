#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int f_one = -1;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            f_one = i; break;
        }
    }
    int l_one = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 1) {
            l_one = i; break;
        }
    }
    int res = 0;
    for (int i = f_one; i <= l_one; i++) {
        if (a[i] == 0)
            res++;
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}