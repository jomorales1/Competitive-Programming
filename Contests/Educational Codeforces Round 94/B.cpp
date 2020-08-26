#include <bits/stdc++.h>

using namespace std;

void solve() {
    int p, f;
    cin >> p >> f;
    int cnt_s, cnt_w;
    cin >> cnt_s >> cnt_w;
    int s, w;
    cin >> s >> w;
    if (s > w) {
        swap(s, w);
        swap(cnt_s, cnt_w);
    }
    int res = 0;
    for (int s1 = 0; s1 <= min(cnt_s, p / s); s1++) {
        int w1 = min(cnt_w, (p - s1 * s) / w);
        int s2 = min(cnt_s - s1, f / s);
        int w2 = min(cnt_w - w1, (f - s * s2) / w);
        res = max(res, s1 + s2 + w1 + w2);
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