#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000
bool graph[MAX][MAX] = { false };
bool visited[MAX];

void dfs(int v, int city, int n) {
	visited[v] = true;
	for (int i = 1; i <= n; i++) {
		if (i != city && graph[i][v] == true && visited[i] == false) {
			dfs(i, city, n);
		}
	}
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int c1, c2;
		cin >> c1 >> c2;
		graph[c1][c2] = graph[c2][c1] = true;
	}
	for (int i = 0; i < k; i++) {
		int city, count = 0;
		cin >> city;
		fill(visited + 1, visited + n + 1, false);
		for (int j = 1; j <= n; j++) {
			if (visited[j] == false && j != city) {
				dfs(j, city, n);
				count++;
			}
		}
		cout << count - 1 << endl;
	}
	return 0;
}