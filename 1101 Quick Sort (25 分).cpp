#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100000

int numbers[MAX], left_to_right_max[MAX], right_to_left_min[MAX];
vector<int> pivot;

int main() {
	int n, _max = -1, _min = 0x7fffffff;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &numbers[i]);
	}
	for (int i = 0; i < n; i++) {
		if (numbers[i] > _max) {
			left_to_right_max[i] = numbers[i];
			_max = numbers[i];
		}
		else {
			left_to_right_max[i] = left_to_right_max[i - 1];
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		if (numbers[i] < _min) {
			right_to_left_min[i] = numbers[i];
			_min = numbers[i];
		}
		else
			right_to_left_min[i] = right_to_left_min[i - 1];
	}
	for (int i = 0; i < n; i++) {
		if (left_to_right_max[i] == right_to_left_min[i])
			pivot.push_back(left_to_right_max[i]);
	}
	sort(pivot.begin(), pivot.end());
	printf("%d\n", pivot.size());
	if (pivot.size() != 0) {
		for (int i = 0; i < pivot.size(); i++) {
			if (i == 0)
				printf("%d", pivot[i]);
			else
				printf(" %d", pivot[i]);
		}
	}
	putchar('\n');
	return 0;
}