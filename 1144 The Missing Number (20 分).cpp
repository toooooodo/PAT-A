#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100000

int numbers[MAX];

int main() {
	int n, cnt = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		if (x > 0)
			numbers[cnt++] = x;
	}
	sort(numbers, numbers + cnt);
	for (int i = 0; i < cnt; i++) {
		if (numbers[i] == numbers[i + 1] - 1 || numbers[i] == numbers[i + 1])
			continue;
		printf("%d", numbers[i] + 1);
		return 0;
	}
	printf("%d", numbers[cnt - 1] + 1);
	return 0;
}