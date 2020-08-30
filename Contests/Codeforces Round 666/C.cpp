#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    long long maximum = LONG_LONG_MIN;
    vector<long long> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        maximum = max(maximum, numbers[i]);
    }
    long long div = maximum / n;
    div = div * n + 1;
    cout << 1 << ' ' << n << '\n';
    for (int i = 0; i < n; i++) {
        cout << abs(numbers[i] - div) << ' ';
    }
    cout << '\n';
    cout << 1 << ' ' << n << '\n';
    for (int i = 0; i < n; i++) {
        cout << div * -1 << ' ';
    }
    cout << '\n';
    cout << 1 << ' ' << n << '\n';
    for (int i = 0; i < n; i++) {
        cout << 0 << ' ';
    }
    cout << '\n';
    return 0;
}