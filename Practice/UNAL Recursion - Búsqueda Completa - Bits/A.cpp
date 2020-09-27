#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    int res = (m / 2) * n;
    if (m % 2 != 0)
        res += (n / 2);
    cout << res << '\n';
    return 0;
}