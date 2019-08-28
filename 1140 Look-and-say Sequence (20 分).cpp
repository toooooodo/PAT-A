#include <iostream>
#include <string>

using namespace std;

int main() {
	int d, n;
	string x;
	scanf("%d %d", &d, &n);
	x = to_string(d);
	for (int i = 1; i < n; i++) {
		string re = "";
		int idx = 0;
		while (idx < x.size()) {
			int count = 1;
			while (idx + 1 < x.size() && x[idx + 1] == x[idx]) {
				count++;
				idx++;
			}
			re = re + x[idx] + (char)('0' + count);
			idx++;
		}
		x = re;
	}
	printf("%s\n", x.c_str());
	return 0;
}