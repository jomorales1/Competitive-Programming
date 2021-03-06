#include <bits/stdc++.h>

using namespace std;

long long sum_pot(int power, int n) {
    long long res = (1 - pow(power, n + 1)) / (1 - power);
    long long up = (1 - pow(power, n + 1));
    long long down = 1 - power;
    return abs(up / down);
}

void solve() {
    int n = 0;
    cin >> n;
    long long sum = 0;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        sum += numbers[i];
    }
    sort(numbers.begin(), numbers.end());
    long long operations = 0;
    long long left = 1;
    long long right = (long long) pow(1e9, 1 / (n - 1));
    long long minimum = LONG_LONG_MAX;
    int power = -1;
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (abs(sum - sum_pot(mid, n - 1)) < minimum) {
            minimum = abs(sum - sum_pot(mid, n - 1));
            power = mid;
        }
        if (sum > sum_pot(mid, n - 1)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    cout << sum_pot(power, n - 1) << '\n';
    cout << minimum << " " << power << '\n';
}

void solve2() {
    int n; cin >> n;
    vector<int> numbers(n);
    long long sum = 0LL;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        sum += numbers[i];
    }
    sort(numbers.begin(), numbers.end());
    int limit = (int) 1e6;
    long long res = LONG_LONG_MAX;
    long long operations = 0LL;
    for (int i = 1; i <= limit; i++) {
        for (int j = 0; j < n; j++) {
            operations += abs(numbers[j] - pow(i, j));
            if (operations > res)
                break;
        }
        if (operations < res) {
            res = operations;
        }
        operations = 0;
    }
    cout << res << '\n';
}

int main() {
    solve2();
    return 0;
}