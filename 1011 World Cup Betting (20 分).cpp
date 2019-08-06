#include <iostream>
#include <algorithm>
using namespace std;

double matrix[3][3];

void get_max(int &index, double &_max, double arr[]) {
	for (int i = 1; i < 3; i++) {
		if (arr[i] > _max) {
			index = i;
			_max = arr[i];
		}
	}
}
int main() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> matrix[i][j];
		}
	}
	double product = 1;
	for (int i = 0; i < 3; i++) {
		int index = 0;
		double _max = matrix[i][0];
		get_max(index, _max, matrix[i]);
		product *= _max;
		if (index == 0)
			cout << "W ";
		else if (index == 1)
			cout << "T ";
		else
			cout << "L ";
	}
	printf("%.2f\n", (0.65*product - 1) * 2);
	return 0;
}