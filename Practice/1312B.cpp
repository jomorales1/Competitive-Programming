#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0; cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    sort(numbers.rbegin(), numbers.rend());
    for (int i = 0; i < n; i++) {
        cout << numbers[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}