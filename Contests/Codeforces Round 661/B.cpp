#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, a, b;
    cin >> n;
    vector<int> candies(n); // a
    vector<int> oranges(n); // b
    long long res = 0;
    int min_a = INT_MAX;
    int min_b = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> candies[i];
        min_a = min(candies[i], min_a);
    }
    for (int i = 0; i < n; i++) {
        cin >> oranges[i];
        min_b = min(oranges[i], min_b);
    }
    for (int i = 0; i < n; i++) {
        candies[i] -= min_a;
        oranges[i] -= min_b;
        res += max(candies[i], oranges[i]);
    }
    cout << res << "\n";
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}