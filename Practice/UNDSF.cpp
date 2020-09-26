#include <bits/stdc++.h>

using namespace std;

class comparison {
    public:
        bool operator() (pair<int, int> &a, pair<int, int> &b) {
            int length1 = a.second - a.first + 1;
            int length2 = b.second - b.first + 1;
            if (length1 == length2)
                return a.first > b.first;
            return length1 < length2;
        }
};

int len(pair<int, int> &segment) {
    return (segment.second - segment.first + 1);
}

void solve() {
    int n = 0; cin >> n;
    vector<int> a(n, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, comparison> q;
    q.push({0, n - 1});
    int current = 1;
    while (!q.empty()) {
        pair<int, int> sub_array = q.top();
        q.pop();
        if (len(sub_array) % 2 == 0) {
            int mid = (sub_array.first + sub_array.second - 1) / 2;
            a[mid] = current;
            if (len(sub_array) > 1) {
                if (mid + 1 <= sub_array.second)
                    q.push({mid + 1, sub_array.second});
                if (mid - 1 >= sub_array.first)
                    q.push({sub_array.first, mid - 1});
            }
        } else {
            int mid = (sub_array.first + sub_array.second) / 2;
            a[mid] = current;
            if (len(sub_array) > 1) {
                if (mid - 1 >= sub_array.first)
                    q.push({sub_array.first, mid - 1});
                if (mid + 1 <= sub_array.second)
                    q.push({mid + 1, sub_array.second});
            }
        }
        current++;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
}

int main() {
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}