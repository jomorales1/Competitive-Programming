#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<long long> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    if (n == 1) {
        for (int i = 0; i < 3; i++) {
            cout << 1 << ' ' << 1 << '\n';
            if (i == 2) {
                cout << -numbers[0] << '\n';
            } else {
                cout << 0 << '\n';
            }
        }
        return 0;
    }
    cout << 1 << ' ' << (n - 1) << '\n';
    for (int i = 0; i < n - 1; i++) {
        cout << numbers[i] * (n - 1) << ' ';
    }
    cout << '\n';
    cout << 1 << ' ' << n << '\n';
    for (int i = 0; i < n; i++) {
        cout << -numbers[i] * n << ' ';
    }
    cout << '\n';
    cout << n << ' ' << n << '\n';
    cout << numbers[n - 1] * (n - 1) << '\n';
    return 0;
}