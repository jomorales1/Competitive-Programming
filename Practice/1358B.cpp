#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0;
    cin >> n;
    vector<int> grannies(n);
    for (int i = 0; i < n; i++) {
        cin >> grannies[i];
    }
    sort(grannies.begin(), grannies.end());
    int present = 1;
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (present >= grannies[i]) {
            present++;
        } else {
            if ((present + s) >= grannies[i]) {
                present += s + 1;
                s = 0;
                continue;
            }
            s++;
        }
        //cout << present << " " << s << '\n';
    }
    cout << present << '\n';
}

int main() {
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}