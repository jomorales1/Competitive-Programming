#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0; cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    vector<int> positives;
    vector<int> negatives;
    vector<int> result(n);
    int status;
    for (int i = 0; i < n; i++) {
        cin >> status;
        if (status == 1) {
            result[i] = numbers[i];
        } else {
            result[i] = INT_MAX;
            if (numbers[i] >= 0) {
                positives.push_back(numbers[i]);
            } else {
                negatives.push_back(numbers[i]);
            }
        }
    }
    if (positives.size() > 0)
        sort(positives.begin(), positives.end());
    if (negatives.size() > 0)
        sort(negatives.rbegin(), negatives.rend());
    if (negatives.empty() && !positives.empty()) {
        int index = (int) positives.size() - 1;
        for (int i = 0; i < n; i++) {
            if (result[i] == INT_MAX) {
                result[i] = positives[index];
                index--;
            }
        }
    } else if (!negatives.empty() && positives.empty()) {
        int index = (int) negatives.size() - 1;
        for (int i = 0; i < n; i++) {
            if (result[i] == INT_MAX) {
                result[i] = negatives[index];
                index--;
            }
        }
    } else if (!negatives.empty() && !positives.empty()) {
        int moves = 0;
        for (int i = 0; i < n; i++) {
            if (result[i] == INT_MAX) {
                if (moves % 2 == 0 && !negatives.empty()) {
                    result[i] = negatives.back();
                    negatives.pop_back();
                    moves++;
                } else if (moves % 2 != 0 && !positives.empty()) {
                    result[i] = positives.back();
                    positives.pop_back();
                    moves++;
                } else if (negatives.empty() && !positives.empty()) {
                    result[i] = positives.back();
                    positives.pop_back();
                } else if (positives.empty() && !negatives.empty()) {
                    result[i] = negatives.back();
                    negatives.pop_back();
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << result[i] << ' ';
    }
    cout << '\n';
}

void solve2() {
    int n = 0; cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    vector<int> status(n);
    vector<int> to_place;
    for (int i = 0; i < n; i++) {
        cin >> status[i];
        if (status[i] == 0) {
            to_place.push_back(numbers[i]);
        }
    }
    if (to_place.size() > 0)
        sort(to_place.begin(), to_place.end());
    for (int i = 0; i < n; i++) {
        if (status[i] == 1) {
            cout << numbers[i] << ' ';
        } else {
            cout << to_place.back() << ' ';
            to_place.pop_back();
        }
    }
    cout << '\n';
}

int main() {
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve2();
    }
    return 0;
}