#include <bits/stdc++.h>

using namespace std;

void solve() {
    string numbers;
    cin >> numbers;
    int n = numbers.size();
    vector<int> ones;
    int aux = 0;
    for (int i = 0; i < n; i++) {
        if (numbers[i] == '1') {
            aux++;
        } else {
            if (aux > 0)
                ones.push_back(aux);
            aux = 0;
        }
    }
    if (aux > 0)
        ones.push_back(aux);
    sort(ones.rbegin(), ones.rend());
    int res = 0;
    for (int i = 0; i < ones.size(); i += 2) {
        res += ones[i];
    }
    cout << res << '\n';
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}