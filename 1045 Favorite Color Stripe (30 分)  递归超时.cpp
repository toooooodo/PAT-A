#include <iostream>
#include <algorithm>

using namespace std;

#define MAXM 201
#define MAXL 10000

int fav[MAXM], stripe[MAXL];

void choose(int fav_index, int stripe_index, int count, int &max_count, int m, int l) {
	if (fav_index == m || stripe_index == l)
		return;
	if (fav[fav_index] == stripe[stripe_index]) {
		count++;
		if (max_count < count) {
			max_count = count;
		}
		choose(fav_index, stripe_index + 1, count, max_count, m, l);
	}
	else {
		choose(fav_index + 1, stripe_index, count, max_count, m, l);
		choose(fav_index, stripe_index + 1, count, max_count, m, l);
	}
}

int main() {
	int n, m, l, max_count = -1;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &fav[i]);
	}
	scanf("%d", &l);
	for (int i = 0; i < l; i++) {
		scanf("%d", &stripe[i]);
	}
	choose(0, 0, 0, max_count, m, l);
	printf("%d\n", max_count);
	return 0;
}