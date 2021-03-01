#include <bits/stdc++.h>

using namespace std;

set<long long> possible;

void process(vector<int> &a, vector<long long> &prefix_sum, int left, int right) {
    if (left > right) return;
    if (left == right) {
        possible.insert((long long) a[left]);
        return;
    }
    if (left == 0) {
        possible.insert(prefix_sum[right]);
    } else {
        possible.insert(prefix_sum[right] - prefix_sum[left - 1]);
    }
    int target = (a[left] + a[right]) / 2;
    int l = left, r = right, mid;
    while (l <= r) {
        mid = l + (r - l) / 2;
        if (a[mid] == target)
            break;
        if (a[mid] < target)
            l = mid + 1;
        if (a[mid] > target)
            r = mid - 1;
    }
    int middle = mid;
    if (a[middle] == target) {
        while (middle < right) {
            if (a[middle] == a[middle + 1] && a[middle] == target)
                middle++;
            else break;
        }
    } else {
        while (middle > left) {
            if (a[middle] > target)
                middle--;
            else break;
        }
    }
    if (middle == right) return;
    process(a, prefix_sum, left, middle);
    process(a, prefix_sum, middle + 1, right);
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<long long> tests(q);
    for (int i = 0; i < q; i++) {
        cin >> tests[i];
    }
    vector<long long> prefix_sum(n);
    long long sum = 0LL;
    for (int i = 0; i < n; i++) {
        sum += (long long) a[i];
        prefix_sum[i] = sum;
    }
    process(a, prefix_sum, 0, n - 1);
    for (int i = 0; i < q; i++) {
        if (possible.count(tests[i])) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    possible.clear();
}

int main() {
    int t = 1; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}