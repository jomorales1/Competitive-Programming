#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int minutes = 0;
    int which = -1;
    if (a < b) which = 1;
    else which = 2;
    while (a >= 1 && b >= 1) {
        if (which == 1) {
            a += 1;
            b -= 2;
            if (b <= 2) {
                which = 2;
            }
            if (b < 0) break;
        } else {
            b += 1;
            a -= 2;
            if (a <= 2) {
                which = 1;
            }
            if (a < 0) break;
        }
        minutes++;
    }
    cout << minutes << '\n';
    return 0;
}