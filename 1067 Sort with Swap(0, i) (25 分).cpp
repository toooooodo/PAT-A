#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100000

int pos[MAX];

int main() {
	int n, count = 0, k = 1;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		pos[x] = i;
	}
	while (true) {
		if (pos[0] != 0) {
			count++;
			swap(pos[0], pos[pos[0]]);
		}
		else {
			while (k < n) {
				if (pos[k] != k) {
					swap(pos[0], pos[k]);
					count++;
					break;
				}
				k++;
			}
			if (k == n)
				break;
		}
	}
	printf("%d\n", count);
	return 0;
}