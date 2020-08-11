#include <bits/stdc++.h>

using namespace std;

long long f(long long n) {
	n += 1;
	while (n % 10 == 0) {
		n /= 10;
	}
	return n;
}

int main() {
	long long n = 0;
	cin >> n;
	set<long long> numbers;
	while(numbers.count(n) == 0){
		numbers.insert(n);
		n = f(n);
	}
	cout << numbers.size() << '\n';
	return 0;
}
