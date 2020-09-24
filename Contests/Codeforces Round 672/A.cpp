#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0; cin >> n;
    vector<int> cubes(n);
    vector<int> numbers(n);
    map<int, int> positions;
    for (int i = 0; i < n; i++) {
        cin >> cubes[i];
        numbers[i] = cubes[i];
        positions[cubes[i]] = i;
    }
    sort(numbers.begin(), numbers.end());
    long long operations = 0, last_pos = -1, sorted = 0;
    for (int i = 0; i < n; i++) {
        if (numbers[i] != cubes[i]) {
            if (last_pos == -1) {
                operations += positions[numbers[i]];
                last_pos = positions[numbers[i]];
            } else {
                if (positions[numbers[i]] < last_pos) {
                    operations += positions[numbers[i]];
                } else {
                    operations += abs(positions[numbers[i]] - i);
                    last_pos = positions[numbers[i]];
                }
            }
            sorted++;
        } else {
            if (positions[numbers[i]] + sorted != i)
                operations += abs(positions[numbers[i]] + sorted - i);
        }
    }
    long long limit = (long long) (n * (n - 1) / 2) - 1;
    if (operations <= limit) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    int t = 0; cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
    return 0;
}