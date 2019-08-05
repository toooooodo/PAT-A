#include <iostream>
using namespace std;

int main() {
	int n, total_time = 0, loc = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		total_time += 5;
		if (x < loc) {
			total_time += (loc - x) * 4;
		}
		else if (x > loc) {
			total_time += (x - loc) * 6;
		}
		loc = x;
	}
	cout << total_time << endl;
	return 0;
}