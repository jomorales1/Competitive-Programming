#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k, z;
    cin >> n >> k >> z;
    vector<int> numbers(n);
    int dp[k + 1];
    int max_index = 0, maximum = -1;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        if (numbers[i] > maximum && i <= k) {
            maximum = numbers[i];
            max_index = i;
        }
    }
    int pos = 1;
    int moves = 1;
    int left_moves = z;
    dp[0] = numbers[0];
    dp[1] = dp[0] + numbers[1];
    for (int i = 2; i < k + 1; i++) {
        if (pos == 0) {
            pos++;
            dp[i] = numbers[pos] + dp[i - 1];
        } else  if (pos == n - 1 && left_moves > 0) {
            pos--;
            left_moves--;
            dp[i] = numbers[pos] + dp[i - 1];
        } else {
            if (abs(max_index - pos) <= (k - moves)) {
                if (pos == max_index) {
                    if (numbers[pos + 1] > numbers[pos - 1]) {
                        pos++;
                        dp[i] = numbers[pos] + dp[i - 1];
                    } else if (left_moves > 0) {
                        pos--;
                        left_moves--;
                        dp[i] = numbers[pos] + dp[i - 1];
                    } else {
                        pos++;
                        dp[i] = numbers[pos] + dp[i - 1];
                    }
                } else if (pos < max_index) {
                    pos++;
                    dp[i] = numbers[pos] + dp[i - 1];
                } else if (left_moves > 0) {
                    pos--;
                    left_moves--;
                    dp[i] = numbers[pos] + dp[i - 1];
                } else {
                    pos++;
                    dp[i] = numbers[pos] + dp[i - 1];
                }
                moves++;
                if (moves == k)
                    break;
                continue;
            }
            int option1 = numbers[pos + 1] + dp[i - 1];
            int option2 = numbers[pos - 1] + dp[i - 1];
            if (left_moves > 0 && option2 > option1) {
                pos--;
                left_moves--;
                dp[i] = option2;
            } else {
                pos++;
                dp[i] = option1;
            }
        }
        moves++;
        if (moves == k)
            break;
    }
    // for (int i = 0; i < k + 1; i++) {
    //     cout << dp[i] << ' ';
    // }
    // cout << '\n';
    cout << dp[k] << '\n';
}

int main() {
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}