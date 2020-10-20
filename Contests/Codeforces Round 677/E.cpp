#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    long long n = 0; cin >> n;
    long long res = 0LL;
    long long fact = 1LL; 
    if (n == 2) {
        cout << 1 << '\n';
        return 0;
    }
    for (int i = n; i > 2; i--) {
        fact = (long long) (fact * i);
    }
    long long fact2 = 1LL;
    for (int i = 2; i <= n / 2; i++) {
        fact2 = (long long) (fact2 * i);
    }
    long long fact3 = fact2 / (n / 2);
    res = fact / (fact2 * fact2);
    res *= (fact3 * fact3);
    cout << res << '\n';
    return 0;
}