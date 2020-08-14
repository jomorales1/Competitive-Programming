#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    int a = 0;
    int b = 1;
    int c = 2;
    for (int i = 3; i < n; i++) {
        if (numbers[a] + numbers[b] <= numbers[i])
            c = i;
    }
    if (numbers[a] + numbers[b] <= numbers[c])
        cout << (a + 1) << " " << (b + 1) << " " << (c + 1) << '\n';
    else
        cout << -1 << '\n';
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}