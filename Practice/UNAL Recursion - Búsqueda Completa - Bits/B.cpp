#include <bits/stdc++.h>

using namespace std;

bool check(long long n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum == 10;
}

int main() {
    int k = 0; cin >> k;
    long long number = 19;
    while (k > 0) {
        if (check(number)) {
            k--;
        }
        number += 9;
    }
    cout << number - 9 << '\n';
    return 0;
}