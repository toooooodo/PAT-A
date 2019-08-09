#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 10010

vector<int>graph[MAX];
bool visited[MAX];
int father[MAX];
vector<int>root;

int bfs(int start, int n) {
	fill(visited, visited + MAX, false);
	queue<int> q;
	q.push(start);
	visited[start] = true;
	int this_layer = 1, layer_count = 0;
	while (q.empty() == false) {
		int next_layer = 0;
		for (int i = 0; i < this_layer; i++) {
			int front = q.front();
			q.pop();
			for (int j = 0; j < graph[front].size(); j++) {
				if (visited[graph[front][j]] == false) {
					q.push(graph[front][j]);
					visited[graph[front][j]] = true;
					next_layer++;
				}
			}
		}
		this_layer = next_layer;
		layer_count++;
	}
	return layer_count;
}

int find_father(int x) {
	if (x == father[x])
		return x;
	int f = find_father(father[x]);
	father[x] = f;
	return f;
}

void union_(int a, int b) {
	int a_f = find_father(a);
	int b_f = find_father(b);
	if (a_f != b_f)
		father[a_f] = b_f;
}

int main() {
	int n, max_layer = -1, components = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		father[i] = i;
	for (int i = 0; i < n - 1; i++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
		union_(v1, v2);
	}
	for (int i = 1; i <= n; i++) {
		if (father[i] == i)
			components += 1;
	}
	if (components > 1)
		printf("Error: %d components\n", components);
	else {
		for (int i = 1; i <= n; i++) {
			int layer = bfs(i, n);
			if (layer > max_layer) {
				root.clear();
				root.push_back(i);
				max_layer = layer;
			}
			else if (layer == max_layer) {
				root.push_back(i);
			}
		}
		for (int i = 0; i < root.size(); i++) {
			printf("%d\n", root[i]);
		}
	}
	return 0;
}