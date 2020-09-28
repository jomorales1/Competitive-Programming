#include <bits/stdc++.h>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    if (n == 1) {
        cout << 0 << '\n';
        return;
    }
    long long moves = 0;
    long long accum = 1;
    long long number = 1;
    // while (n >= accum) {
    //     accum = number * (number + 1);
    //     moves = number * 2;
    //     if (n <= accum - number) {
    //         moves--;
    //         if (n <= accum - number)
    //             moves--;
    //         break;
    //     }
    //     number++;
    // }
    while (n >= accum) {
        accum += number;
        if (n < accum) break;
        moves++;
        if (n == accum) break;
        accum += number;
        if (n < accum) break;
        moves++;
        if (n == accum) break;
        number++;
    }
    cout << moves << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}