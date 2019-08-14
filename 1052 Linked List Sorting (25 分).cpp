#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100000

struct node {
	int key;
	int addr, next;
	bool flag;
	node() : flag (false) {}
}lst[MAX];

bool cmp(node a, node b) {
	if (a.flag == false || b.flag == false)
		return a.flag > b.flag;
	else
		return a.key < b.key;
}

int main() {
	int n, head, count = 0;
	cin >> n >> head;
	for (int i = 0; i < n; i++) {
		int address;
		cin >> address;
		cin >> lst[address].key >> lst[address].next;
		lst[address].addr = address;
	}
	while (head != -1) {
		count++;
		lst[head].flag = true;
		head = lst[head].next;
	}
	sort(lst, lst + MAX, cmp);
	if (count == 0)
		printf("%d -1\n", count);
	else
		printf("%d %05d\n", count, lst[0].addr);
	for (int i = 0; i < count; i++) {
		if (i != count - 1) {
			printf("%05d %d %05d\n", lst[i].addr, lst[i].key, lst[i + 1].addr);
		}
		else {
			printf("%05d %d -1\n", lst[i].addr, lst[i].key);
		}
	}
	return 0;
}