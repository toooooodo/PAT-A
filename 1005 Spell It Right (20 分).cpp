#include <iostream>
#include <string>
#include <vector>
using namespace std;

string number[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
vector<string>result;

int main() {
	string n;
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n.size(); i++) {
		sum += (n[i] - '0');
	}
	if (sum == 0)
		cout << number[0] << endl;
	else {
		while (sum != 0) {
			int digit = sum % 10;
			sum /= 10;
			result.push_back(number[digit]);
		}
		for (int i = result.size() - 1; i >= 0; i--) {
			if (i == 0)
				cout << result[i] << endl;
			else
				cout << result[i] << " ";
		}
	}
	return 0;
}