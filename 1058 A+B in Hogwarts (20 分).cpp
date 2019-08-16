#include <iostream>

using namespace std;

// Galleon.Sickle.Knut
struct currency {
	int g, s, k;
};

int main() {
	struct currency a, b, c;
	scanf("%d.%d.%d %d.%d.%d", &a.g, &a.s, &a.k, &b.g, &b.s, &b.k);
	int carry = 0;
	c.k = (a.k + b.k) % 29;
	carry = (a.k + b.k) / 29;
	c.s = (a.s + b.s + carry) % 17;
	carry = (a.s + b.s + carry) / 17;
	c.g = a.g + b.g + carry;
	printf("%d.%d.%d\n", c.g, c.s, c.k);
	return 0;
}