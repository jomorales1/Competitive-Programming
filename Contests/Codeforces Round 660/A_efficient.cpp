#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n < 31) {
        cout << "NO\n";
    } else {
        if (n - 30 == 6 || n - 30 == 10 || n - 30 == 14){
            cout << 6 << " " << 10 << " " << 15 << " " << (n - 31) << "\n"; 
        } else {
            cout << 6 << " " << 10 << " " << 14 << " " << (n - 30) << "\n"; 
        }
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}