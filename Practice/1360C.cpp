#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0;
    cin >> n;
    vector<int> even;
    vector<int> odd;
    int element;
    for (int i = 0; i < n; i++) {
        cin >> element;
        if (element % 2 == 0) {
            even.push_back(element);
        } else {
            odd.push_back(element);
        }
    }
    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());
    if (even.size() % 2 == 0 && odd.size() % 2 == 0) {
        cout << "YES\n";
        return;
    }
    for (int i = 0; i < odd.size(); i++) {
        for (int j = 0; j < even.size(); j++) {
            if (odd[i] == even[j] + 1 || odd[i] + 1 == even[j]) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}