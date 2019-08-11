#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 100000

long long c[MAX], p[MAX];

bool cmp(long long a, long long b) {
	return a > b;
}

int main() {
	int nc, np;
	cin >> nc;
	for (int i = 0; i < nc; i++)
		cin >> c[i];
	cin >> np;
	for (int i = 0; i < np; i++)
		cin >> p[i];
	sort(c, c + nc, cmp);
	sort(p, p + np, cmp);
	long long result = 0;
	for (int i = 0; i < nc&&i < np; i++) {
		if (c[i] <= 0 || p[i] <= 0)
			break;
		result += c[i] * p[i];
	}
	sort(c, c + nc);
	sort(p, p + np);
	for (int i = 0; i < nc&&i < np; i++) {
		if (c[i] >= 0 || p[i] >= 0)
			break;
		result += c[i] * p[i];
	}
	cout << result << endl;
	return 0;
}