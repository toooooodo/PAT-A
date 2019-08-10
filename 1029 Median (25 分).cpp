#include <iostream>
using namespace std;

#define MAX 200000
int seq[MAX];

int main() {
	int n1, n2;
	cin >> n1;
	for (int i = 0; i < n1; i++)
		cin >> seq[i];
	cin >> n2;
	int med = (n1 + n2 + 1) / 2;
	int count = 0, index = 0;
	for (int i = 0; i < n2; i++) {
		int tmp;
		cin >> tmp;
		while (seq[index] < tmp&&index < n1) {
			count++;
			if (count == med)
				cout << seq[index];
			index++;
		}
		count++;
		if (count == med)
			cout << tmp;
	}
	while (index < n1) {
		count++;
		if (count == med) {
			cout << seq[index];
			break;
		}
			
		index++;
	}
	return 0;
}