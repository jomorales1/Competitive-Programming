#include <bits/stdc++.h>

using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

bool isTaken(int a, const vector<pair<int, int>>& r) {
    if (a == 0)
        return false;
    for (auto np: r) {
        if (np.first * np.second == a)
            return true;
    }
    return false;
}

void solve(const vector<int>& primes) {
    int n;
    cin >> n;
    if (n < 31) {
        cout << "NO" << "\n";
        return;
    }
    int s = primes.size();
    vector<pair<int, int>> result;
    int sum = 0;
    int taken = 0;
    for (int i = 0; i < s - 1; i++) {
        if (taken >= 3)
            break;
        for (int j = i + 1; j < s; j++) {
            if (taken >= 3)
                break;
            if ((sum + (primes[i] * primes[j]) <= n)) {
                if (!isTaken(n - (sum + primes[i] * primes[j]), result) && (n - (sum + primes[i] * primes[j]) != primes[i] * primes[j])) {
                    result.push_back(make_pair(primes[i], primes[j]));
                    sum += (primes[i] * primes[j]);
                    taken++;
                } else {
                    break;
                }
            }
        }
    }
    cout << "YES" << "\n";
    for (auto np: result) {
        cout << (np.first * np.second) << " ";
    }
    if (sum < n) {
        cout << (n - sum) << "\n";
    } else {
        cout << "\n";
    }
}

int main() {
    int t;
    cin >> t;
    vector<int> primes;
    for (int i = 2; i < 1000; i++) {
        if (isPrime(i))
            primes.push_back(i);
    }
    for (int i = 0; i < t; i++) {
        solve(primes);
    }
    return 0;
}