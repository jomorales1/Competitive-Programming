#include <bits/stdc++.h>

using namespace std;

int mod(int a, int b) {
    int c = a % b;
    return (c < 0 ? c + b : c);
}

int main() {
    int n = 0; cin >> n;
    unordered_map<int, pair<int, int>> distances;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        distances[a[i]].first = (i + 1);
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        distances[b[i]].second = (i + 1);
    }
    unordered_map<int, int> frequencies;
    int m = -1;
    for (int i = 0; i < n; i++) {
        int modulo = mod(distances[a[i]].first - distances[a[i]].second, n);
        frequencies[modulo]++;
        m = max(m, frequencies[modulo]);
    }
    cout << m << '\n';
    return 0;
}