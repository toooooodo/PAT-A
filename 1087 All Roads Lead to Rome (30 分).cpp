#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

#define MAX 200
#define INF 0X3FFFFFFF

map<string, int> name_to_index;
string names[MAX];
int graph[MAX][MAX], dis[MAX], path_count[MAX], happi[MAX] = { 0 };
bool visited[MAX];
vector<int> tmp, result;
vector<int> pre[MAX];

void dijkstra(int start, int n) {
	fill(visited, visited + MAX, false);
	fill(dis, dis + MAX, INF);
	fill(path_count, path_count + MAX, 0);
	dis[start] = 0;
	path_count[start] = 1;
	for (int i = 0; i < n; i++) {
		int min_index = -1, min_dis = INF;
		for (int j = 0; j < n; j++) {
			if (visited[j] == false && dis[j] < min_dis) {
				min_dis = dis[j];
				min_index = j;
			}
		}
		if (min_index == -1)
			break;
		visited[min_index] = true;
		for (int j = 0; j < n; j++) {
			if (visited[j] == false) {
				if (dis[min_index] + graph[min_index][j] < dis[j]) {
					pre[j].clear();
					pre[j].push_back(min_index);
					dis[j] = dis[min_index] + graph[min_index][j];
					path_count[j] = path_count[min_index];
				}
				else if (dis[min_index] + graph[min_index][j] == dis[j]) {
					pre[j].push_back(min_index);
					path_count[j] += path_count[min_index];
				}
			}
		}
	}
}

void dfs(int index, int start, int &total_happi, int &avg_happi) {
	tmp.push_back(index);
	if (index == start) {
		int happi_sum = 0, num = 0, avg;
		for (int i = 0; i < tmp.size(); i++) {
			happi_sum += happi[tmp[i]];
		}
		avg = happi_sum / (tmp.size() - 1);
		if (happi_sum > total_happi) {
			total_happi = happi_sum;
			avg_happi = avg;
			result = tmp;
		}
		else if (happi_sum == total_happi && avg > avg_happi) {
			result = tmp;
			avg_happi = avg;
		}
	}
	else {
		for (int i = 0; i < pre[index].size(); i++) {
			dfs(pre[index][i], start, total_happi, avg_happi);
		}
	}
	tmp.pop_back();
}

int main() {
	int n, k, end, total_happi = -1, avg_happi = -1;
	cin >> n >> k >> names[0];
	name_to_index[names[0]] = 0;
	fill(graph[0], graph[0] + MAX * MAX, INF);
	for (int i = 1; i < n; i++) {
		cin >> names[i] >> happi[i];
		name_to_index[names[i]] = i;
		if (names[i] == "ROM")
			end = i;
	}
	for (int i = 0; i < k; i++) {
		string c1, c2;
		int cost;
		cin >> c1 >> c2 >> cost;
		int c1_index = name_to_index[c1];
		int c2_index = name_to_index[c2];
		graph[c1_index][c2_index] = graph[c2_index][c1_index] = cost;
	}
	dijkstra(0, n);
	dfs(end, 0, total_happi, avg_happi);
	printf("%d %d %d %d\n", path_count[end], dis[end], total_happi, avg_happi);
	for (int i = result.size() - 1; i >= 0; i--) {
		if (i == 0) {
			printf("%s\n", names[result[i]].c_str());
		}
		else {
			printf("%s->", names[result[i]].c_str());
		}
	}
	return 0;
}