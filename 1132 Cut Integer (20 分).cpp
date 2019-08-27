#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		int a = stoi(x.substr(0, x.size() / 2));
		int b = stoi(x.substr(x.size() / 2, x.size() / 2));
		if (a * b != 0 && stoi(x) % (a*b) == 0)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}