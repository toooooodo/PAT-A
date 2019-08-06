#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 500
#define INF 0X3FFFFFFF

int graph_distance[MAX][MAX], graph_cost[MAX][MAX];
int cost[MAX], dis[MAX], pre[MAX];
bool visited[MAX];

void dijkstra(int n, int start)
{
	fill(cost, cost + MAX, INF);
	fill(dis, dis + MAX, INF);
	fill(visited, visited + MAX, false);
	for (int i = 0; i < n; i++) {
		pre[i] = i;
	}
	cost[start] = 0;
	dis[start] = 0;
	for (int i = 0; i < n; i++) {
		int min_index = -1, min_dist = INF;
		for (int j = 0; j < n; j++) {
			if (visited[j] == false && dis[j] < min_dist) {
				min_dist = dis[j];
				min_index = j;
			}
		}
		if (min_index == -1)
			return;
		visited[min_index] = true;
		for (int j = 0; j < n; j++) {
			if (visited[j] == false) {
				if (dis[min_index] + graph_distance[min_index][j] < dis[j]) {
					dis[j] = dis[min_index] + graph_distance[min_index][j];
					cost[j] = cost[min_index] + graph_cost[min_index][j];
					pre[j] = min_index;
				}
				else if (dis[min_index] + graph_distance[min_index][j] == dis[j]) {
					if (cost[min_index] + graph_cost[min_index][j] < cost[j]) {
						cost[j] = cost[min_index] + graph_cost[min_index][j];
						pre[j] = min_index;
					}
				}
			}
		}
	}
}

void print_path(int x) {
	if (pre[x] == x) {
		cout << x << " ";
		return;
	}
	print_path(pre[x]);
	cout << x << " ";
}

int main() {
	fill(graph_distance[0], graph_distance[0] + MAX * MAX, INF);
	fill(graph_cost[0], graph_cost[0] + MAX * MAX, INF);
	int n, m, s, d;
	cin >> n >> m >> s >> d;
	for (int i = 0; i < m; i++) {
		int c1, c2, _distance, _cost;
		cin >> c1 >> c2 >> _distance >> _cost;
		graph_distance[c1][c2] = graph_distance[c2][c1] = _distance;
		graph_cost[c1][c2] = graph_cost[c2][c1] = _cost;
	}
	dijkstra(n, s);
	print_path(d);
	cout << dis[d] << " " << cost[d];
	return 0;
}