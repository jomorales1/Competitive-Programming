#include <bits/stdc++.h>

using namespace std;

void solve() {
    string number;
    cin >> number;
    int s; cin >> s;
    int sum = 0;
    int digits = 0;
    for (int i = 0; i < number.length(); i++) {
        sum += (number[i] - '0');
        if (sum < s)
            digits++;
    }
    if (sum <= s) {
        cout << 0 << '\n';
        return;
    }
    long long sum2;
    int power = 0;
    for (int i = number.length() - 1; i >= digits; i--) {
        sum2 += (number[i] - '0') * pow(10, power);
        power++;
    }
    cout << (pow(10, power + 1) - sum2) << '\n';
}

int main() {
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}