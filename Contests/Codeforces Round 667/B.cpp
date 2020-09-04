#include <bits/stdc++.h>

using namespace std;

long long option1(int a, int b, int x, int y, int n) {
    int prev = a;
    a -= min(n, (a - x));
    int other = n - min(n, (prev - x));
    b -= min(other, (b - y));
    long long res = (long long) a * b;
    return res;
}

long long option2(int a, int b, int x, int y, int n) {
    int prev = b;
    b -= min(n, (b - y));
    int other = n - min(n, (prev - y));
    a -= min(other, (a - x));
    long long res = (long long) a * b;
    return res;
}

void solve() {
    int a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    long long one = option1(a, b, x, y, n);
    long long two = option2(a, b, x, y, n);
    cout << min(one, two) << '\n';
}

int main() {
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}