    #include <bits/stdc++.h>
     
    using namespace std;
     
    int main() {
        int n = 0; cin >> n;
        string s; cin >> s;
        int count = 0;
        int balance = 0;
        int op = 0;
        int close = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                balance++;
                op++;
            } else {
                if (balance > 0) {
                    balance--;
                } else {
                    count++;
                }
                close++;
            }
            if (count > 1) {
                cout << "No\n";
                return 0;
            }
        }
        if (op == close) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
        return 0;
    }