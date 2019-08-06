#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

long long convert(string n, long long radix) {
	long long sum = 0;
	for (long long i = 0; i < n.size(); i++) {
		if (n[i] >= 'a') {
			sum = sum * radix + (n[i] - 'a') + 10;
		}
		else {
			sum = sum * radix + (n[i] - '0');
		}
	}
	return sum;
}

// 对123a来说，最小的可能进制是11，因为有a
long long least_radix(string n) {
	long long radix = 2;
	for (long long i = 0; i < n.size(); i++) {
		if (n[i] >= 'a') {
			if((n[i] - 'a') + 11 > radix)
				radix = (n[i] - 'a') + 11;
		}
		else {
			if ((n[i] - '0' + 1) > radix)
				radix = (n[i] - '0') + 1;
		}
	}
	return radix;
}

int main() {
	string n1, n2;
	long long tag, radix;
	bool flag = true;
	cin >> n1 >> n2 >> tag >> radix;
	if (tag == 2)
		swap(n1, n2);
	long long goal = convert(n1, radix);
	/*
	3.二分查找的上下界确定能减少耗时：下界选数字的所有位上的最大值+1；上界容易想当然的认为就是题中给定了 radix 的数的值。
	实际上，示例11 b 1 10就是一个反例，原因在于这个假设忽略了一位数的可能性，解决方案是在取给定 radix 的数值和下界中较大的那个数。
	*/
	long long low = least_radix(n2);
	long long high = max(low, goal);
	while (low <= high) {
		long long mid = (low + high) / 2;
		long long convert_result = convert(n2, mid);
		if (convert_result == goal) {
			cout << mid << endl;
			flag = false;
			break;
		}
		// 一定要判断convert_result < 0，溢出说明当前进制太大
		else if (convert_result < 0 || convert_result > goal) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	//for (long long i = least_radix(n2); i <= goal; i++) {
	//	if (goal == convert(n2, i)) {
	//		cout << i << endl;
	//		flag = false;
	//		break;
	//	}
	//}
	if (flag)
		cout << "Impossible" << endl;
	return 0;
}