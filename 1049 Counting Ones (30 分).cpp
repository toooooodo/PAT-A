#include <iostream>

using namespace std;

int main() {
	int n, num = 0, time = 1;
	cin >> n;
	while (n / time != 0) {
		int left = n / (time * 10);
		int right = n % time;
		int mid = n / time % 10;
		if (mid == 0)
			num += left * time;
		else if (mid == 1)
			num += left * time + right + 1;
		else
			num += (left + 1)*time;
		time *= 10;
	}
	cout << num << endl;
	return 0;
}