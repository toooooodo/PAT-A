#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef struct node *tree;
struct node {
	int key;
	int height;
	tree left, right;
};
vector<int> level;

int get_h(tree root) {
	if (root == NULL)
		return -1;
	return root->height;
}

tree ll(tree root) {
	tree left_son = root->left;
	root->left = left_son->right;
	left_son->right = root;
	root->height = max(get_h(root->left), get_h(root->right)) + 1;
	left_son->height = max(get_h(left_son->left), get_h(left_son->right)) + 1;
	return left_son;
}

tree rr(tree root) {
	tree right_son = root->right;
	root->right = right_son->left;
	right_son->left = root;
	root->height = max(get_h(root->left), get_h(root->right)) + 1;
	right_son->height = max(get_h(right_son->left), get_h(right_son->right)) + 1;
	return right_son;
}

tree lr(tree root) {
	root->left = rr(root->left);
	return ll(root);
}

tree rl(tree root) {
	root->right = ll(root->right);
	return rr(root);
}

tree insert(int x, tree root) {
	if (root == NULL) {
		root = (tree)malloc(sizeof(struct node));
		root->key = x;
		root->height = 0;
		root->left = root->right = NULL;
	}
	else {
		if (x < root->key) {
			root->left = insert(x, root->left);
			if (get_h(root->left) - get_h(root->right) == 2) {
				if (x < root->left->key)
					root = ll(root);
				else
					root = lr(root);
			}
		}
		else {
			root->right = insert(x, root->right);
			if (get_h(root->right) - get_h(root->left) == 2) {
				if (x > root->right->key)
					root = rr(root);
				else
					root = rl(root);
			}
		}
		root->height = max(get_h(root->left), get_h(root->right)) + 1;
	}
	return root;
}

bool level_order(tree root, int n) {
	queue<tree> q;
	q.push(root);
	bool flg = true;
	int this_level_num = 1;
	int count = 1;
	while (q.empty() == false) {
		int next_level_num = 0;
		for (int i = 0; i < this_level_num; i++) {
			tree front = q.front();
			q.pop();
			level.push_back(front->key);
			if (front->left == NULL && front->right == NULL) {
				if (flg == true && count != n)
					flg = false;
			}
			else if (front->left == NULL && front->right != NULL) {
				flg = false;
				q.push(front->right);
				next_level_num++;
				count++;
			}
			else if (front->left != NULL && front->right == NULL) {
				next_level_num++;
				q.push(front->left);
				count++;
				if (flg == true && count != n)
					flg = false;
			}
			else {
				next_level_num += 2;
				count += 2;
				q.push(front->left);
				q.push(front->right);
			}
		}
		this_level_num = next_level_num;
	}
	return flg;
}

int main() {
	tree root = NULL;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		root = insert(x, root);
	}
	bool flg = level_order(root, n);
	for (int i = 0; i < level.size(); i++) {
		if (i == 0)
			cout << level[i];
		else
			cout << " " << level[i];
	}
	cout << endl;
	if (flg)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}