#include <bits/stdc++.h>

using namespace std;

int shared_ones(int a, int b) {
    string bina = "";
    string binb = "";
    while (a > 0) {
        bina += to_string(a % 2);
        a /= 2;
    }
    while (b > 0) {
        binb += to_string(b % 2);
        b /= 2;
    }
    int m = min(bina.size(), binb.size());
    int res = 0;
    for (int i = 0; i < m; i++) {
        if (bina[i] == binb[i])
            res++;
    }
    return res;
}

int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    vector<int> chosen(n);
    for (int i = 0; i < n; i++) {
        int mi = INT_MAX;
        for (int j = 0; j < m; j++) {
            mi = min(mi, a[i] & b[j]);
        }
        chosen[i] = mi;
    }
    int res = chosen[0];
    for (int i = 1; i < n; i++)
        res |= chosen[i];
    cout << res << '\n';
    return 0;
}