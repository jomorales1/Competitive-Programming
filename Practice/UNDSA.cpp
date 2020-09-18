#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> numbers(n);
    map<int, int> frequencies;
    set<int> elements;
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
        frequencies[numbers[i]]++;
        elements.insert(numbers[i]);
    }
    vector<int> positions(m);
    for (int i = 0; i < m; i++) {
        cin >> positions[i];
    }
    vector<int> pref(n);
    for (int i = n - 1; i >= 0; i--) {
        pref[n - (i + 1)] = elements.size();
        frequencies[numbers[n - (i + 1)]]--;
        if (frequencies[numbers[n - (i + 1)]] == 0)
            elements.erase(numbers[n - (i + 1)]);
    }
    for (int i = 0; i < m; i++) {
        cout << pref[positions[i] - 1] << '\n';
    }
    return 0;
}