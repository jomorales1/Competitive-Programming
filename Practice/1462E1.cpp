#include <bits/stdc++.h>

using namespace std;

long long c(long long n, long long k) {
    if (n < k) return 0;
    double res = 1;
    for (int i = 1; i <= k; i++)
        res = res * (n - k + i) / i;
    return (long long)(res + 0.01);
}

void solve() {
    int n = 0; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long res = 0LL;
    int index = 0;
    while (index < n - 2) {
        int pos = lower_bound(a.begin(), a.end(), a[index] + 2) - a.begin();
        if (a[pos] == a[index] + 2) {
            while(pos + 1 < n) {
                if (a[pos + 1] == a[index] + 2) pos++;
                else break;
            }
        } else {
            pos--;
        }
        long long v = (long long) pos - index + 1LL;
        res += (long long) c(v, 3LL);
        index = lower_bound(a.begin(), a.end(), a[index] + 1) - a.begin();
        long long v2 = (long long) pos - index + 1LL;
        res -= (long long) c(v2, 3LL);
    }
    cout << res << '\n';
}

int main() {
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}