#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1000
struct cake {
	double amount;
	double price;
	double unit_p;
}cakes[MAX];

bool cmp(cake a, cake b) {
	return a.unit_p > b.unit_p;
}

int main() {
	int n, d;
	cin >> n >> d;
	for (int i = 0; i < n; i++)
		cin >> cakes[i].amount;
	for (int i = 0; i < n; i++) {
		cin >> cakes[i].price;
		cakes[i].unit_p = cakes[i].price / cakes[i].amount;
	}
	sort(cakes, cakes + n, cmp);
	double profit = 0;
	int total = 0;
	for (int i = 0; i < n; i++) {
		if (total + cakes[i].amount <= d) {
			profit += cakes[i].price;
			total += cakes[i].amount;
		}
		else {
			int need = d - total;
			profit += need * cakes[i].unit_p;
			break;
		}
	}
	printf("%.2f\n", profit);
	return 0;
}