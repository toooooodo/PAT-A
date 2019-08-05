#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct node *tree;
struct node {
	int key;
	tree left, right;
};

vector<int> post, in;
queue<tree> q;
vector<int> seq;

tree insert(int post_left, int post_right, int in_left, int in_right)
{
	if (post_left > post_right)
		return NULL;
	int mid;
	for (int i = in_left; i <= in_right; i++) {
		if (in[i] == post[post_right]) {
			mid = i;
			break;
		}
	}
	tree root = (tree)malloc(sizeof(struct node));
	root->key = post[post_right];
	root->left = insert(post_left, post_left + mid - in_left - 1, in_left, mid - 1);
	root->right = insert(post_left + mid - in_left, post_right - 1, mid + 1, in_right);
	return root;
}


int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		post.push_back(x);
	}
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		in.push_back(x);
	}
	tree root = insert(0, n - 1, 0, n - 1);
	q.push(root);
	while (!q.empty()) {
		tree t = q.front();
		q.pop();
		seq.push_back(t->key);
		if (t->left)
			q.push(t->left);
		if (t->right)
			q.push(t->right);
	}
	for (int i = 0; i < seq.size(); i++) {
		if (i == 0) {
			printf("%d", seq[i]);
		}
		else {
			printf(" %d", seq[i]);
		}
	}
	return 0;
}