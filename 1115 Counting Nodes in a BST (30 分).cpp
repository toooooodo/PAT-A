#include <iostream>
#include <queue>

using namespace std;

typedef struct node *tree;
struct node {
	int key;
	tree left, right;
};

tree insert(int x, tree root) {
	if (root == NULL) {
		root = (tree)malloc(sizeof(struct node));
		root->left = root->right = NULL;
		root->key = x;
	}
	else {
		if (x <= root->key)
			root->left = insert(x, root->left);
		else
			root->right = insert(x, root->right);
	}
	return root;
}

void level_order(tree root, int &l1, int &l2) {
	queue<tree> q;
	q.push(root);
	int this_level_num = 1;
	l1 = 1, l2 = 0;
	while (q.empty() == false) {
		int next_level_num = 0;
		for (int i = 0; i < this_level_num; i++) {
			tree front = q.front();
			q.pop();
			if (front->left != NULL) {
				q.push(front->left);
				next_level_num++;
			}
			if (front->right != NULL) {
				q.push(front->right);
				next_level_num++;
			}
		}
		this_level_num = next_level_num;
		if (this_level_num != 0) {
			l2 = l1;
			l1 = this_level_num;
		}
	}
}

int main() {
	int n, l1, l2;
	cin >> n;
	tree root = NULL;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		root = insert(x, root);
	}
	level_order(root, l1, l2);
	cout << l1 << " + " << l2 << " = " << l1 + l2 << endl;
	return 0;
}