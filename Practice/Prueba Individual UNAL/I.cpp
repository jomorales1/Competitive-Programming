#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0;
    cin >> n;
    vector<int> figures(n);
    for (int i = 0; i < n; i++) {
        cin >> figures[i];
    }
    int points = 0;
    int change = 0;
    for (int i = 0; i < n - 1; i++) {
        if ((figures[i] == 2 && figures[i + 1] == 3) || (figures[i] == 3 && figures[i + 1] == 2)) {
            cout << "Infinite\n";
            return;
        }
        if (figures[i] == 2 && figures[i + 1] == 1) {
            points += 3;
        } else if (figures[i] == 1 && figures[i + 1] == 3) {
            points += 4;
        } else if (figures[i] == 1 && figures[i + 1] == 2) {
            points += 3;
        } else if (figures[i] == 3 && figures[i + 1] == 1) {
            points += 4;
            if (i <= n - 3) {
                if (figures[i + 2] == 2) {
                    change ++;
                }
            }
        }
    }
    cout << "Finite\n";
    cout << (points - change) << '\n';
}

int main() {
    solve();
    return 0;
}