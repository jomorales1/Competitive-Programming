#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());
    int chosen = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (abs(numbers[i] - numbers[j]) <= 1) {
                numbers[i] = -1;
                chosen++;
                break;
            }
        }
    }
    cout << ((n - chosen) == 1 ? "YES" : "NO") << "\n";
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}