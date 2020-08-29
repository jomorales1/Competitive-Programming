#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    set<int> elements;
    int element;
    for (int i = 0; i < n; i++) {
        cin >> element;
        elements.insert(element);
    }
    if (elements.size() > k) {
        cout << -1 << '\n';
        return;
    }
    vector<int> result;
    cout << n * k << '\n';
    for (int i = 0; i < n; i++) {
        for (int el : elements) {
            cout << el << ' ';
        }
        for (int j = 0; j < k - elements.size(); j++) {
            cout << 1 << ' ';
        }
    }
    cout << '\n';
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}