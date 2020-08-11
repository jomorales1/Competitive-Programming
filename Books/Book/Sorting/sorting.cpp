#include <bits/stdc++.h>

using namespace std;

void sort_vector(vector<int> &v) {
    sort(v.begin(), v.end());
}

void sort_array(int a[], int n) {
    sort(a, a + n);
}

void bubble_sort(vector<int> &elements) {
    int n = elements.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (elements[j] > elements[j + 1])
                swap(elements[j], elements[j + 1]);
        }
    }
}

void print_vector(vector<int> &v) {
    for (auto x : v) {
        cout << x << " ";
    }
    cout << "\n";
}

void print_array(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << '\n';
}

int main() {
    int n = 0;
    cin >> n;
    vector<int> elements(n);
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> elements[i];
        a[i] = elements[i] * 10;
    }
    sort_vector(elements);
    print_vector(elements);
    sort_array(a, n);
    print_array(a, n);
    return 0;
}