#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100000

int numbers[MAX];

int main() {
	int n, sum1 = 0, sum2 = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> numbers[i];
	sort(numbers, numbers + n);
	for (int i = 0; i < n; i++) {
		if (i < n / 2)
			sum1 += numbers[i];
		else
			sum2 += numbers[i];
	}
	if (n % 2 == 0)
		cout << 0 << " " << sum2 - sum1;
	else
		cout << 1 << " " << sum2 - sum1;

	return 0;
}