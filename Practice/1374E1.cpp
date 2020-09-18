#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> only_alice;
    vector<int> only_bob;
    vector<int> both;
    int time, alice, bob;
    for (int i = 0; i < n; i++) {
        cin >> time >> alice >> bob;
        if (alice + bob == 2) {
            both.push_back(time);
        } else if (alice == 1) {
            only_alice.push_back(time);
        } else if (bob == 1) {
            only_bob.push_back(time);
        }
    }
    sort(both.begin(), both.end());
    sort(only_alice.begin(), only_alice.end());
    sort(only_bob.begin(), only_bob.end());
    vector<long long> pref_sum_both;
    vector<long long> pref_sum_alice;
    vector<long long> pref_sum_bob;
    long long sum_both = 0, sum_alice = 0, sum_bob = 0;
    for (int i = 0; i < (int) both.size(); i++) {
        sum_both += (long long) both[i];
        pref_sum_both.push_back(sum_both);
    }
    for (int i = 0; i < (int) only_alice.size(); i++) {
        sum_alice += (long long) only_alice[i];
        pref_sum_alice.push_back(sum_alice);
    }
    for (int i = 0; i < (int) only_bob.size(); i++) {
        sum_bob += (long long) only_bob[i];
        pref_sum_bob.push_back(sum_bob);
    }
    long long ans = LONG_LONG_MAX;
    for (int i = min((int) both.size(), k); i >= 0; i--) {
        long long option = 0;
        if (i > 0) {
            option += pref_sum_both[i - 1];
        }
        int left = k - i;
        if ((int) pref_sum_alice.size() < (k - i) || (int) pref_sum_bob.size() < (k - i))
            break;
        if (left > 0)
            option += pref_sum_alice[left - 1];
        if (left > 0)
            option += pref_sum_bob[left - 1];
        if (option > 0)
            ans = min(ans, option);
    }
    if (ans == LONG_LONG_MAX) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
    }
    return 0;
}