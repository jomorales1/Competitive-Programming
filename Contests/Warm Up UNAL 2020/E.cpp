#include <bits/stdc++.h>

using namespace std;

const int MAX_N = (int) 1e5;
int t[4 * MAX_N];

void build(int a[], int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = 0;
    }
}

void update(int v, int tl, int tr, int l, int r, int sub) {
    if (l > r)
        return;
    if (l == tl && r == tr) {
        t[v] = max(0, t[v] - sub);
    } else {
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), sub);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, sub);
    }
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return t[v] + get(v*2, tl, tm, pos);
    else
        return t[v] + get(v*2+1, tm+1, tr, pos);
}

int main() {
    int n, q;
    cin >> n >> q;
    int heights[n];
    int sum = 0, element;
    for (int i = 0; i < n; i++) {
        cin >> element;
        sum += element;
        heights[i] = sum;
    }
    build(heights, 1, 0, n - 1);
    int option, s, a, b;
    for (int i = 0; i < q; i++) {
        cin >> option;
        if (option == 1) {
            cin >> a >> b;
            cout << get(1, a - 1, b - 1, n / 2) << '\n';
        } else {
            cin >> a >> b >> s;
            update(1, 0, n - 1, a - 1, b - 1, s);
        }
    }
    return 0;
}