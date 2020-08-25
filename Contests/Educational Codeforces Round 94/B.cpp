#include <bits/stdc++.h>

using namespace std;

int gcd_2(int a, int b) {
    if (b > a)
        swap(a, b);
    if (b == 0)
        return a;
    return gcd_2(b, a % b);
}

int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}

void solve() {
    int p, f;
    cin >> p >> f;
    int cnt_s, cnt_w;
    cin >> cnt_s >> cnt_w;
    int s, w;
    cin >> s >> w;
    int res = 0;
    int x, y, g;
    if (find_any_solution(s, w, p, x, y, g)) {
        res += (min(x, cnt_s) + min(y, cnt_w));
        p -= (min(x, cnt_s) * s + min(y, cnt_w) * w);
        cnt_s -= min(x, cnt_s);
        cnt_w -= min(y, cnt_w);
    }
    if (find_any_solution(s, w, f, x, y, g)) {
        res += (min(x, cnt_s) + min(y, cnt_w));
        f -= (min(x, cnt_s) * s + min(y, cnt_w) * w);
    }
    cout << res << '\n';
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}