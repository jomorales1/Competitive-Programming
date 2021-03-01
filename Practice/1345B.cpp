#include <bits/stdc++.h>

using namespace std;

const long long N = 1e9;
vector<long long> p;

void solve() {
    long long n; cin >> n;
    int res = 0;
    while (n > 1) {
        int index = lower_bound(p.begin(), p.end(), n) - p.begin();
        if (p[index] != n) {
            index--;
        }
        if (index < 0) break;
        n -= p[index];
        res++;
    }
    cout << res << '\n';
}

int main() {
    p.push_back(2LL);
    p.push_back(7LL);
    int index = 2;
    long long next = 2LL * p[index - 1] - p[index - 2] + 3;
    while (next <= N) {
        p.push_back(next);
        index++;
        next = 2LL * p[index - 1] - p[index - 2] + 3;
    }
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}