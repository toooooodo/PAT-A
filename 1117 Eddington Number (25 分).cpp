#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100000

int numbers[MAX];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int n, e = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> numbers[i];
	sort(numbers, numbers + n, cmp);
	for (int i = 0; i < n; i++) {
		if (numbers[i] > i + 1)
			e++;
		else
			break;
	}
	cout << e << endl;
	return 0;
}