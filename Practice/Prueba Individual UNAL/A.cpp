#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n = 0;
    cin >> n;
    unordered_map<int, int> planks;
    int length = 0;
    for (int i = 0; i < n; i++) {
        cin >> length;
        planks[length]++;
    }
    int q = 0;
    cin >> q;
    char option;
    int x = 0;
    bool square = false, rect = false;
    for (int i = 0; i < q; i++) {
        cin >> option;
        cin >> x;
        if (option == '+')
            planks[x]++;
        else
            planks[x]--;
        int chosen = -1;
        for (auto &plank : planks) {
            if (plank.second >= 4) {
                square = true; chosen = plank.first;
                planks[chosen] -= 4;
                break;
            }
        }
        if (square) {
            int a = -1, b = -1;
            for (const auto &plank : planks) {
                if (plank.second >= 4) {
                    rect = true;
                    break;
                }
                if (plank.second >= 2 && a == -1)
                    a = plank.first;
                if (plank.second >= 2 && a != -1 && a != plank.first && b == -1) {
                    b = plank.first;
                    rect = true;
                    break;
                }
            }
            planks[chosen] += 4;
        }
        cout << (square && rect ? "YES" : "NO") << '\n';
        square = false; rect = false;
    }
}

void solve2() {
    int n = 0;
    cin >> n;
    vector<int> planks(n);
    for (int i = 0; i < n; i++) {
        cin >> planks[i];
    }
    sort(planks.rbegin(), planks.rend());
    map<int, int> ocurrences;
    for (auto plank : planks) {
        ocurrences[plank]++;
    }
    int q = 0;
    cin >> q;
    char option;
    int x = 0;
    bool square = false, rect = false;
    for (int i = 0; i < q; i++) {
        cin >> option;
        cin >> x;
        if (option == '+')
            ocurrences[x]++;
        else
            ocurrences[x]--;
        int chosen = -1;
        int a = -1;
        for (auto &o : ocurrences) {
            if (o.second >= 4 && !square) {
                square = true; chosen = o.first;
                ocurrences[chosen] -= 4;
            }
            if (o.second >= 4 && chosen != -1) {
                rect = true;
                break;
            }
            if (o.second >= 2 && a == -1) {
                a = o.first;
                ocurrences[o.first] -= 2;
            }
            if (o.second >= 2 && a != -1) {
                rect = true;
            }
        }
        if (chosen != -1)
            ocurrences[chosen] += 4;
        if (a != -1)
            ocurrences[a] += 2;
        cout << (square && rect ? "YES" : "NO") << '\n';
        square = false; rect = false;
    }
}

bool compare(pair<int, int> &a, pair<int, int> &b) {
    return a.second >= b.second;
}

bool compare2(pair<int, int> &a, pair<int, int> &b) {
    return a.first < b.first;
}

int contains(vector<pair<int,int>> &planks, int plank) {
    sort(planks.begin(), planks.end(), compare2);
    int l = 0;
    int r = planks.size() - 1;
    while (l <= r) {
        int k = (l + r) / 2;
        if (planks[k].first == plank)
            return k;
        if (planks[k].first > plank)
            r = k - 1;
        else
            l = k + 1;
    }
    return -1;
}

void solve3() {
    int n = 0;
    cin >> n;
    vector<pair<int, int>> planks;
    int plank;
    int pos = -1;
    for (int i = 0; i < n; i++) {
        cin >> plank;
        pos = contains(planks, plank);
        if (pos != -1)
            planks[pos].second++;
        else
            planks.push_back({plank, 1});
    }
    int q = 0;
    cin >> q;
    char option;
    int x;
    for (int i = 0; i < q; i++) {
        cin >> option;
        cin >> x;
        int index = contains(planks, x);
        int change = 0;
        if (option == '+')
            change = 1;
        else
            change = -1;
        if (index != -1) {
            planks[index].second += change;
        } else {
            planks.push_back({x, 1});
        }
        sort(planks.begin(), planks.end(), compare);
        bool s = false;
        bool first = false, sec = false;
        if (planks[0].second >= 4) {
            int ocurrences = -1;
            if (planks[0].second - 4 >= 4) {
                cout << "YES\n";
                continue;
            }
            if (planks[0].second - 4 >= 2)
                first = true;
            for (int k = 1; k < planks.size(); k++) {
                if (planks[k].first == 0 || planks[k].second < 2)
                    break;
                ocurrences = planks[k].second;
                if (ocurrences >= 4) {
                    s = true;
                    cout << "YES\n";
                    break; 
                } else if (ocurrences >= 2){
                    if (first) {
                        sec = true;
                        cout << "YES\n";
                        break;
                    } else {
                        first = true;
                    }
                }
            }
        } else {
            /*for (auto &x : planks) {
                if (x.first != 0)
                    cout << x.first << " " << x.second << '\n';
            }*/
            cout << "NO\n";
            //sort(planks.begin(), planks.end(), compare);
            continue;
        }
        /*for (auto &x : planks) {
            if (x.first != 0)
                cout << x.first << " " << x.second << '\n';
        }*/
        if (!s && !sec)
            cout << "NO\n";
    }
}

bool check(vector<pair<int, int>> &planks, int k) {
    if (k == 0) {
        if (planks[k].second - 4 >= 2 && planks[k + 1].second >= 2)
            return true;
    } else if (k == planks.size() - 1) {
        if (planks[k].second >= 2 && planks[k - 1].second >= 2)
            return true;
    } else {
        int aux = 0;
        if (k == 1)
            aux = 4;
        if (planks[k - 1].second - aux >= 2 || planks[k + 1].second >= 2)
            return true;
    }
    return false;
}

int search_two(vector<pair<int, int>> &planks) {
    int l = 1;
    int r = planks.size() - 1;
    while (l <= r) {
        int k = (l + r) / 2;
        if (planks[k].second >= 4)
            return 4;
        else
            r = k - 1;
    }
    l = 0;
    r = planks.size() - 1;
    if (r == 1) {
        if (planks[0].second - 4 >= 2 && planks[1].second >= 2)
            return 2;
        return -1;
    }
    while (l <= r) {
        int k = (l + r) / 2;
        if (planks[k].second >= 2 && check(planks, k))
            return 2;
        else
            r = k - 1;
    }
    return -1;
}
 
void solve4() {
    int n = 0;
    cin >> n;
    vector<pair<int, int>> planks;
    int plank;
    int pos = -1;
    for (int i = 0; i < n; i++) {
        cin >> plank;
        pos = contains(planks, plank);
        if (pos != -1)
            planks[pos].second++;
        else
            planks.push_back({plank, 1});
    }
    int q = 0;
    cin >> q;
    char option;
    int x;
    for (int i = 0; i < q; i++) {
        cin >> option;
        cin >> x;
        int index = contains(planks, x);
        int change = 0;
        if (option == '+')
            change = 1;
        else
            change = -1;
        if (index != -1) {
            planks[index].second += change;
        } else {
            planks.push_back({x, 1});
        }
        sort(planks.begin(), planks.end(), compare);
        if (planks[0].second >= 4) {
            if (planks[0].second - 4 >= 4) {
                cout << "YES\n";
                continue;
            }
            int res = search_two(planks);
            if (res == 4 || res == 2) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        } else {
            /*for (auto &x : planks) {
                if (x.first != 0)
                    cout << x.first << " " << x.second << '\n';
            }*/
            cout << "NO\n";
            //sort(planks.begin(), planks.end(), compare);
        }
        /*for (auto &x : planks) {
            if (x.first != 0)
                cout << x.first << " " << x.second << '\n';
        }*/
    }
}

int main() {
    solve4();
    return 0;
}