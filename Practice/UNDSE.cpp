#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> id_s(n);
    for (int i = 0; i < n; i++) {
        cin >> id_s[i];
    }
    list<int> messages;
    map<int, bool> frequencies;
    for (int i = 0; i < n; i++) {
        if (messages.size() < k) {
            if (!frequencies[id_s[i]]) {
                frequencies[id_s[i]] = true;
                messages.push_back(id_s[i]);
            }
        } else if (!frequencies[id_s[i]]) {
            frequencies[messages.front()] = false;
            messages.pop_front();
            frequencies[id_s[i]] = true;
            messages.push_back(id_s[i]);
        }
    }
    cout << (int) messages.size() << '\n';
    while (!messages.empty()) {
        cout << messages.back() << ' ';
        messages.pop_back();
    }
    cout << '\n';
    return 0;
}