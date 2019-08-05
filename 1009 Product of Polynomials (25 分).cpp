#include <iostream>
#include <vector>
using namespace std;
/* зЂвт 1000 + 1000 = 2000*/
#define MAX 2001 
struct item {
	int expo;
	double coef;
};
vector<item> poly1, poly2, poly;
double re[MAX] = { 0 };

int main() {
	int num1, num2;
	cin >> num1;
	for (int i = 0; i < num1; i++) {
		struct item it;
		cin >> it.expo >> it.coef;
		poly1.push_back(it);
	}
	cin >> num2;
	for (int i = 0; i < num2; i++) {
		struct item it;
		cin >> it.expo >> it.coef;
		poly2.push_back(it);
	}
	for (int i = 0; i < poly1.size(); i++) {
		for (int j = 0; j < poly2.size(); j++) {
			re[poly1[i].expo + poly2[j].expo] += poly1[i].coef*poly2[j].coef;
		}
	}
	for (int i = MAX - 1; i >= 0; i--) {
		if (re[i] != 0) {
			struct item it;
			it.expo = i;
			it.coef = re[i];
			poly.push_back(it);
		}
	}
	cout << poly.size();
	for (int i = 0; i < poly.size(); i++) {
		printf(" %d %.1f", poly[i].expo, poly[i].coef);
	}
	return 0;
}