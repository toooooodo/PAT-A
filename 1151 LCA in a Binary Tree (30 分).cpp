#include <iostream>
#include <vector>

using namespace std;

#define MAX 10000

int in[MAX], pre[MAX];
typedef struct node *tree;
struct node {
	int key;
	tree left, right;
};

tree insert(int in_left, int in_right, int pre_left, int pre_right) {
	if (in_left > in_right)
		return NULL;
	int mid = in_left;
	while (in[mid] != pre[pre_left])
		mid++;
	tree root = (tree)malloc(sizeof(struct node));
	root->key = in[mid];
	root->left = insert(in_left, mid - 1, pre_left + 1, pre_left + mid - in_left);
	root->right = insert(mid + 1, in_right, pre_left + mid - in_left + 1, pre_right);
	return root;
}

void search(tree root, int x, vector<int> &path, vector<int> &final_path) {
	path.push_back(root->key);
	if (root->key == x) {
		final_path = path;
	}
	else {
		if (final_path.size() == 0) {
			if (root->left != NULL)
				search(root->left, x, path, final_path);
			if (root->right != NULL)
				search(root->right, x, path, final_path);
		}
	}
	path.pop_back();
}

int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		cin >> in[i];
	for (int i = 0; i < n; i++)
		cin >> pre[i];
	tree root = insert(0, n - 1, 0, n - 1);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vector<int> a_path, b_path;
		vector<int> final_path_a, final_path_b;
		search(root, a, a_path, final_path_a);
		search(root, b, b_path, final_path_b);
		if (final_path_a.size() == 0 && final_path_b.size() == 0)
			printf("ERROR: %d and %d are not found.\n", a, b);
		else if (final_path_a.size() == 0)
			printf("ERROR: %d is not found.\n", a);
		else if (final_path_b.size() == 0)
			printf("ERROR: %d is not found.\n", b);
		else {
			int root_idx = 0;
			while (root_idx + 1 < final_path_a.size() && root_idx + 1 < final_path_b.size() && final_path_a[root_idx + 1] == final_path_b[root_idx + 1]) {
				root_idx++;
			}
			if (final_path_a[root_idx] == a)
				printf("%d is an ancestor of %d.\n", a, b);
			else if (final_path_b[root_idx] == b)
				printf("%d is an ancestor of %d.\n", b, a);
			else
				printf("LCA of %d and %d is %d.\n", a, b, final_path_a[root_idx]);
		}
	}
	return 0;
}