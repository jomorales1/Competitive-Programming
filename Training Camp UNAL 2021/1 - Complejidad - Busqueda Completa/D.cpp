#include <bits/stdc++.h>

using namespace std;

void solve() {
    string a, b;
    cin >> a >> b;
    map<char, int> occ;
    for (int i = 0; i < b.length(); i++) {
        occ[b[i]]++;
    }
    int res = 0;
    for (int i = 0; i < a.length(); i++) {
        if (occ.count(a[i])) {
            if (occ[a[i]] > 0) {
                occ[a[i]]--; res++;
            } else break;
        } else {
            break;
        }
    }
    cout << res << '\n';
}

int main() {
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}