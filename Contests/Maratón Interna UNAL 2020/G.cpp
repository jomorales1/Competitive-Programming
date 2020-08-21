#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
vector<int> fact(MOD + 1, 0);

int factorial(int n) {
    if (n == 1 || n == 0)
        return 1;
    if (fact[n] != 0)
        return fact[n];
    return (n * fact[n - 1]) % MOD;
}

int main() {
    fact[0] = 1;
    fact[1] = 1;
    int n = 0, m = 0;
    cin >> n >> m;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
    }
    int answer = factorial(n) / (1 << m);
    cout << answer << '\n';
    return 0;
}