#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0; cin >> n;
    int k = 0; cin >> k;
    string s; cin >> s;
    int losses = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') losses++;
    }
    if (k >= losses) {
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') s[i] = 'W';
        }
    } else {
        int moves = 0;
        int prev = 0;
        while (moves < k) {
            for (int i = 1; i < n - 1; i++) {
                if (s[i - 1] == 'W' && s[i + 1] == 'W' && s[i] == 'L') {
                    s[i] = 'W';
                    moves++;
                }
                if (moves == k) break;
            }
            if (moves == prev || moves == k) break;
            prev = moves;
        }
        prev = moves;
        while (moves < k) {
            for (int i = 1; i < n; i++) {
                if (s[i - 1] == 'W' && s[i] == 'L') {
                    s[i] = 'W';
                    moves++;
                }
                if (moves == k) break;
            }
            if (moves == prev || moves == k) break;
            prev = moves;
        }
        prev = moves;
        while (moves < k) {
            for (int i = 0; i < n - 1; i++) {
                if (s[i + 1] == 'W' && s[i] == 'L') {
                    s[i] = 'W';
                    moves++;
                }
                if (moves == k) break;
            }
            if (moves == prev || moves == k) break;
            prev = moves;
        }
        if (moves < k) {
            for (int i = 0; i < n; i++) {
                if (s[i] == 'L') {
                    s[i] = 'W';
                    moves++;
                }
                if (moves == k) break;
            }
        }
    }
    int score = 0;
    if (s[0] == 'W') score++;
    for (int i = 1; i < n; i++) {
        if (s[i] == 'W' && s[i - 1] == 'W') {
            score += 2;
        } else if (s[i] == 'W') score++;
    }
    cout << score << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}