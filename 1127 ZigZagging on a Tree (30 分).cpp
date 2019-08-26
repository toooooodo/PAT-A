#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

#define MAX 30

typedef struct node *tree;
struct node {
	int key;
	tree left, right;
};
int in[MAX], post[MAX];
vector<int> zigzag;

tree insert(int in_left, int in_right, int post_left, int post_right) {
	if (in_left > in_right) {
		return NULL;
	}
	int mid = in_left;
	while (mid <= in_right && in[mid] != post[post_right])
		mid++;
	tree root = (tree)malloc(sizeof(struct node));
	root->key = in[mid];
	root->left = insert(in_left, mid - 1, post_left, post_left + mid- in_left - 1);
	root->right = insert(mid + 1, in_right, post_left + mid - in_left, post_right - 1);
	return root;
}

void zig_zag(tree root) {
	queue<tree> q;
	q.push(root);
	int this_level_num = 1;
	int level = 1;
	while (q.empty() == false) {
		int next_level_num = 0;
		stack<int> stk;
		for (int i = 0; i < this_level_num; i++) {
			tree front = q.front();
			q.pop();
			if (level % 2 != 0) {
				stk.push(front->key);
			}
			else {
				zigzag.push_back(front->key);
			}
			if (front->left != NULL) {
				next_level_num++;
				q.push(front->left);
			}
			if (front->right != NULL) {
				next_level_num++;
				q.push(front->right);
			}
		}
		this_level_num = next_level_num;
		if (level % 2 != 0) {
			while (stk.empty() == false) {
				zigzag.push_back(stk.top());
				stk.pop();
			}
		}
		level++;
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> in[i];
	for (int i = 0; i < n; i++)
		cin >> post[i];
	tree root = insert(0, n - 1, 0, n - 1);
	zig_zag(root);
	for (int i = 0; i < n; i++) {
		if (i == 0)
			cout << zigzag[i];
		else
			cout << " " << zigzag[i];
	}
	return 0;
}