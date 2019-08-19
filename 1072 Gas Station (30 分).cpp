#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

#define MAX 1011
#define INF 0x3fffffff

int graph[MAX][MAX], dis[MAX];
bool visited[MAX];

int get_id(string v, int n) {
	int times = 1, id = 0;
	for (int i = v.size() - 1; i >= 0 && v[i] != 'G'; i--) {
		id += times * (int)(v[i] - '0');
		times *= 10;
	}
	if (v[0] == 'G')
		id += n;
	return id;
}

void dijkstra(int s, int n) {
	fill(visited, visited + MAX, false);
	fill(dis, dis + MAX, INF);
	dis[s] = 0;
	for (int i = 0; i < n; i++) {
		int min_index = -1, min_dis = INF;
		for (int j = 1; j <= n; j++) {
			if (visited[j] == false && dis[j] < min_dis) {
				min_dis = dis[j];
				min_index = j;
			}
		}
		if (min_index == -1)
			return;
		visited[min_index] = true;
		for (int j = 1; j <= n; j++) {
			if (visited[j] == false) {
				if (dis[min_index] + graph[min_index][j] < dis[j])
					dis[j] = dis[min_index] + graph[min_index][j];
			}
		}
	}
}

int main() {
	int n, m, k, ds;
	cin >> n >> m >> k >> ds;
	fill(graph[0], graph[0] + MAX * MAX, INF);
	for (int i = 0; i < k; i++) {
		string v1, v2;
		int d;
		cin >> v1 >> v2 >> d;
		int id1 = get_id(v1, n);
		int id2 = get_id(v2, n);
		graph[id1][id2] = graph[id2][id1] = d;
	}
	int station_dis = -1, station = -1;
	double avg_dis = 10000000;
	for (int i = n + 1; i < m + n + 1; i++) {
		dijkstra(i, m + n);
		int min_dis = INF, sum = 0, max_dis = -1;
		for (int j = 1; j <= n; j++) {
			if (dis[j] < min_dis)
				min_dis = dis[j];
			if (dis[j] > max_dis)
				max_dis = dis[j];
			sum += dis[j];
		}
		if (max_dis > ds)
			continue;
		double avg = sum * 1.0 / n;
		if (min_dis > station_dis) {
			station = i;
			station_dis = min_dis;
			avg_dis = avg;
		}
		else if (min_dis == station_dis && avg < avg_dis) {
			station = i;
			avg_dis = avg;
		}
	}
	if (station == -1)
		cout << "No Solution" << endl;
	else {
		cout << "G" << station - n << endl;
		printf("%.1f %.1f\n", (float)station_dis, avg_dis);
	}
	return 0;
}