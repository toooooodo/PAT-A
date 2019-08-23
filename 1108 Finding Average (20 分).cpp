#include <iostream>
#include <string>

using namespace std;

bool check(string x, double &number) {
	bool neg = false, dot = false;
	int integer = 0;
	double decimal = 0, times = 0.1;
	for (int i = 0; i < x.size(); i++) {
		if (x[i] == '-'&&i == 0) {
			neg = true;
		}
		else if (dot == true && x[i] == '.') {
			return false;
		}
		else if (x[i] == '.'&&i != 0) {
			dot = true;
		}
		else if (isdigit(x[i]) == false) {
			return false;
		}
		else {
			if (dot == false) {
				integer = integer * 10 + (int)(x[i] - '0');
				//if (integer > 1000)
				//	return false;
			}
			else {
				if (times < 0.01)
					return false;
				decimal += (int)(x[i] - '0')*times;
				times /= 10;
			}
		}
	}
	number = (double)integer + decimal;
	if (number > 1000)
		return false;
	if (neg)
		number = -number;
	return true;
}

int main() {
	int n, count = 0;
	double sum = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string x;
		double number;
		cin >> x;
		if (check(x, number)) {
			count++;
			sum += number;
		}
		else {
			printf("ERROR: %s is not a legal number\n", x.c_str());
		}
	}
	if (count == 0)
		cout << "The average of 0 numbers is Undefined" << endl;
	else if (count == 1)
		printf("The average of 1 number is %.2f\n", sum);
	else
		printf("The average of %d numbers is %.2f\n", count, sum / count);
	return 0;
}