#include <bits/stdc++.h>

using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    string s; cin >> s;
    int n = (int) s.length();
    vector<pair<int, int>> zeros;
    int first = 0;
    while (s[first] == '0') {
        first++;
    }
    int second = n - 1;
    while (s[second] == '0') {
        second--;
    }
    int segments = 0;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            if (index == -1) {
                index = i;
            }
        } else {
            if (index != -1) {
                index = -1;
                segments++;
            }
        }
    }
    if (index != -1) {
        segments++;
    }
    int count = 0;
    bool prev = false;
    long long cost = 0LL;
    for (int i = first; i <= second; i++) {
        if (s[i] == '0') {
            count++;
        } else {
            if (count > 0 && (b * count + a) <= 2 * a) {
                segments--;
                cost += b * count;
                count = 0;
            }
        }
    }
    cost += (long long) segments * a;
    cout << cost << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0); cout.tie(0);
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}