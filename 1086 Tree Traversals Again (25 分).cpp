#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

#define MAX 30

typedef struct node *tree;
struct node {
	int key;
	tree right, left;
};
int in_order[MAX], pre_order[MAX];
vector<int> post;

tree insert(int pre_left, int pre_right, int in_left, int in_right) {
	if (pre_left > pre_right)
		return NULL;
	int mid = in_left;
	while (in_order[mid] != pre_order[pre_left])
		mid++;
	tree root = (tree)malloc(sizeof(struct node));
	root->key = pre_order[pre_left];
	root->left = insert(pre_left + 1, pre_left + mid - in_left, in_left, mid - 1);
	root->right = insert(pre_left + mid - in_left + 1, pre_right, mid + 1, in_right);
	return root;
}

void post_order(tree root) {
	if (root == NULL)
		return;
	post_order(root->left);
	post_order(root->right);
	post.push_back(root->key);
}

int main() {
	stack<int> stk;
	int n, in_order_counter = 0, pre_order_counter = 0;
	cin >> n;
	for (int i = 0; i < 2 * n; i++) {
		string cmd;
		cin >> cmd;
		if (cmd == "Push") {
			int x;
			cin >> x;
			stk.push(x);
			pre_order[pre_order_counter++] = x;
		}
		else {
			in_order[in_order_counter++] = stk.top();
			stk.pop();
		}
	}
	tree root = insert(0, n - 1, 0, n - 1);
	post_order(root);
	for (int i = 0; i < post.size(); i++) {
		if (i != 0)
			cout << " ";
		cout << post[i];
	}
	return 0;
}