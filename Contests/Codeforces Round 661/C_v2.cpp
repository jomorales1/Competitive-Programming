#include <bits/stdc++.h>

using namespace std;

void reset(vector<bool> chosen) {
    int n = chosen.size();
    for (int i = 0; i < n; i++) {
        chosen[i] = false;
    }
}

void solve() {
    int n = 0;
    cin >> n;
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    vector<bool> chosen(n, false);
    unordered_map<int, int> options;
    for (int s = 2; s <= 2 * n; s++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && !chosen[i] && !chosen[j]) {
                    if (weights[i] + weights[j] == s) {
                        chosen[i] = true; chosen[j] = true;
                        options[weights[i] + weights[j]]++;
                        break;
                    }
                }
            }
            if (chosen[i]) break;
            //reset(chosen);
        }
        reset(chosen);
    }
    int res = -1;
    for (auto option : options) {
        cout << option.first << " " << option.second << '\n';
        res = max(res, option.second);
    }
    cout << res << '\n';
}

int main() {
    // TODO: finish algorithm
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}