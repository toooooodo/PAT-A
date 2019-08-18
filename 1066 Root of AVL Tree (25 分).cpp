#include <iostream>
#include <algorithm>

using namespace std;

typedef struct node *avl;
struct node {
	int key;
	int height;
	avl left, right;
};

int get_h(avl root) {
	if (root == NULL)
		return -1;
	else
		return root->height;
}

avl ll(avl root) {
	avl left_son = root->left;
	root->left = left_son->right;
	left_son->right = root;
	root->height = max(get_h(root->left), get_h(root->right)) + 1;
	left_son->height = max(get_h(left_son->left), get_h(left_son->right)) + 1;
	return left_son;
}

avl rr(avl root) {
	avl right_son = root->right;
	root->right = right_son->left;
	right_son->left = root;
	root->height = max(get_h(root->left), get_h(root->right)) + 1;
	right_son->height = max(get_h(right_son->left), get_h(right_son->right)) + 1;
	return right_son;
}

avl lr(avl root) {
	root->left = rr(root->left);
	return ll(root);
}

avl rl(avl root) {
	root->right = ll(root->right);
	return rr(root);
}

avl insert(avl root, int x) {
	if (root == NULL) {
		root = (avl)malloc(sizeof(struct node));
		root->left = root->right = NULL;
		root->key = x;
		root->height = 0;
	}
	else {
		if (x < root->key) {
			root->left = insert(root->left, x);
			if (get_h(root->left) - get_h(root->right) == 2) {
				if (x < root->left->key)
					root = ll(root);
				else
					root = lr(root);
			}
		}
		else {
			root->right = insert(root->right, x);
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

int main() {
	int n;
	cin >> n;
	avl root = NULL;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		root = insert(root, x);
	}
	cout << root->key << endl;
	return 0;
}