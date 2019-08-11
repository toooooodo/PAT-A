#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b) {
	return a + b < b + a;
}

int main() {
	int n;
	vector<string> seg;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string number;
		cin >> number;
		seg.push_back(number);
	}
	sort(seg.begin(), seg.end(), cmp);
	string result = "";
	for (int i = 0; i < n; i++)
		result += seg[i];
	while (result.empty() == false && result[0] == '0')
		//result.erase(0, 1);
		result.erase(result.begin());
	if (result.empty())
		cout << "0" << endl;
	else
		cout << result << endl;
	return 0;
}