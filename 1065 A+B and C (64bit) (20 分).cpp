#include <iostream>

using namespace std;

int main() {
	long long a, b, c;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		if (a > 0 && b > 0 && a + b <= 0)
			printf("Case #%d: true\n", i + 1);
		else if (a < 0 && b < 0 && a + b >= 0)
			printf("Case #%d: false\n", i + 1);
		else if (a + b > c)
			printf("Case #%d: true\n", i + 1);
		else
			printf("Case #%d: false\n", i + 1);
	}
	return 0;
}