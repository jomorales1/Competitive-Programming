#include <bits/stdc++.h>

using namespace std;

vector<int> factors(int n) {
    vector<int> res;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }
    if (n > 1)
        res.push_back(n);
    return res;
}

void solve() {
    int n; cin >> n;
    int turn = 0;
    while (n >= 1) {
        if (turn % 2 == 0) {
            if (n == 1) {
                cout << "FastestFinger\n";
                return;
            }
            if (n % 2 == 1) {
                n--;
            } else {
                vector<int> f = factors(n);
                bool find = false;
                for (int i = 0; i < f.size(); i++) {
                    if (n / f[i] % 2 == 1) {
                        n /= f[i];
                        find = true;
                        break;
                    }
                }
                if (!find) {
                    cout << "FastestFinger\n";
                    return;
                }
            }
        } else {
            if (n == 1) {
                cout << "Ashishgup\n";
                return;
            }
            if (n % 2 == 0) {
                n--;
            } else {
                vector<int> f = factors(n);
                bool find = false;
                for (int i = 0; i < f.size(); i++) {
                    if (n / f[i] % 2 == 0) {
                        n /= f[i];
                        find = true;
                        break;
                    }
                }
                if (!find) {
                    cout << "Ashishgup\n";
                    return;
                }
            }
        }
        turn++;
    }
}

int main() {
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}