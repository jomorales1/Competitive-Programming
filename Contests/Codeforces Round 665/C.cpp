#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b > a)
        swap(a, b);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void solve() {
    int n = 0;
    cin >> n;
    vector<int> numbers(n);
    int m = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        m = min(m, numbers[i]);
    }
    for (int i = 0; i < n; i++) {
        if (numbers[i] > numbers[i + 1 % n]) {
            bool found = false;
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if (gcd(numbers[i], numbers[j]) == m) {
                        found = true;
                        break;
                    }
                }
            }
            if (!found) {
                cout << "NO\n";
                return;
            }
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