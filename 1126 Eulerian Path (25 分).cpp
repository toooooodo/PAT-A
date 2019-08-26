#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 501

vector<int> graph[MAX];
vector<int> degree;
bool visited[MAX] = { false };

bool connected(int root, int n) {
	queue<int> q;
	q.push(root);
	visited[root] = true;
	int count = 1;
	while (q.empty() == false) {
		int front = q.front();
		q.pop();
		for (int i = 0; i < graph[front].size(); i++) {
			if (visited[graph[front][i]] == false) {
				visited[graph[front][i]] = true;
				q.push(graph[front][i]);
				count++;
			}
		}
	}
	return count == n;
}

int main() {
	int n, m, odd = 0;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	for (int i = 1; i <= n; i++) {
		if (graph[i].size() % 2 != 0) {
			odd++;
		}
		degree.push_back(graph[i].size());
	}
	for (int i = 0; i < degree.size(); i++) {
		if (i == degree.size() - 1)
			cout << degree[i] << endl;
		else
			cout << degree[i] << " ";
	}
	if(connected(1,n)==false)
		cout << "Non-Eulerian" << endl;
	else if (odd == 0)
		cout << "Eulerian" << endl;
	else if (odd == 2)
		cout << "Semi-Eulerian" << endl;
	else
		cout << "Non-Eulerian" << endl;
	return 0;
}