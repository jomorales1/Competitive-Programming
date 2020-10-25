#include <bits/stdc++.h>

using namespace std;

vector<int> divisors(int n) {
    vector<int> d;
    d.push_back(1);
    for (int i = 2; i < n; i++) {
        if (n % i == 0)
            d.push_back(i);
    }
    return d;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0); cout.tie(0);
    int n = 0; cin >> n;
    string a; cin >> a;
    int sum = 0;
    vector<int> b;
    for (char number : a) {
        int r = (number - '0');
        b.push_back(r);
        sum = sum + r;
    }
    vector<int> d = divisors(sum);
    int current = 0;
    assert(b.size() == n);
    bool find = false;
    for (int div : d) {
        for (int i = 0; i < n; i++) {
            current += b[i];
            if (current == div) {
                current = 0;
            } else if (current > div) {
                current = 0;
                break;
            }
            if (i == n - 1 && current == 0) find = true;
        }
        if (find) break;
    }
    cout << (find ? "YES\n" : "NO\n");
    return 0;
}