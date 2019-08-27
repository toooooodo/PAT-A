#include <iostream>
#include <vector>

using namespace std;

#define MAX 50000

typedef struct node *tree;
struct node {
	int key;
	tree left, right;
};
int pre[MAX], in[MAX];

tree insert(int pre_left, int pre_right, int in_left, int in_right) {
	if (pre_left > pre_right)
		return NULL;
	int mid = in_left;
	while (in[mid] != pre[pre_left])
		mid++;
	tree root = (tree)malloc(sizeof(struct node));
	root->key = in[mid];
	root->left = insert(pre_left + 1, pre_left + mid - in_left, in_left, mid - 1);
	root->right = insert(pre_left + mid - in_left + 1, pre_right, mid + 1, in_right);
	return root;
}

void print(tree root, bool &flg) {
	if (root == NULL)
		return;
	print(root->left, flg);
	print(root->right, flg);
	if (flg == false) {
		cout << root->key;
		flg = true;
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> pre[i];
	for (int i = 0; i < n; i++)
		cin >> in[i];
	tree root = insert(0, n - 1, 0, n - 1);
	bool flg = false;
	print(root, flg);
	return 0;
}