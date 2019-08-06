#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 1010
#define INF 0X3FFFFFFF

bool visited[MAX], graph[MAX][MAX] = { false };

int bfs(int start, int L, int n) {
	int num_layers = 0;
	int this_layer_num = 1;
	int count = 0;
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (q.empty() == false && num_layers++ < L) {
		int next_layer_num = 0;
		for (int i = 0; i < this_layer_num; i++) {
			int f = q.front();
			q.pop();
			for (int j = 1; j <= n; j++) {
				if (visited[j] == false && graph[f][j] == true) {
					visited[j] = true;
					q.push(j);
					count++;
					next_layer_num++;
				}
			}
		}
		this_layer_num = next_layer_num;
	}
	return count;
}

int main() {
	int n, l;
	cin >> n >> l;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < num; j++) {
			int user;
			cin >> user;
			graph[user][i] = true;
		}
	}
	int k;
	cin >> k;
	for (int i = 0; i < k; i++) {
		int start;
		cin >> start;
		fill(visited, visited + MAX, false);
		cout << bfs(start, l, n) << endl;
	}
	return 0;
}