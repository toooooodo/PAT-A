#include <iostream>
#include <cmath>

using namespace std;

struct fraction {
	long long nume;
	long long deno;
};

int gcd(long long a, long long b) {
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

fraction reduction(fraction a) {
	if (a.deno < 0) {
		a.deno = -a.deno;
		a.nume = -a.nume;
	}
	int div = gcd(abs(a.nume), abs(a.deno));
	a.nume /= div;
	a.deno /= div;
	return a;
}

fraction add(fraction a, fraction b) {
	fraction re;
	re.nume = a.nume*b.deno + b.nume*a.deno;
	re.deno = a.deno*b.deno;
	return reduction(re);
}

fraction diff(fraction a, fraction b) {
	fraction re;
	re.nume = a.nume*b.deno - a.deno*b.nume;
	re.deno = a.deno*b.deno;
	return reduction(re);
}

fraction muti(fraction a, fraction b) {
	fraction re;
	re.nume = a.nume*b.nume;
	re.deno = a.deno*b.deno;
	return reduction(re);
}

fraction divi(fraction a, fraction b) {
	fraction re;
	re.nume = a.nume*b.deno;
	re.deno = a.deno*b.nume;
	return reduction(re);
}

void print(fraction a) {
	if (a.deno == 0)
		cout << "Inf";
	else {
		if (a.nume < 0)
			cout << "(";
		if (a.nume == 0)
			cout << 0;
		else if (a.deno == 1)
			cout << a.nume;
		else {
			if (abs(a.nume) > a.deno) {
				cout << a.nume / a.deno << " " << abs(a.nume) % a.deno << "/" << a.deno;
			}
			else {
				cout << a.nume << "/" << a.deno;
			}
		}
		if (a.nume < 0)
			cout << ")";
	}
}

/*
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
*/

int main() {
	fraction a, b;
	scanf("%lld/%lld %lld/%lld", &a.nume, &a.deno, &b.nume, &b.deno);
	a = reduction(a);
	b = reduction(b);
	print(a);
	cout << " + ";
	print(b);
	cout << " = ";
	print(add(a, b));
	cout << endl;

	print(a);
	cout << " - ";
	print(b);
	cout << " = ";
	print(diff(a, b));
	cout << endl;

	print(a);
	cout << " * ";
	print(b);
	cout << " = ";
	print(muti(a, b));
	cout << endl;

	print(a);
	cout << " / ";
	print(b);
	cout << " = ";
	print(divi(a, b));
	cout << endl;
	return 0;
}