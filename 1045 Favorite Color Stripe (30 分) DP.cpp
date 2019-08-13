#include <iostream>
#include <algorithm>

using namespace std;

#define MAXM 201
#define MAXL 10001

int fav[MAXM], stripe[MAXL], dp[MAXM][MAXL];


int main() {
	int n, m, l, max_count = -1;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &fav[i]);
	}
	scanf("%d", &l);
	for (int i = 1; i <= l; i++) {
		scanf("%d", &stripe[i]);
	}
	for (int i = 0; i <= m; i++)
		dp[i][0] = 0;
	for (int i = 0; i <= l; i++)
		dp[0][i] = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= l; j++) {
			int MAX = max(dp[i - 1][j], dp[i][j - 1]);
			if (fav[i] == stripe[j])
				dp[i][j] = MAX + 1;
			else
				dp[i][j] = MAX;
		}
	}
	printf("%d", dp[m][l]);
	return 0;
}