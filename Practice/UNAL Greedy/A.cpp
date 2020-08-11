#include <bits/stdc++.h>

using namespace std;

long long max_score(const vector<int>& numbers) {
    int n = numbers.size();
    long long score = 0;
    for (int i = 0; i < n; i++) {
        score += numbers[i];
    }
    long long total = score;
    int index = 0;
    while (index < n - 1) {
        score += total;
        total -= numbers[index];
        index++;
    }
    return score;
}

// SOLVED
int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end());
    long long score = max_score(numbers);
    cout << score << "\n";
    return 0;
}