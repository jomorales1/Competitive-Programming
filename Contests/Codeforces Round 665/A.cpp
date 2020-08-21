#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    if (k == 0) {
        cout << (n % 2 == 0 ? 0 : 1) << '\n';
    } else if (n < k) {
        cout << (k - n) << '\n'; 
    } else if (n > k) {
        cout << 0 << '\n';
    } else {
        cout << 0 << '\n';
    }
}

int option1(int n, int k) {
    if (k == 0) {
        return (n % 2 == 0 ? 0 : 1);
    } else if (n < k) {
        return (k - n);
    } else if (n > k) {
        return 0;
        //return (n % 2 == 0 && k % 2 == 0 ? 0 : 1);
    } else {
        return 0;
    }
}

int option2(int n, int k) {
    int res = 0;
    if (k == 0) {
        return (n % 2 == 0 ? 0 : 1);
    }
    while (n <= (int) 1e6) {
        for (int i = 0; i <= n; i++) {
            if (n - i == k)
                return res;
        }
        n++;
        res++;
    }
    return res;
}

void solve2() {
    int n, k;
    cin >> n >> k;
    cout << option2(n, k) << '\n';
}

void stress_test() {
    while (true) {
        int n = rand() % 100 + 10;
        int k = rand() % 100 + 10;
        int res1 = option1(n, k);
        int res2 = option2(n, k);
        cout << "n: " << n << ", k: " << k << '\n'; 
        if (res1 != res2) {
            cout << "Wrong answer\n";
            cout << "Correct answer: " << res2 << '\n';
            cout << "User's answer:  " << res1 << '\n';
            break;
        } else {
            cout << "OK\n";
        }
    }
}

int main() {
    stress_test();
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();
    return 0;
}