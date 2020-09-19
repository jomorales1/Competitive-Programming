#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 0; cin >> n;
    priority_queue<int> snacks;
    int needed = n;
    int snack;
    for (int i = 0; i < n; i++) {
        cin >> snack;
        snacks.push(snack);
        while (!snacks.empty() && snacks.top() == needed) {
            cout << needed << ' ';
            needed--;
            snacks.pop();
        }
        cout << '\n';
    }
    return 0;
}