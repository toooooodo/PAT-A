#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100001

int dis[MAX];

int main() {
	int n, m;
	scanf("%d", &n);
	dis[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &dis[i]);
		dis[i] += dis[i - 1];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int begin, end;
		scanf("%d %d", &begin, &end);
		if (begin > end)
			swap(begin, end);
		printf("%d\n", min(dis[end - 1] - dis[begin - 1], dis[n] - dis[end - 1] + dis[begin - 1] - dis[0]));
	}
	return 0;
}