#include <bits/stdc++.h>

using namespace std;

class line {
    private:
        double slope;
        double cut_point;
    public:
        line(pair<double, double> p1, pair<double, double> p2) {
            this->slope = (p2.second - p1.second) / (p2.first - p1.first);
            this->cut_point = p1.second - this->slope * p1.first;
        }
        bool up(pair<double, double> point) {
            double value = this->slope * point.first + this->cut_point;
            return value <= point.second;
        }
        bool down(pair<double, double> point) {
            double value = this->slope * point.first + this->cut_point;
            return value >= point.second;
        }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0); cout.tie(0);
    double n, d;
    cin >> n >> d;
    int m = 0; cin >> m;
    vector<pair<double, double>> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i].first;
        cin >> a[i].second;
    }
    line one({0.0, d}, {d, 0.0});
    line second({0.0, d}, {n - d, n});
    line third({n - d, n}, {n, n - d});
    line fourth({n, n - d}, {d, 0.0});
    for (auto point : a) {
        if (one.up(point) && third.down(point) && second.down(point) && fourth.up(point)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}