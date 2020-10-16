#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 0; cin >> n;
    int m = 0; cin >> m;
    priority_queue<int, vector<int>, greater<int>> q;
    int maximum = -1;
    int element;
    for (int i = 0; i < n; i++) {
        cin >> element;
        maximum = max(maximum, element);
        q.push(element);
    }
    maximum += m;
    while (m > 0) {
        int el = q.top() + 1;
        q.pop(); m--;
        q.push(el);
    }
    int minimum = -1;
    while (!q.empty()) {
        int b = q.top();
        minimum = max(minimum, b);
        q.pop();
    }
    cout << minimum << ' ' << maximum << '\n';
    return 0;
}