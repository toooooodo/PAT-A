#include <iostream>
#include <vector>

using namespace std;

#define MAX 1010

struct node {
	int key;
	int left, right;
	node() :left(-1), right(-1) {}
}heap[MAX];

bool check_max(int n) {
	for (int i = 1; i * 2 <= n; i++) {
		int child = i * 2;
		if (heap[child].key > heap[i].key)
			return false;
		if (i * 2 + 1 <= n) {
			child = i * 2 + 1;
			if (heap[child].key > heap[i].key)
				return false;
		}
	}
	return true;
}

bool check_min(int n) {
	for (int i = 1; i * 2 <= n; i++) {
		int child = i * 2;
		if (heap[child].key < heap[i].key)
			return false;
		if (i * 2 + 1 <= n) {
			child = i * 2 + 1;
			if (heap[child].key < heap[i].key)
				return false;
		}
	}
	return true;
}

void post_order(int root, vector<int>& post) {
	if (root == -1)
		return;
	post_order(heap[root].left, post);
	post_order(heap[root].right, post);
	post.push_back(heap[root].key);
}

int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> heap[j].key;
			if (j % 2 == 0) {
				heap[j / 2].left = j;
			}
			else {
				heap[j / 2].right = j;
			}
		}
		if (check_max(n))
			cout << "Max Heap" << endl;
		else if (check_min(n))
			cout << "Min Heap" << endl;
		else
			cout << "Not Heap" << endl;
		vector<int> post;
		post_order(1, post);
		for (int i = 0; i < post.size(); i++) {
			if (i == 0)
				cout << post[i];
			else
				cout << " " << post[i];
		}
		cout << endl;
	}
	return 0;
}