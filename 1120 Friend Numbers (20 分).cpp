#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec_id;
set<int> set_id;

void insert(string x) {
	int sum = 0;
	for (int i = 0; i < x.size(); i++)
		sum += (int)(x[i] - '0');
	set_id.insert(sum);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		insert(x);
	}
	for (auto it = set_id.begin(); it != set_id.end(); it++)
		vec_id.push_back(*it);
	sort(vec_id.begin(), vec_id.end());
	cout << vec_id.size() << endl;
	for (int i = 0; i < vec_id.size(); i++) {
		if (i == 0)
			cout << vec_id[i];
		else
			cout << " " << vec_id[i];
	}
	return 0;
}