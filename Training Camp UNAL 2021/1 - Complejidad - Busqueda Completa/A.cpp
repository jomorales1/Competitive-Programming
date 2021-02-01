#include <bits/stdc++.h>

using namespace std;

double distance(pair<int, int> &a, pair<int, int> &b) {
    double res = sqrt(pow(b.first - a.first, 2.0) + pow(b.second - a.second, 2.0));
    return res;
}

int main() {
    int n = 0; cin >> n;
    vector<pair<int, int>> points(n);
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }
    int done = 0;
    int current = 0;
    int next = -1;
    double best = -1.0;
    while (done < n - 1) {
        for (int i = 0; i < n; i++) {
            if (visited[i] || i == current) continue;
            double dist = distance(points[current], points[i]);
            if (dist > best) {
                next = i; best = dist;
            }
        }
        if (next == -1) break;
        visited[current] = true;
        cout << current + 1 << ' ';
        current = next;
        next = -1;
        best = -1.0;
        done++;
    }
    cout << current + 1 << '\n';
    return 0;
}