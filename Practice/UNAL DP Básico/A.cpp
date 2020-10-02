#include <bits/stdc++.h>

using namespace std;

const int N = (int) 1e5 + 1;
int dp[N];

int main() {
    int n = 0; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    memset(dp, 1, sizeof dp);
    dp[0] = 1;
    int maximum = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        } else {
            dp[i] = 1;
        }
        maximum = max(maximum, dp[i]);
    }
    cout << maximum << '\n';
    return 0;
}