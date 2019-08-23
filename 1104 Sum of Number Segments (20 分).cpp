#include <iostream>

using namespace std;

#define MAX 100000

double num[MAX];
double number[MAX];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> number[i];
	for (int i = 0; i < n; i++) {
		num[i] = 1.0*(n - i)*(i + 1);
	}
	double sum = 0;
	for (int i = 0; i < n; i++)
		//sum = sum + num[i] * number[i];
		sum += (num[i] * number[i]);
	printf("%.2f", sum);
	return 0;
}