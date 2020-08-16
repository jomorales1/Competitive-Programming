#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<long long> dormitories(n);
    vector<long long> letters(m);
    for (int i = 0; i < n; i++)
        cin >> dormitories[i];
    for (int i = 0; i < m; i++)
        cin >> letters[i];
    vector<long long> all(n + 1, 0);
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += dormitories[i - 1];
        all[i] = sum;
    }
    for (int i = 0; i < m; i++) {
        int l = 1;
        int r = n;
        while (l <= r) {
            int k = (l + r) / 2;
            if (letters[i] > all[k - 1] && letters[i] <= all[k]) {
                cout << k << " " << (letters[i] - all[k - 1]) << '\n';
                break;
            }
            if (letters[i] <= all[k - 1])
                r = k - 1;
            if (all[k] < letters[i])
                l = k + 1;
        }
    }
}

int main() {
    solve();
    return 0;
}