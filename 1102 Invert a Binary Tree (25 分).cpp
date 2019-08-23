#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define MAX 10

struct node {
	int left, right;
}tree[MAX];
bool appear[MAX] = { false };
vector<int> level_order, in_order;

void levelorder(int root) {
	queue<int> q;
	q.push(root);
	while (q.empty() == false) {
		int front = q.front();
		q.pop();
		if (tree[front].left != -1)
			q.push(tree[front].left);
		if (tree[front].right != -1)
			q.push(tree[front].right);
		level_order.push_back(front);
	}
	for (int i = 0; i < level_order.size(); i++) {
		if (i == 0)
			cout << level_order[i];
		else
			cout << " " << level_order[i];
	}
	cout << endl;
}

void inorder(int root) {
	if (root == -1)
		return;
	inorder(tree[root].left);
	in_order.push_back(root);
	inorder(tree[root].right);
}

int main() {
	int n, root;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string left, right;
		cin >> left >> right;
		tree[i].left = right == "-" ? -1 : stoi(right);
		tree[i].right = left == "-" ? -1 : stoi(left);
		if (right != "-")
			appear[stoi(right)] = true;
		if (left != "-")
			appear[stoi(left)] = true;
	}
	for (int i = 0; i < n; i++)
		if (appear[i] == false) {
			root = i;
			break;
		}
	levelorder(root);
	inorder(root);
	for (int i = 0; i < in_order.size(); i++) {
		if (i == 0)
			cout << in_order[i];
		else
			cout << " " << in_order[i];
	}
	cout << endl;
	return 0;
}