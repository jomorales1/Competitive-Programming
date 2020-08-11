#include <bits/stdc++.h>

using namespace std;

struct P {
    int x, y;
    bool operator<(const P &p) {
        if (x != p.x) return x < p.x;
        else return y < p.y;
    }
};

bool comp(string a, string b) {
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

bool linear_search(int a) {

    return true;
}

bool binary_search(vector<int>& v, int a) {
    int n = v.size();
    sort(v.begin(), v.end());
    int l = 0;
    int r = n - 1;
    while (l <= r) {
        int k = (l + r) / 2;
        if (v[k] == a)
            return true;
        if (v[k] > a) {
            r = k - 1;
        } else {
            l = k + 1;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    // sort(numbers.begin(), numbers.end());
    for (auto x: numbers) {
        cout << x << " ";
    }
    cout << "\n";
    cout << (binary_search(numbers, 4) ? "YES" : "NO");
    string words[n];
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    sort(words, words + n, comp);
    for (int i = 0; i < n; i++) {
        cout << words[i] + " ";
    }
    cout << "\n";
    return 0;
}