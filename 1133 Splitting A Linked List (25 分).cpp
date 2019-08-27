#include <iostream>

using namespace std;

#define MAX 100000

struct node {
	int key;
	int next;
	node() :next(-1) {}
}lst[MAX], sort_lst[MAX];

int main() {
	int head, n, k;
	cin >> head >> n >> k;
	for (int i = 0; i < n; i++) {
		int addr;
		cin >> addr;
		cin >> lst[addr].key >> lst[addr].next;
	}
	int sort_head, last = -1;
	int tmp = head;
	while (tmp != -1) {
		if (lst[tmp].key < 0) {
			if (last == -1) {
				sort_head = tmp;
			}
			else {
				sort_lst[last].next = tmp;
			}
			sort_lst[tmp].key = lst[tmp].key;
			last = tmp;
		}
		tmp = lst[tmp].next;
	}
	tmp = head;
	while (tmp != -1) {
		if (lst[tmp].key >= 0 && lst[tmp].key <= k) {
			if (last == -1) {
				sort_head = tmp;
			}
			else {
				sort_lst[last].next = tmp;
			}
			sort_lst[tmp].key = lst[tmp].key;
			last = tmp;
		}
		tmp = lst[tmp].next;
	}
	tmp = head;
	while (tmp != -1) {
		if (lst[tmp].key > k) {
			if (last == -1) {
				sort_head = tmp;
			}
			else {
				sort_lst[last].next = tmp;
			}
			sort_lst[tmp].key = lst[tmp].key;
			last = tmp;
		}
		tmp = lst[tmp].next;
	}
	sort_lst[last].next = -1;
	while (sort_head != -1) {
		if (sort_lst[sort_head].next != -1) {
			printf("%05d %d %05d\n", sort_head, sort_lst[sort_head].key, sort_lst[sort_head].next);
		}
		else {
			printf("%05d %d %d\n", sort_head, sort_lst[sort_head].key, sort_lst[sort_head].next);
		}
		sort_head = sort_lst[sort_head].next;
	}
	return 0;
}