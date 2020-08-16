#include <bits/stdc++.h>

using namespace std;

const int si = 1e5 + 5;

void solve() {
    int n = 0;
    cin >> n;
    unordered_map<int, int> planks;
    int plank = 0;
    for (int i = 0; i < n; i++) {
        cin >> plank;
        planks[plank]++;
    }
    char option;
    int x;
    int q = 0;
    cin >> q;
    int square = 0, rect = 0;
    for (const auto &p : planks) {
        square += p.second / 4;
        rect += p.second / 2;
    }
    for (int i = 0; i < q; i++) {
        cin >> option;
        cin >> x;
        square -= planks[x] / 4;
        rect -= planks[x] / 2;
        if (option == '+')
            planks[x]++;
        else
            planks[x]--;
        square += planks[x] / 4;
        rect += planks[x] / 2;
        if (square >= 2) {
            cout << "YES\n";
        } else if (square == 1 && (rect - square * 2) >= 2) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

int main() {
    solve();
    return 0;
}