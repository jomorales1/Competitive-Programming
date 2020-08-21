#include <bits/stdc++.h>

using namespace std;

int query(const vector<int> sums, int left, int right) {
    if (left == 0)
        return sums[right];
    return sums[right] - sums[left - 1];
}

void solve() {
    int n = 0;
    string arr;
    cin >> n;
    cin >> arr;
    vector<int> sums(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i] - '0';
        sums[i] = sum;
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        for (int l = 0; l < i; l++) {
            if (query(sums, l, i) == (i - l + 1)) {
                res++;
                // cout << i << " " << l << " " << (l + i - 1) << '\n'; 
            }
        }
    }
    cout << res << '\n';
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}