#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 0; cin >> n;
    vector<int> spheres(n);
    for (int i = 0; i < n; i++) {
        cin >> spheres[i];
    }
    sort(spheres.begin(), spheres.end());
    vector<int> result(n);
    int index = 1;
    for (int i = 0; i < n / 2; i++) {
        result[index] = spheres[i];
        index += 2;
    }
    index = 0;
    for (int i = n / 2; i < n; i++) {
        result[index] = spheres[i];
        index += 2;
    }
    int count = 0;
    for (int i = 1; i < n - 1; i++) {
        if (result[i] < result[i - 1] && result[i] < result[i + 1])
            count++;
    }
    cout << count << '\n';
    for (int i = 0; i < n; i++) {
        cout << result[i] << ' ';
    }
    cout << '\n';
    return 0;
}