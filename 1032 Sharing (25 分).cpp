#include <iostream>

using namespace std;

#define MAX 100000

struct node {
	char data;
	int next;
}lst[MAX];
bool visited[MAX] = { false };

int main() {
	int s1, s2, n;
	cin >> s1 >> s2 >> n;
	for (int i = 0; i < n; i++) {
		int address;
		cin >> address;
		cin >> lst[address].data >> lst[address].next;

	}
	while (s1 != -1) {
		visited[s1] = true;
		s1 = lst[s1].next;
	}
	while (s2 != -1) {
		if (visited[s2] == true) {
			printf("%05d\n", s2);
			break;
		}
		else {
			visited[s2] = true;
		}
		s2 = lst[s2].next;
	}
	if (s2 == -1)
		cout << s2 << endl;
	return 0;
}