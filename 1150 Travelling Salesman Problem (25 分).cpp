#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 210
#define INF 0x3fffffff

int graph[MAX][MAX];

int check(vector<int> &path, int &dis, int n) {
	// 0: not a cycle; 1: simple cycle; 2: cycle
	int v1 = path[0], v2;
	vector<bool>visited(n + 1, false);
	visited[v1] = true;
	for (int i = 1; i < path.size(); i++) {
		v2 = path[i];
		visited[v2] = true;
		if (graph[v1][v2] == INF) {
			dis = INF;
			return 0;
		}
		else {
			dis += graph[v1][v2];
		}
		v1 = v2;
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i] == false) {
			return 0;
		}
	}
	if (path[0] != path[path.size() - 1])
		return 0;
	else if (path.size() != n + 1)
		return 2;
	else
		return 1;
}

int main() {
	fill(graph[0], graph[0] + MAX * MAX, INF);
	int n, m, k;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int v1, v2, dis;
		cin >> v1 >> v2 >> dis;
		graph[v1][v2] = graph[v2][v1] = dis;
	}
	cin >> k;
	int min_index, min_dis = INF;
	for (int i = 0; i < k; i++) {
		int num, dis = 0;
		cin >> num;
		vector<int> path(num);
		for (int j = 0; j < num; j++)
			cin >> path[j];
		int flg = check(path, dis, n);
		if (flg == 0) {
			// Path 5: 3 (Not a TS cycle)
			if (dis == INF)
				printf("Path %d: NA (Not a TS cycle)\n", i + 1);
			else
				printf("Path %d: %d (Not a TS cycle)\n", i + 1, dis);
		}
		else {
			if (flg == 2)
				// Path 4: 8 (TS cycle)
				printf("Path %d: %d (TS cycle)\n", i + 1, dis);
			else
				printf("Path %d: %d (TS simple cycle)\n", i + 1, dis);
			if (dis < min_dis) {
				min_dis = dis;
				min_index = i + 1;
			}
		}
	}
	printf("Shortest Dist(%d) = %d\n", min_index, min_dis);
	return 0;
}