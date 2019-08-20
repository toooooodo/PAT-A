#include <iostream>

using namespace std;

#define MAX 100

struct number {
	int nume;
	int deno;
}numbers[MAX];

int gcd(int a, int b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

number reduction(number a) {
	int common = gcd(abs(a.nume), abs(a.deno));
	a.deno /= common;
	a.nume /= common;
	return a;
}

number add(number a, number b) {
	number re;
	re.nume = a.nume*b.deno + a.deno*b.nume;
	re.deno = a.deno*b.deno;
	return reduction(re);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf("%d/%d", &numbers[i].nume, &numbers[i].deno);
	}
	number re = numbers[0];
	re = reduction(re);
	for (int i = 1; i < n; i++) {
		re = add(re, numbers[i]);
	}
	if (re.nume == 0)
		cout << 0 << endl;
	else if (re.deno == 1)
		cout << re.nume << endl;
	else if (abs(re.nume) < abs(re.deno))
		cout << re.nume << "/" << re.deno << endl;
	else
		cout << re.nume / re.deno << " " << abs(re.nume) % re.deno << "/" << re.deno << endl;
	return 0;
}