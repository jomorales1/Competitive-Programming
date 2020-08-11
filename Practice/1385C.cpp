#include <bits/stdc++.h>
#include <cstdlib>

using namespace std;

void test_case(const vector<int>& a) {
    int n = a.size();
    int index = n - 1;
    while (index > 0 && a[index - 1] >= a[index]) {
        index--;
    }
    while (index > 0 && a[index - 1] <= a[index]) {
        index--;
    }
    cout << index << "\n";
}

int main() {
    int t, n;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        vector<int> a(n);
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
        }
        test_case(a);
    }
    return 0;
}