#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    unordered_map<char, int> frequencies;
    for (const auto &word : words) {
        for (int i = 0; i < word.length(); i++) {
            frequencies[word[i]]++;
        }
    }
    for (const auto &f : frequencies) {
        if (f.second % n != 0) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}