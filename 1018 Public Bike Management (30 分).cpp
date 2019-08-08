#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 0X3FFFFFFF
#define MAX 501

int graph[MAX][MAX], dis[MAX], bike[MAX];
bool visited[MAX];
vector<int> pre[MAX];
vector<int> tmp_path, final_path;

void dijkstra(int index, int n) {
	fill(visited, visited + MAX, false);
	fill(dis, dis + MAX, INF);
	dis[index] = 0;
	for (int i = 0; i <= n; i++) {
		int min_index = -1, min_value = INF;
		for (int j = 0; j <= n; j++) {
			if (visited[j] == false && dis[j] < min_value) {
				min_value = dis[j];
				min_index = j;
			}
		}
		if (min_index == -1)
			return;
		visited[min_index] = true;
		for (int j = 0; j <= n; j++) {
			if (visited[j] == false) {
				if (dis[min_index] + graph[min_index][j] < dis[j]) {
					dis[j] = dis[min_index] + graph[min_index][j];
					pre[j].clear();
					pre[j].push_back(min_index);
				}
				else if (dis[min_index] + graph[min_index][j] == dis[j]) {
					pre[j].push_back(min_index);
				}
			}
		}
	}
}

void dfs(int index, int start, int &best_send, int &best_back, int perf) {
	tmp_path.push_back(index);
	if (index == start) {
		int send = 0, back = 0;
		// tmp_path是倒序的，最后一个是start。
		for (int i = tmp_path.size() - 2; i >= 0; i--) {
			int station = tmp_path[i];
			// 有盈余
			if (bike[station] - perf >= 0) {
				back += bike[station] - perf;
			}
			// 有亏损
			else {
				int need = perf - bike[station];
				if (need > back) {
					send += need - back;
					back = 0;
				}
				else {
					back -= need;
				}
			}
		}
		if (send < best_send || send == best_send && back < best_back) {
			best_send = send;
			best_back = back;
			final_path = tmp_path;
		}
	}
	else {
		for (int i = 0; i < pre[index].size(); i++) {
			dfs(pre[index][i], start, best_send, best_back, perf);
		}
	}
	tmp_path.pop_back();
}

int main() {
	int c, n, sp, m;
	int best_send = INF, best_back = INF;
	cin >> c >> n >> sp >> m;
	fill(graph[0], graph[0] + MAX * MAX, INF);
	for (int i = 1; i <= n; i++)
		cin >> bike[i];
	for (int i = 0; i < m; i++) {
		int s1, s2, t;
		cin >> s1 >> s2 >> t;
		graph[s1][s2] = graph[s2][s1] = t;
	}
	dijkstra(0, n);
	dfs(sp, 0, best_send, best_back, c / 2);
	cout << best_send << " ";
	for (int i = final_path.size() - 1; i >= 0; i--) {
		if (i == 0)
			cout << final_path[i];
		else
			cout << final_path[i] << "->";
	}
	cout << " " << best_back << endl;
	return 0;
}