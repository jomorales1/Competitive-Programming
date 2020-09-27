#include <bits/stdc++.h>

using namespace std;

vector<int> divisors(int n) {
    vector<int> d;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            if (n / i == i) d.push_back(i);
            else {
                d.push_back(i);
                d.push_back(n / i);
            }
        }
    }
    return d;
}

bool is_lucky(int n) {
    while (n > 0) {
        if (n % 10 != 4 && n % 10 != 7) return false;
        n /= 10;
    }
    return true;
}

int main() {
    map<int, int> luckies;
    for (int i = 4; i <= 1000; i++) {
        if (is_lucky(i))
            luckies[i]++;
    }
    int n; cin >> n;
    if (luckies[n]) {
        cout << "YES\n";
    } else {
        vector<int> d = divisors(n);
        for (int i = 0; i < (int) d.size(); i++) {
            if (luckies[d[i]]) {
                cout << "YES\n";
                return 0;
            }
        }
        cout << "NO\n";
    }
    return 0;
}