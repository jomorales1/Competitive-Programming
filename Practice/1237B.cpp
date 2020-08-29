#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 0;
    cin >> n;
    vector<int> in(n);
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    vector<int> out(n);
    for (int i = 0; i < n; i++) {
        cin >> out[i];
    }
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        pos[out[i] - 1] = i;
    }
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        c[i] = pos[in[i] - 1];
    }
    int res = 0;
    int m = -1;
    for (int i = 0; i < n; i++) {
        if (c[i] > m) {
            m = c[i];
        } else {
            res++;
        }
    }
    cout << res << '\n';
    return 0;
}