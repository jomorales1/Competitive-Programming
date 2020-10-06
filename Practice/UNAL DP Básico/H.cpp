#include <bits/stdc++.h>
    
using namespace std;

bool compare(pair<int, int> &a, pair<int, int> &b) {
    if (a.second == b.second)
        return a.first > b.first;
    return a.second < b.second;
}
bool compare2(pair<int, int> &a, pair<int, int> &b) {
    return a.first < b.first;
}
    
int main() {
    int v = 0; cin >> v;
    vector<pair<int, int>> costs(9);
    for (int i = 0; i < 9; i++) {
        cin >> costs[i].second;
        costs[i].first = i + 1;
    }
    sort(costs.begin(), costs.end(), compare);
    pair<int, int> optimal = costs[0];
    vector<int> res;
    while (v > 0 && v >= optimal.second) {
        res.push_back(optimal.first);
        v -= optimal.second;
    }
    if (res.empty()) {
        cout << -1 << '\n';
        return 0;
    }
    sort(costs.begin(), costs.end(), compare2);
    int change = 0;
    if (v > 0) {
        while (v > 0 && change < res.size() - 1 && res[change] < costs.back().first) {
            if (v + optimal.second - costs.back().second >= 0) {
                res[change] = costs.back().first;
                v = v + optimal.second - costs.back().second;
                change++;
            } else {
                costs.pop_back();
            }
        }
    }
    for (int i = 0; i < (int) res.size(); i++) {
        cout << res[i];
    }
    cout << '\n';
    return 0;
}