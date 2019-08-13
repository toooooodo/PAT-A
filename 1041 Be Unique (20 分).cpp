#include <iostream>
#include <vector>

using namespace std;

#define MAX 1001

int cnt[MAX] = { 0 };
vector<int> vec;

int main() {
	int n, flg = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		vec.push_back(x);
		cnt[x]++;
	}
	for (int i = 0; i < vec.size(); i++) {
		if (cnt[vec[i]] == 1) {
			cout << vec[i] << endl;
			flg = 1;
			break;
		}	
	}
	if (flg == 0)
		cout << "None" << endl;
	return 0;
}