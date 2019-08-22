#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 100

struct node {
	int left;
	int right;
	int key;
}tree[MAX];
int numbers[MAX];
vector<int> inorder;

void in_order(int root) {
	if (root == -1)
		return;
	in_order(tree[root].left);
	inorder.push_back(root);
	in_order(tree[root].right);
}

void level_order(int root) {
	queue<int> q;
	q.push(root);
	int count = 0;
	while (q.empty() == false) {
		int front = q.front();
		q.pop();
		if (tree[front].left != -1)
			q.push(tree[front].left);
		if (tree[front].right != -1)
			q.push(tree[front].right);
		if (count == 0)
			cout << tree[front].key;
		else
			cout << " " << tree[front].key;
		count++;
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tree[i].left >> tree[i].right;
	}
	for (int i = 0; i < n; i++)
		cin >> numbers[i];
	sort(numbers, numbers + n);
	in_order(0);
	for (int i = 0; i < n; i++)
		tree[inorder[i]].key = numbers[i];
	level_order(0);
	return 0;
}