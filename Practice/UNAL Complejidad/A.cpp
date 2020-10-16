#include <bits/stdc++.h>

using namespace std;

const int N = 2000000;
int sieve[N + 1];
int phi[N + 1];
int depthphi[N + 1];
int dp[N + 1];

bool prime(int n) {
    return sieve[n] == 0;
}

vector<pair<int, int>> factors(int n) {
    vector<pair<int, int>> f;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            pair<int, int> factor = {i, 0};
            while (n % i == 0) {
                n /= i;
                factor.second++;
            }
            f.push_back(factor);
        }
    }
    if (n > 1) f.push_back({n, 1});
    return f;
}

void solve() {
    int m, n;
    cin >> m >> n;
    cout << dp[n] - dp[m - 1] << '\n';
}

int main() {
    memset(sieve, 0, sizeof sieve);
    for (int i = 2; i <= N; i++) {
        if (sieve[i]) continue;
        for (int j = i * 2; j <= N; j += i) {
            sieve[j] = i;
        }
    }
    memset(phi, 0, sizeof phi);
    for (int i = 2; i <= N; i++) {
        if (prime(i)) {
            phi[i] = i - 1;
        } else {
            vector<pair<int, int>> f = factors(i);
            int product = 1;
            for (auto factor : f) {
                product *= (pow(factor.first, factor.second - 1) * (factor.first - 1));
            }
            phi[i] = product;
        }
    }
    memset(depthphi, 0, sizeof depthphi);
    for (int i = 2; i <= N; i++) {
        int p = phi[i];
        int steps = 1;
        while (p > 1) {
            p = phi[p];
            steps++;
        }
        depthphi[i] = steps;
    }
    memset(dp, 0, sizeof dp);
    int sum = 0;
    for (int i = 2; i <= N; i++) {
        sum += depthphi[i];
        dp[i] = sum;
    }
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}