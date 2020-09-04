#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> numbers;
    numbers.push_back(x);
    numbers.push_back(y);
    int elements = 2;
    int distance = -1;
    for (int i = n - 1; i >= 2; i--) {
        if ((y - x) % i == 0) {
            distance = (y - x) / i;
            break;
        }
    }
    if (distance == -1)
        distance = (y - x);
    int e = x + distance;
    while (e != y && elements < n) {
        numbers.push_back(e);
        elements++;
        e += distance;
    }
    e = x - distance;
    while (e > 0 && elements < n) {
        numbers.push_back(e);
        elements++;
        e -= distance;
    }
    e = y + distance;
    while (elements < n) {
        numbers.push_back(e);
        elements++;
        e += distance;
    }
    for (int number : numbers) {
        cout << number << ' ';
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