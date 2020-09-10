#include <bits/stdc++.h>

using namespace std;

void solve() {
    string x, y;
    cin >> x >> y;
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());
    int pos_one = 0;
    for (int i = 0; i < y.length(); i++) {
        if (y[i] == '0')
            pos_one++;
        else
            break;
    }
    int distance = 0;
    for (int i = pos_one; i < x.length(); i++) {
        if (x[i] == '1') {
            distance = i;
            break;
        }
    }
    cout << (distance - pos_one) << '\n';
}

int main() {
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}