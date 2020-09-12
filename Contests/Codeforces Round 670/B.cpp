#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0; cin >> n;
    vector<int> positives;
    vector<int> negatives;
    int element;
    for (int i = 0; i < n; i++) {
        cin >> element;
        if (element >= 0) {
            positives.push_back(element);
        } else {
            negatives.push_back(element);
        }
    }
    sort(positives.rbegin(), positives.rend());
    sort(negatives.begin(), negatives.end());
    int chosen = 0;
    long long product = 1LL;
    int neg = negatives.size();
    int index = 0;
    for (int i = 0; i < negatives.size() - 1; i++) {
        if (neg > 1) {
            if ((negatives[i] > positives[index]) || index >= positives.size()) {
                product *= (long long) (negatives[i] * negatives[i + 1]);
                chosen += 2;
                neg -= 2;
            } else {
                product *= (long long) positives[index];
                index++;
            }
        } else {
            product *= (long long) positives[index];
            index++;
            chosen++;
        }
        if (chosen == 5)
            break;
    }
}

int main() {
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}