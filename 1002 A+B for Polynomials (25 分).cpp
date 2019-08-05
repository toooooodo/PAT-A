#include <iostream>
#include <vector>
using namespace std;

struct item {
	int expo;
	double coef;
};
vector<item> a, b, result;

int main()
{
	int n1, n2;
	cin >> n1;
	for (int i = 0; i < n1; i++) {
		item it;
		cin >> it.expo >> it.coef;
		a.push_back(it);
	}
	cin >> n2;
	for (int i = 0; i < n2; i++) {
		item it;
		cin >> it.expo >> it.coef;
		b.push_back(it);
	}
	int a_point, b_point;
	a_point = b_point = 0;
	while (a_point < a.size() && b_point < b.size()) {
		if (a[a_point].expo > b[b_point].expo)
			result.push_back(a[a_point++]);
		else if (a[a_point].expo < b[b_point].expo)
			result.push_back(b[b_point++]);
		else {
			item it;
			it.expo = a[a_point].expo;
			it.coef = a[a_point].coef + b[b_point].coef;
			if (it.coef != 0)
				result.push_back(it);
			a_point++;
			b_point++;
		}
	}
	while (a_point < a.size())
		result.push_back(a[a_point++]);
	while (b_point < b.size())
		result.push_back(b[b_point++]);
	cout << result.size();
	for (int i = 0; i < result.size(); i++)
		printf(" %d %.1f", result[i].expo, result[i].coef);
	return 0;
}