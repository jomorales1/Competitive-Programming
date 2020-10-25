#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0); cout.tie(0);
    int n = 0; cin >> n;
    bool ok = true;
    int element;
    for (int i = 0; i < n; i++) {
        cin >> element;
        if (element == 1) ok = false;
    }
    cout << (ok ? "EASY" : "HARD") << '\n';
    return 0;
}