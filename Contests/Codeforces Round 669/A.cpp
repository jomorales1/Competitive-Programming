#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

void solve() {
    int n = 0; cin >> n;
    vector<int> elements(n);
    bool check = true;
    int k = 0;
    for (int i = 0; i < n; i++) {
        cin >> elements[i];
        if (k % 2 != 0 && check) {
            if (elements[i - 1] != elements[i]) {
                check = false;
            }
        }
        k++;
    }
    if (check) {
        cout << n << '\n';
        for (int i = 0; i < n; i++) {
            cout << elements[i] << ' ';
        }
        cout << '\n';
    } else {
        if (n == 2) {
            cout << 1 << '\n';
            cout << 0 << '\n';
            return;
        }
        int index1 = 0;
        int index2 = 1;
        int s = 0;
        cout << (n / 2) << '\n';
        while (s < n / 2) {
            if (elements[index1] == elements[index2]) {
                cout << elements[index1] << ' ' << elements[index2] << ' ';
                s += 2;
                index1++;
                index2 = index1 + 1;
            } else {
                index2++;
                if (index2 == n - 1) {
                    index1++;
                    index2 = index1 + 1;
                }
            }
        }
        cout << '\n';
    }
}

void solve2() {
    int n = 0; cin >> n;
    vector<int> count(2);
    int element;
    for (int i = 0; i < n; i++) {
        cin >> element;
        count[element]++;
    }

    if (count[0] >= n / 2) {
        cout << n / 2 << '\n';
        for (int i = 0; i < n / 2; i++) {
            cout << 0 << ' ';
        }
        cout << '\n';
    } else {
        int len = n / 2;
        if (len % 2 != 0) {
            len++;
        }
        cout << len << '\n';
        for (int i = 0; i < len; i++) {
            cout << 1 << ' ';
        }
        cout << '\n';
    }
}

int main() {
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve2();
    }
    return 0;
}