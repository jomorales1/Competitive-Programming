#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 0; cin >> n;
    vector<int> spheres(n);
    for (int i = 0; i < n; i++) {
        cin >> spheres[i];
    }
    sort(spheres.begin(), spheres.end());
    vector<int> odd;
    vector<int> even;
    for (int i = 0; i < n / 2; i++) {
        odd.push_back(spheres[i]);
    }
    for (int i = n / 2; i < n; i++) {
        even.push_back(spheres[i]);
    }
    int e = 0, od = 0;
    if (n % 2 == 0) {
        cout << (int) odd.size() - 1 << '\n';
    } else {
        cout << (int) odd.size() << '\n';
    }
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            cout << even[e] << ' ';
            e++;
        } else {
            cout << odd[od] << ' ';
            od++;
        }
    }
    cout << '\n';
    return 0;
}