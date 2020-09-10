#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin >> s;
    vector<vector<int>> matrix(10, vector<int>(10));
    int value = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == 0 && j == 0) {
                matrix[i][j] = -1;
                continue;
            }
            bool find = false;
            int operations = 0;
            for (int k = 1; k < s.length(); k++) {
                int digit = s[k] - '0';
                int start = value;
                value += digit;
                int target = value - start;
                if (target % __gcd(i, j) != 0) {
                    matrix[i][j] = -1;
                    break;
                }
                int maximum = max(i, j);
                int minimum = min(i, j);
                while (target > 0) {
                    if (target - minimum >= 0 && minimum > 0 && (target - minimum) % maximum != 0) {
                        target -= minimum;
                    } else {
                        target -= maximum;
                    }
                    operations++;
                }
                find = true;
            }
            if (find) {
                matrix[i][j] = operations;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}