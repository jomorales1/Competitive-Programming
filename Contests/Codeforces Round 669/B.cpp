#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0; cin >> n;
    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }
    sort(sequence.rbegin(), sequence.rend());
    int m = INT_MIN;
    int gcd = sequence[0];
    for (int i = 1; i < n - 1; i++) {
        int option = __gcd(gcd, sequence[i]);
        int index = i;
        for (int j = i + 1; j < n; j++) {
            int option2 = __gcd(gcd, sequence[j]);
            if (option2 > option) {
                index = j;
                option = option2;
            }
        }
        gcd = option;
        swap(sequence[i], sequence[index]);
    }
    for (int i = 0; i < n; i++) {
        cout << sequence[i] << ' ';
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