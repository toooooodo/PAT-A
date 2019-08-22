#include <iostream>
#include <set>
#include <cmath>

using namespace std;

#define MAX 100000

struct node {
	int key;
	int next;
}lst[MAX],lst1[MAX],lst2[MAX];
set<int> st;

bool check(int key) {
	// true->not in set;
	return st.find(abs(key)) == st.end();
}

void print(int head, node lst[]) {
	while (head != -1) {
		printf("%05d %d ", head, lst[head].key);
		if (lst[head].next == -1)
			printf("-1\n");
		else
			printf("%05d\n", lst[head].next);
		head = lst[head].next;
	}
}

int main() {
	int head, n;
	cin >> head >> n;
	for (int i = 0; i < n; i++) {
		int addr;
		cin >> addr;
		cin >> lst[addr].key >> lst[addr].next;
	}
	int head2 = -1;
	int tail1 = -1, tail2 = -1;
	int tmp = head;
	while (tmp != -1) {
		if (check(lst[tmp].key)) {
			st.insert(abs(lst[tmp].key));
			lst1[tmp].key = lst[tmp].key;
			if (tail1 != -1) {
				lst1[tail1].next = tmp;
			}	
			tail1 = tmp;
		}
		else {
			if (head2 == -1)
				head2 = tmp;
			lst2[tmp].key = lst[tmp].key;
			if (tail2 != -1)
				lst2[tail2].next = tmp;
			tail2 = tmp;
		}
		tmp = lst[tmp].next;
	}
	lst1[tail1].next = -1;
	if (tail2 != -1)
		lst2[tail2].next = -1;
	print(head, lst1);
	print(head2, lst2);
	return 0;
}