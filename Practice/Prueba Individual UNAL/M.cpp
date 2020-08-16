#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    string brackets;
    cin >> brackets;
    stack<char> s;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (brackets[i] == '(') {
            s.push('(');
            count++;
        } else if (brackets[i] == ')' && s.size() >= 1){
            s.pop();
            count++;
        }
    }
    cout << (n - count) << '\n';
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}