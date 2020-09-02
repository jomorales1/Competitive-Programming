#include <bits/stdc++.h>

using namespace std;

bool contains(const vector<char> &letters, char letter) {
    for (const auto &l : letters) {
        if (l == letter)
            return true;
    }
    return false;
}

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<char> letters(k);
    for (int i = 0; i < k; i++) {
        cin >> letters[i];
    }
    long long segment = 0;
    long long res = 0;
    for (int i = 0; i < n; i++) {
        if (contains(letters, s[i])) {
            segment++;
        } else {
            res += (segment * (segment + 1)) / 2;
            segment = 0;
        }
    }
    res += (segment * (segment + 1)) / 2;
    cout << res << '\n';
    return 0;
}