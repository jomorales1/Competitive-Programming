#include <bits/stdc++.h>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    reverse(s.begin(), s.end());
    reverse(t.begin(), t.end());
    long long equal = 0;
    int n = min(s.length(), t.length());
    for (int i = 0; i < n; i++) {
        if (s[i] == t[i])
            equal++;
        else
            break;
    }
    long long res = (long long) s.length() + t.length() - 2 * equal;
    cout << res << '\n';
    return 0;
}