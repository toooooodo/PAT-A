#include <iostream>
#include <vector>

using namespace std;

#define MAX 1010

struct node {
	int key;
	int left, right;
	node() :left(-1), right(-1) {}
}heap[MAX];
vector<int> path;

void print_path(int root) {
	path.push_back(heap[root].key);
	if (heap[root].left == -1 && heap[root].right == -1) {
		for (int i = 0; i < path.size(); i++) {
			if (i == 0)
				cout << path[i];
			else
				cout << " " << path[i];
		}
		cout << endl;
	}
	else {
		if (heap[root].right != 0)
			print_path(heap[root].right);
		if (heap[root].left != 0)
			print_path(heap[root].left);
	}
	path.pop_back();
}

bool check_max_heap(int n) {
	for (int i = 1; i * 2 <= n; i++) {
		int child = i * 2;
		if (i * 2 + 1 <= n && heap[i * 2].key < heap[i * 2 + 1].key)
			child = i * 2 + 1;
		if (heap[child].key > heap[i].key)
			return false;
	}
	return true;
}

bool check_min_heap(int n) {
	for (int i = 1; i * 2 <= n; i++) {
		int child = i * 2;
		if (i * 2 + 1 <= n && heap[i * 2].key > heap[i * 2 + 1].key)
			child = i * 2 + 1;
		if (heap[child].key < heap[i].key)
			return false;
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> heap[i].key;
		if (i % 2 == 0)
			heap[i / 2].left = i;
		else
			heap[i / 2].right = i;
	}
	print_path(1);
	if (check_max_heap(n))
		cout << "Max Heap" << endl;
	else if (check_min_heap(n))
		cout << "Min Heap" << endl;
	else
		cout << "Not Heap" << endl;
	return 0;
}