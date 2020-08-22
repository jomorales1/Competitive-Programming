#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0;
    cin >> n;
    vector<int> numbers(n);
    vector<int> numbers2(n);
    int m = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        m = min(m, numbers[i]);
        numbers2[i] = numbers[i];
    }
    sort(numbers2.begin(), numbers2.end());
    for (int i = 0; i < n; i++) {
        if (numbers[i] != numbers2[i] && numbers[i] % m != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; ++i)
        solve();
    return 0;
}