#include <iostream>

using namespace std;

int main() {
	int n;
	double sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		double num;
		cin >> num;
		sum += num * (i + 1)*(n - i);
	}
	printf("%.2f\n", sum);
	return 0;
}