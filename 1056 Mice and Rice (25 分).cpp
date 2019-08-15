#include <iostream>
#include <queue>

using namespace std;

#define MAX 1000

struct mouse {
	int rank;
	int weight;
}mice[MAX];

int main() {
	int np, ng;
	queue<int> q;
	cin >> np >> ng;
	for (int i = 0; i < np; i++)
		cin >> mice[i].weight;
	for (int i = 0; i < np; i++) {
		int per;
		cin >> per;
		q.push(per);
	}
	int now = np, group_num;
	while (q.size() != 1) {
		if (now%ng == 0)
			group_num = now / ng;
		else
			group_num = now / ng + 1;
		for (int i = 0; i < group_num; i++) {
			int max_index = q.front();
			q.pop();
			mice[max_index].rank = group_num + 1;
			for (int j = 1; j < ng; j++) {
				if (i*ng + j == now)
					break;
				int front = q.front();
				q.pop();
				if (mice[max_index].weight < mice[front].weight) {
					max_index = front;
				}
				mice[front].rank = group_num + 1;
			}
			q.push(max_index);
		}
		now = group_num;
	}
	mice[q.front()].rank = 1;
	for (int i = 0; i < np; i++) {
		if (i == 0)
			cout << mice[i].rank;
		else
			cout << " " << mice[i].rank;
	}
	return 0;
}