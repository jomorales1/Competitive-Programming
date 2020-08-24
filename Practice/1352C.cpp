#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    long long left = 1;
    long long right = k * 2;
    long long mid;
    while (left <= right) {
        cout << "Left: " << left << "\n";
        cout << "Right: " << right << "\n";
        mid = left + (right - left) / 2;
        cout << "Mid: " << mid << "\n";
        double res = (double) mid / n * (n - 1);
        if (mid % n != 0 && (long long) ceil(res) == k) {
            cout << mid << '\n';
            return;
        }
        if (mid % n == 0)
            left = mid + 1;
        if ((long long) ceil(res) < k) {
            left = mid + 1;
        }
        if ((long long) ceil(res) > k) {
            right = mid - 1;
        }
    }
    cout << mid << '\n';
}

void solve2() {
    int n, k;
    cin >> n >> k;
    long long res = k + (k - 1) / (n - 1);
    cout << res << '\n';
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve2();
    }
    return 0;
}