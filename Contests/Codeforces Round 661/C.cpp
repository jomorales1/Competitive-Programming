#include <bits/stdc++.h>

using namespace std;

bool contains(const vector<pair<int, int>>& pairs, const unordered_map<int, int>& oc, pair<int, int> a) {
    for (int i = 0; i < pairs.size(); i++) {
        if (pairs[i].first == a.first && pairs[i].second == a.second) {
            if ((int) oc.count(pairs[i].first) < 1)
                return true;
            if ((int) oc.count(pairs[i].second) < 1)
                return true;
        }
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    vector<int> weights(n);
    unordered_map<int, int> oc;
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
        oc[weights[i]]++;
    }
    unordered_map<int, int> s;
    int res = -1;
    vector<pair<int, int>> pairs;
    for (int i = 0; i < n - 1; i++) {
        //vector<int> individual_values;
        for (int j = i + 1; j < n; j++) {
            //if (contains(individual_values, weights[i] + weights[j]))
                //continue;
            if (s[weights[i] + weights[j]] + 1 <= (n / 2) && !contains(pairs, oc, {weights[i], weights[j]})){
                s[weights[i] + weights[j]]++;
                pairs.push_back({weights[i], weights[j]});
                oc[weights[i]]--;
                oc[weights[j]]--;
            }
            //individual_values.push_back(weights[i] + weights[j]);
            res = max(res, (int) s[weights[i] + weights[j]]);
        }
    }
    if (res % 2 != 0)
        res--;
    cout << res << "\n";
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}