#include <iostream>

using namespace std;

#define MAX 100000

struct node {
	int data;
	int next;
}lst[MAX];

int reverse(int head, int n, int k) {
	if (n < k)
		return head;
	int tail = head;
	int tmp, last, next;
	tmp = last = head;
	next = lst[head].next;
	for (int i = 0; i < k - 1; i++) {
		tmp = next;
		next = lst[tmp].next;
		lst[tmp].next = last;
		last = tmp;
	}
	lst[tail].next = reverse(next, n - k, k);
	return tmp;
}

int count(int head) {
	int n = 0;
	while (head != -1) {
		n++;
		head = lst[head].next;
	}
	return n;
}

int main() {
	int head, n, k;
	cin >> head >> n >> k;
	for (int i = 0; i < n; i++) {
		int addr, data, next;
		cin >> addr >> data >> next;
		lst[addr].data = data;
		lst[addr].next = next;
	}
	n = count(head);
	head = reverse(head, n, k);
	while (lst[head].next != -1) {
		printf("%05d %d %05d\n", head, lst[head].data, lst[head].next);
		head = lst[head].next;
	}
	printf("%05d %d -1\n", head, lst[head].data);
	return 0;
}