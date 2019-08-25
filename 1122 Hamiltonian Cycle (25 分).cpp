#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

#define MAX 201

bool graph[MAX][MAX] = { false };

bool check(vector<int> path, int n) {
	if (path.size() != n + 1 || path[0] != path[path.size() - 1])
		return false;
	set<int> appear;
	appear.insert(path[0]);
	for (int i = 0; i < path.size() - 1; i++) {
		if (graph[path[i]][path[i + 1]] == false)
			return false;
		appear.insert(path[i + 1]);
	}
	return appear.size() == n;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1][v2] = graph[v2][v1] = true;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		vector<int> path;
		int k;
		cin >> k;
		path.resize(k);
		for (int j = 0; j < k; j++) {
			cin >> path[j];
		}
		if (check(path, n))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}