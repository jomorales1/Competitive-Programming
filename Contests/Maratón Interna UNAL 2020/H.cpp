#include <bits/stdc++.h>

using namespace std;

bool check_palindrome(string word) {
    int n = word.length();
    for (int i = 0; i < n; i++) {
        if (word[i] != word[n - i - 1])
            return false;
    }
    return true;
}

bool check_key(unordered_map<string, int> &palindromes, string key) {
    return palindromes.find(key) != palindromes.end();
}

long long count_odd(string word) {
    long long res = 0;
    unordered_map<string, int> palindromes;
    int n = word.length();
    for (int i = 0; i < n; i++) {
        string x = "";
        for (int j = i; j < n; j++) {
            x += word[i];
            if (x.length() >= 3 && x.length() % 2 != 0 && check_palindrome(x)) {
                if (!check_key(palindromes, x)) {
                    palindromes[x]++;
                    res++;
                }
            }
        }
    }
    return res;
}

int main() {
    int n = 0;
    cin >> n;
    string word;
    cin >> word;
    cout << count_odd(word) << '\n';
    return 0;
}