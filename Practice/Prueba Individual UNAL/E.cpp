#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    int even = 0;
    int odd = 0;
    int change = 0;
    for (int i = 0; i < n; i++) {
        if (numbers[i] % 2 == 0)
            even++;
        else
            odd++;
        if ((i % 2 == 0 && numbers[i] % 2 != 0) || (i % 2 != 0 && numbers[i] % 2 == 0))
            change++;
    }
    if (n % 2 == 0) {
        if (even == odd)
            cout << (change / 2) << '\n';
        else
            cout << -1 << '\n';
    } else {
        if (even == odd + 1)
            cout << (change / 2) << '\n';
        else
            cout << -1 << '\n';
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