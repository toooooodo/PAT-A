#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 10000

int numbers[MAX];

int main() {
	int n, len = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	sort(numbers, numbers + n);
	len = (numbers[0] + numbers[1]) / 2;
	for (int i = 2; i < n; i++)
		len = (len + numbers[i]) / 2;
	cout << len << endl;
	return 0;
}