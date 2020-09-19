#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int value;
    for (int i = 0; i < m; i++) {
        cin >> value;
        cout << upper_bound(a.begin(), a.end(), value) - a.begin() << ' ';
    }
    cout << '\n';
    return 0;
}