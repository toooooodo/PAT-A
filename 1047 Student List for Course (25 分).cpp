#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXK 2501
#define MAXN 40000

vector<int> course[MAXK];
char name[MAXN][5];

bool cmp(int a, int b) {
	return strcmp(name[a], name[b]) < 0;
}

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int num;
		scanf("%s %d", name[i], &num);
		for (int j = 0; j < num; j++) {
			int c;
			scanf("%d", &c);
			course[c].push_back(i);
		}
	}
	for (int i = 1; i <= k; i++) {
		printf("%d %d\n", i, course[i].size());
		sort(course[i].begin(), course[i].end(), cmp);
		for (int j = 0; j < course[i].size(); j++) {
			printf("%s\n", name[course[i][j]]);
		}
	}
	return 0;
}