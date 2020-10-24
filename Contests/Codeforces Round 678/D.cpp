#include <bits/stdc++.h>

using namespace std;

const int N = (int) 2 * (1e5) + 1;
vector<int> adj[N];
vector<int> c(N);
vector<int> options;
bool visited[N];

void dfs(int s) {
    if (visited[s]) return;
    visited[s] = true;
    if (adj[s].size() == 0) {
        options.push_back(c[s]);
        return;
    }
    sort(adj[s].begin(), adj[s].end());
    int total = adj[s].size();
    int special = -1;
    int each = 0;
    if (c[s] % total != 0) {
        special = (c[s] / total) + (c[s] % total);
        each = c[s] / total;
    } else {
        each = c[s] / total;
    }
    if (special != -1) {
        c[adj[s].front()] += special;
    } else {
        c[adj[s].front()] += each;
    }
    int index = adj[s].front();
    int maximum = c[adj[s].front()];
    for (int i = 1; i < (int) adj[s].size(); i++) {
        c[adj[s][i]] += each;
        if (c[adj[s][i]] > maximum) {
            index = adj[s][i];
            maximum = c[adj[s][i]];
        }
    }
    dfs(index);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n = 0; cin >> n;
    int v;
    for (int u = 2; u <= n; u++) {
        cin >> v;
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    dfs(1);
    sort(options.rbegin(), options.rend());
    if (options.size() == 0) {
        cout << 0 << '\n';
        return 0;
    }
    cout << options[0] << '\n';
    return 0;
}