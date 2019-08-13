#include <iostream>
#include <vector>

using namespace std;

typedef struct node *tree;
struct node {
	int key;
	tree left, right;
};
vector<int>record, pre, pre_mirror, post;

tree insert(tree root, int key) {
	if (root == NULL) {
		root = (tree)malloc(sizeof(struct node));
		root->left = root->right = NULL;
		root->key = key;
	}
	else {
		if (key < root->key) {
			root->left = insert(root->left, key);
		}
		else {
			root->right = insert(root->right, key);
		}
	}
	return root;
}

void pre_order(tree root) {
	if (root == NULL)
		return;
	pre.push_back(root->key);
	pre_order(root->left);
	pre_order(root->right);
}

void pre_order_mirror(tree root) {
	if (root == NULL)
		return;
	pre_mirror.push_back(root->key);
	pre_order_mirror(root->right);
	pre_order_mirror(root->left);
}

void post_order(tree root) {
	if (root == NULL)
		return;
	post_order(root->left);
	post_order(root->right);
	post.push_back(root->key);
}

void post_order_mirror(tree root) {
	if (root == NULL)
		return;
	post_order_mirror(root->right);
	post_order_mirror(root->left);
	post.push_back(root->key);
}

int main() {
	int n;
	cin >> n;
	tree root = NULL;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		root = insert(root, x);
		record.push_back(x);
	}
	pre_order(root);
	pre_order_mirror(root);
	if (record == pre || record == pre_mirror) {
		cout << "YES" << endl;
		if (record == pre)
			post_order(root);
		else
			post_order_mirror(root);
		for (auto it = post.begin(); it != post.end(); it++) {
			if (it == post.begin())
				cout << *it;
			else
				cout << " " << *it;
		}
	}
	else
		cout << "NO" << endl;
	return 0;
}