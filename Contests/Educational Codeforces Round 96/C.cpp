#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0; cin >> n;
    int left = 1, right = n;
    vector<pair<int, int>> ops;
    int res = 1;
    int op = 0;
    set<int> used;
    for (int i = 0; i < n - 1; i++) {
        if (right - left == 1) {
            res = (int) ceil((left + right) / 2.0);
            ops.push_back({left, right});
            break;
        }
        if (left % 2 == right % 2) {
            res = (left + right) / 2;
            used.insert(left); used.insert(right);
            ops.push_back({left, right});
            op++;
            if (op == n - 1) break;
            if (right - left >= 2 && i != n - 2) {
                ops.push_back({res, res});
                op++;
            }
            if (op == n - 1) break;
            left++; right--;
            if (left == right) break;
        } else if (left % 2 == 0) {
            res = (left + (right - 1)) / 2;
            used.insert(left); used.insert(right - 1);
            ops.push_back({left, right - 1});
            op++;
            if (op == n - 1) break;
            if (right - left >= 2 && i != n - 2) {
                ops.push_back({res, res});
                op++;
            }
            if (op == n - 1) break;
            left++;
            if (left == right) break;
        } else if (right % 2 == 0) {
            res = ((left + 1) + right) / 2;
            used.insert(left + 1); used.insert(right);
            ops.push_back({left + 1, right});
            op++;
            if (op == n - 1) break;
            if (right - left >= 2 && i != n - 2) {
                ops.push_back({res, res});
                op++;
            }
            if (op == n - 1) break;
            right--;
            if (left == right) break;
        }
        while (used.count(left)) left++;
        while (used.count(right)) right--;
        if (left > right) break;
    }
    cout << res << '\n';
    for (int i = 0; i < (int) ops.size(); i++) {
        cout << ops[i].first << ' ' << ops[i].second << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}