#include <bits/stdc++.h>

using namespace std;

int digits(int n) {
    if (n == 0)
        return 1;
    int res = 0;
    while (n > 0) {
        res++;
        n /= 10;
    }
    return res;
}

vector<int> binary(int n) {
    vector<int> res;
    while (n > 0) {
        res.push_back(n % 2);
        n /= 2;
    }
    return res;
}

void solve() {
    int n, t;
    cin >> n;
    if (n == 1) {
        cout << 8 << "\n";
        return;
    }
    t = n * 4;
    vector<int> res;
    while (t > n) {
        res.push_back(9);
        t -= 4;
    }
    if (n - t >= 1) {
        res.pop_back();
        res.push_back(8);
    }
    while (t > 0) {
        res.push_back(8);
        t -= 4;
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}