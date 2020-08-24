#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0;
    cin >> n;
    unordered_map<int, int> frequencies;
    int student;
    for (int i = 0; i < n; i++) {
        cin >> student;
        frequencies[student]++;
    }
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    if (n <= 3) {
        cout << 1 << '\n';
        return;
    }
    int m = INT_MIN;
    for (const auto &student : frequencies) {
        m = max(m, student.second);
    }
    n = frequencies.size() - 1;
    if (n >= m) {
        cout << m << '\n';
    } else {
        cout << min(m - 1, n + 1) << '\n';
    }
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}