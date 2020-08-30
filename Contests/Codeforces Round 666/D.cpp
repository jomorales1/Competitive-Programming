#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> piles(n);
    vector<int> non_empty;
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
        if (piles[i] > 0)
            non_empty.push_back(piles[i]);
    }
    sort(non_empty.rbegin(), non_empty.rend());
    int t = 0;
    for (int i = 0; i < non_empty.size(); i += 2) {
        t += non_empty[i];
    }
    int hl = 0;
    for (int i = 1; i < non_empty.size(); i += 2) {
        hl += non_empty[i];
    }
    if (t > hl) {
        cout << "T\n";
    } else {
        cout << "HL\n";
    }
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}