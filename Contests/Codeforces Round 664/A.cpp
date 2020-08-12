#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

int count_odd(long long r, long g, long b, long w) {
    int res = 0;
    if (r % 2 != 0)
        res++;
    if (g % 2 != 0)
        res++;
    if (b % 2 != 0)
        res++;
    if (w % 2 != 0)
        res++;
    return res;
}

string solve() {
    long long r, g, b, w;
    cin >> r >> g >> b >> w;
    if (r == 0 || g == 0 || b == 0) {
        if (count_odd(r, b, g, w) > 1) {
            return "No\n";
        } else {
            return "Yes\n";
        }
    }
    if (count_odd(r, g, b, w) == 0 || count_odd(r, g, b, w) == 1 || count_odd(r, g, b, w) == 3 || count_odd(r, g, b, w) == 4) {
        return "Yes\n";
    } else {
        return "No\n";
    }
}

/*string solve2(long long r, long long g, long long b, long long w) {
    while (r >= 0 && g >= 0 && b >= 0) {
        if (count_odd(r, g, b, w) == 0 || count_odd(r, g, b, w) == 1) {
            return "Yes\n";
        }
        r--; g--; b--;
        w += 3;
    }
    return "No\n";
}*/

int main() {
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string res1 = solve();
        cout << res1;
    }
    /*int r, g, b, w;
    while (true) {
        r = rand() % 100;
        g = rand() % 100;
        b = rand() % 100;
        w = rand() % 100;
        cout << r << " " << g << " " << b << " " << w << "\n";
        string res1 = solve(r, g, b, w);
        string res2 = solve2(r, g, b, w);
        if (res1 != res2) {
            cout << "Wrong answer: " << res1 << " " << res2 << "\n";
            break;
        } else {
            cout << "OK\n";
        }
    }*/
    return 0;
}