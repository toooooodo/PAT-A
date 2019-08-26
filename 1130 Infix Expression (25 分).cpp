#include <iostream>
#include <string>

using namespace std;

#define MAX 21

struct node {
	string key;
	int left, right;
}tree[MAX];
bool appear[MAX] = { false };

string in_order(int root, int _root) {
	if (tree[root].left != -1 && tree[root].right != -1) {
		if (root != _root)
			return "(" + in_order(tree[root].left, _root) + tree[root].key + in_order(tree[root].right, _root) + ")";
		else
			return in_order(tree[root].left, _root) + tree[root].key + in_order(tree[root].right, _root);
	}
	else if (tree[root].left == -1 && tree[root].right != -1) {
		if (root != _root)
			return "(" + tree[root].key + in_order(tree[root].right, _root) + ")";
		else
			return tree[root].key + in_order(tree[root].right, _root);
	}
	else if (tree[root].left == -1 && tree[root].right == -1) {
		return tree[root].key;
	}
}

int main() {
	int n, root;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> tree[i].key >> tree[i].left >> tree[i].right;
		if (tree[i].left != -1)
			appear[tree[i].left] = true;
		if (tree[i].right != -1)
			appear[tree[i].right] = true;
	}
	for (int i = 1; i <= n; i++) {
		if (appear[i] == false) {
			root = i;
			break;
		}
	}
	string infix = in_order(root, root);
	cout << infix << endl;
	return 0;
}