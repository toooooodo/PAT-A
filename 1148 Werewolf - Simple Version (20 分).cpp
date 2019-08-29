#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> numbers(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> numbers[i];
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			vector<int> lie, werewolf(n + 1, 1);
			werewolf[i] = werewolf[j] = -1;
			for (int k = 1; k <= n; k++) {
				if (numbers[k] * werewolf[abs(numbers[k])] < 0)
					lie.push_back(k);
			}
			if (lie.size() == 2 && werewolf[lie[0]] + werewolf[lie[1]] == 0) {
				cout << i << " " << j << endl;
				return 0;
			}
				
		}
	}
	cout << "No Solution" << endl;
	return 0;
}