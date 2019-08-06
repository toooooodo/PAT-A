#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 0X3FFFFFFF
#define MAX 500

int graph[MAX][MAX];
int team[MAX] = { 0 };
bool visited[MAX] = { false };
//dist->distance£»num->differenct shortest paths£»team_num->amount of teams gathering
int dist[MAX], num[MAX], team_num[MAX];

void dijkstra(int n, int start) {
	fill(dist, dist + MAX, INF);
	fill(num, num + MAX, 0);
	fill(team_num, team_num + MAX, 0);
	dist[start] = 0;
	num[start] = 1;
	team_num[start] = team[start];
	//visited[start] = true;
	for (int i = 0; i < n; i++) {
		int min = INF, min_index = -1;
		for (int i = 0; i < n; i++) {
			if (visited[i] == false && dist[i] < min) {
				min = dist[i];
				min_index = i;
			}
		}
		if (min_index == -1)
			return;
		// At first iteration, min_index=start
		visited[min_index] = true;
		for (int i = 0; i < n; i++) {
			if (visited[i] == false) {
				if (dist[min_index] + graph[i][min_index] < dist[i]) {
					dist[i] = dist[min_index] + graph[i][min_index];
					team_num[i] = team[i] + team_num[min_index];
					num[i] = num[min_index];
				}
				else if (dist[min_index] + graph[i][min_index] == dist[i]) {
					if (team_num[min_index] + team[i] > team_num[i]) {
						team_num[i] = team[i] + team_num[min_index];
					}
					num[i] += num[min_index];
				}
			}
		}
	}
}

int main() {
	int n, m, c1, c2;
	fill(graph[0], graph[0] + MAX * MAX, INF);
	cin >> n >> m >> c1 >> c2;
	for (int i = 0; i < n; i++) {
		cin >> team[i];
	}
	for (int i = 0; i < m; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		graph[a][b] = graph[b][a] = l;
	}
	dijkstra(n, c1);
	cout << num[c2] << " " << team_num[c2] << endl;
	return 0;
}