#include <bits/stdc++.h>

using namespace std;

int best(vector<int> &options, int a) {
    for (auto x : options) {
        if (x < a)
            return x;
        if (x > a)
            return x;
    }
    return options[0];
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
        c[i] = a[i] & best(b, a[i]);
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        res |= c[i];
    }
    cout << res << "\n";
}

int main() {
    solve();
    return 0;
}