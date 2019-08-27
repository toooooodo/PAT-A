#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 10000

bool visited[MAX][MAX];
vector<int> graph[MAX];

bool check(int n, int m, vector<int> vertex) {
	fill(visited[0], visited[0] + MAX * MAX, false);
	int cnt = 0;
	for (int i = 0; i < vertex.size(); i++) {
		int v = vertex[i];
		for (int j = 0; j < graph[v].size(); j++) {
			if (visited[v][graph[v][j]] == false) {
				cnt++;
				visited[v][graph[v][j]] = visited[graph[v][j]][v] = true;
			}
		}
	}
	return cnt == m;
}

int main() {
	int n, m, k;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		vector<int> vertex;
		int nv;
		cin >> nv;
		for (int j = 0; j < nv; j++) {
			int v;
			cin >> v;
			vertex.push_back(v);
		}
		if (check(n, m, vertex))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}