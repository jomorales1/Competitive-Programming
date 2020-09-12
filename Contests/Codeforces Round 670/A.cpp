#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0; cin >> n;
    vector<int> numbers(101, 0);
    int element;
    for (int i = 0; i < n; i++) {
        cin >> element;
        numbers[element]++;
    }
    int res = 0;
    int chosen = 0;
    for (int i = 0; i <= 100; i++) {
        if (numbers[i] == 0) {
            res += i;
            chosen = i;
            break;
        }
    }
    bool found = false;
    for (int i = 0; i <= 100; i++) {
        if (numbers[i] == 1 && i < chosen) {
            res += i;
            found = true;
            break;
        }
    }
    if (!found)
        res += chosen;
    cout << res << '\n';
}

int main() {
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}