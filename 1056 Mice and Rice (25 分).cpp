#include <iostream>
#include <queue>

using namespace std;

#define MAX 1000

struct record {
	int weight;
	int rank;
}records[MAX];
queue<int> q;

int main() {
	int n, ng;
	cin >> n >> ng;
	for (int i = 0; i < n; i++)
		cin >> records[i].weight;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		q.push(x);
	}
	while (q.size() != 1) {
		int n_groups, total = q.size();
		if (q.size() % ng == 0)
			n_groups = q.size() / ng;
		else
			n_groups = q.size() / ng + 1;
		for (int i = 0; i < n_groups; i++) {
			int max_index = q.front();
			records[max_index].rank = n_groups + 1;
			q.pop();
			for (int j = i * ng + 1; j < (i + 1)*ng&&j < total; j++) {
				int front = q.front();
				q.pop();
				records[front].rank = n_groups + 1;
				if (records[front].weight > records[max_index].weight) {
					max_index = front;
				}
			}
			q.push(max_index);
		}
	}
	int front = q.front();
	records[front].rank = 1;
	for (int i = 0; i < n; i++) {
		if (i == 0)
			cout << records[i].rank;
		else
			cout << " " << records[i].rank;
	}
	return 0;
}