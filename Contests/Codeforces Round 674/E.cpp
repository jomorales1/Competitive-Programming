#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    long long n = 0; cin >> n;
    long long a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    long long b1, b2, b3;
    cin >> b1 >> b2 >> b3;
    long long minimum = n - (min(b1, a1) + min(b2, a2) + min(b3, a3)) - (min(b1 - min(b1, a1), a2 - min(a2, b2)) - min(b2 - min(a2, b2), a3 - min(a3, b3)) - min(b3 - min(a3 , b3), a1 - min(a1, b1)));
    long long maximum = min(a1, b2) + min(a2, b3) + min(a3, b1);
    cout << minimum << ' ' << maximum << '\n';
    return 0;
}