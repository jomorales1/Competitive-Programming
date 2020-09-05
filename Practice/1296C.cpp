#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

void operate(char direction, int &x, int &y) {
    if (direction == 'U') {
        y++;
    } else if (direction == 'R') {
        x++;
    } else if (direction == 'D') {
        y--;
    } else {
        x--;
    }
}

void solve() {
    int n = 0; cin >> n;
    string s; cin >> s;
    map<pair<int, int>, pair<int, int>> frequencies;
    frequencies[{0, 0}].first = 1;
    frequencies[{0, 0}].second = 0;
    int x = 0, y = 0;
    int first = -1, last = -1;
    for (int i = 0; i < n; i++) {
        operate(s[i], x, y);
        frequencies[{x, y}].first++;
        if (frequencies[{x, y}].first > 1) {
            if (first != -1 && last != -1) {
                if ((last - first) > (i + 1 - frequencies[{x, y}].second)) {
                    first = frequencies[{x, y}].second + 1;
                    last = i + 1;
                    if (last - first == 1)
                        break;
                    frequencies[{x, y}].second = i + 1;
                } else {
                    frequencies[{x, y}].second = i + 1;
                }
            } else {
                first = frequencies[{x, y}].second + 1;
                last = i + 1;
                if (last - first == 1)
                    break;
                frequencies[{x, y}].second = i + 1;
            }
        } else {
            frequencies[{x, y}].second = i + 1;
        }
    }
    if (first != -1 && last != -1) {
        cout << first << ' ' << last << '\n';
    } else {
        cout << -1 << '\n';
    }
}

void solve2() {
    int n = 0; cin >> n;
    string s; cin >> s;
    int l = -1, r = n;
    map<pair<int, int>, int> visited;
    pair<int, int> cur = {0, 0};
    visited[cur] = 0;
    for (int i = 0; i < n; i++) {
        operate(s[i], cur.first, cur.second);
        if (visited.count(cur)) {
            if (i - visited[cur] < r - l) {
                l = visited[cur];
                r = i;
            }
        }
        visited[cur] = i + 1;
    }
    if (l != -1) {
        cout << l + 1 << ' ' << r + 1 << '\n';
    } else {
        cout << -1 << '\n';
    }
}

char cardinal(int x) {
    if (x == 0) return 'U';
    if (x == 1) return 'R';
    if (x == 2) return 'D';
    return 'L';
}

// void stress_test() {
//     while (true) {
//         int n = rand() % 50 + 20;
//         char direction;
//         string s = "";
//         for (int i = 0; i < n; i++) {
//             int x = rand() % 4;
//             direction = cardinal(x);
//             s += direction;
//         }
//         pair<int, int> sola = solve(s, n);
//         pair<int, int> solb = solve2(s, n);
//         if ((sola.second - sola.first) != (solb.second - solb.first)) {
//             cout << "Wrong answer\n";
//             cout << "String: " << s << '\n';
//             cout << "Correct answer: " << solb.first << ' ' << solb.second << '\n';
//             cout << "User's answer:  " << sola.first << ' ' << sola.second << '\n';
//             break;
//         } else {
//             cout << "OK\n";
//         }
//     }
// }

int main() {
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}