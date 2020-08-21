#include <bits/stdc++.h>

using namespace std;

int main() {
    string word1, word2;
    cin >> word1;
    cin >> word2;
    int n = min(word1.size(), word2.size());
    bool finish = false;
    int index = -1;
    for (int i = 0; i < n; i++) {
        if (isdigit(word1[i]) || isdigit(word2[i])) {
            index = i;
            break;
        }
        if (word1[i] - word2[i] < 0) {
            cout << "<\n";
            finish = true;
            break;
        }
        if (word1[i] - word2[i] > 0) {
            cout << ">\n";
            finish = true;
            break;
        }
    }
    bool finish2 = false;
    if (!finish) {
        if (word1.size() == word2.size()) {
            for (int i = index; i < n; i++) {
                if (word1[i] - word2[i] < 0) {
                    cout << "<\n";
                    finish2 = true;
                    break;
                }
                if (word1[i] - word2[i] > 0) {
                    cout << ">\n";
                    finish2 = true;
                    break;
                }
            }
        } else if (word1.size() < word2.size()) {
            cout << "<\n";
            finish2 = true;
        } else {
            cout << ">\n";
            finish2 = true;
        }
    }
    if (!finish && !finish2)
        cout << "=\n";
    return 0;
}