#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 500
#define INF 0x3fffffff

int graph_dis[MAX][MAX], graph_cost[MAX][MAX];
bool visited[MAX];
int dist[MAX];
vector<int> pre[MAX];
vector<int> temp_path, final_path;

void dijkstra(int start, int n) {
	fill(visited, visited + MAX, false);
	fill(dist, dist + MAX, INF);
	//visited[start] = true;
	dist[start] = 0;
	for (int i = 0; i < n; i++) {
		int min_index = -1, min_value = INF;
		for (int j = 0; j < n; j++) {
			if (visited[j] == false && dist[j] < min_value) {
				min_value = dist[j];
				min_index = j;
			}
		}
		if (min_index == -1)
			return;
		visited[min_index] = true;
		for (int j = 0; j < n; j++) {
			if (visited[j] == false) {
				if (dist[min_index] + graph_dis[min_index][j] < dist[j]) {
					dist[j] = dist[min_index] + graph_dis[min_index][j];
					pre[j].clear();
					pre[j].push_back(min_index);
				}
				else if (dist[min_index] + graph_dis[min_index][j] == dist[j]) {
					pre[j].push_back(min_index);
				}
			}
		}
	}
}

void dfs(int start, int index, int &min_cost) {
	temp_path.push_back(index);
	if (index == start) {
		int temp_cost = 0;
		for (int i = 0; i < temp_path.size() - 1; i++) {
			int a = temp_path[i];
			int b = temp_path[i + 1];
			temp_cost += graph_cost[a][b];
		}
		if (temp_cost < min_cost) {
			min_cost = temp_cost;
			final_path = temp_path;
		}
	}
	else {
		for (int i = 0; i < pre[index].size(); i++) {
			dfs(start, pre[index][i], min_cost);
		}
	}
	temp_path.pop_back();
}

int main() {
	fill(graph_cost[0], graph_cost[0] + MAX * MAX, INF);
	fill(graph_dis[0], graph_dis[0] + MAX * MAX, INF);
	int n, m, s, d, min_cost = INF;
	cin >> n >> m >> s >> d;
	for (int i = 0; i < m; i++) {
		int c1, c2, _distance, _cost;
		cin >> c1 >> c2 >> _distance >> _cost;
		graph_dis[c1][c2] = graph_dis[c2][c1] = _distance;
		graph_cost[c1][c2] = graph_cost[c2][c1] = _cost;
	}
	dijkstra(s, n);
	dfs(s, d, min_cost);
	for (int i = final_path.size() - 1; i >= 0; i--) {
		cout << final_path[i] << " ";
	}
	cout << dist[d] << " " << min_cost << endl;
	return 0;
}