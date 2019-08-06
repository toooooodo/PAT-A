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

// ��123a��˵����С�Ŀ��ܽ�����11����Ϊ��a
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
	3.���ֲ��ҵ����½�ȷ���ܼ��ٺ�ʱ���½�ѡ���ֵ�����λ�ϵ����ֵ+1���Ͻ������뵱Ȼ����Ϊ�������и����� radix ������ֵ��
	ʵ���ϣ�ʾ��11 b 1 10����һ��������ԭ������������������һλ���Ŀ����ԣ������������ȡ���� radix ����ֵ���½��нϴ���Ǹ�����
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
		// һ��Ҫ�ж�convert_result < 0�����˵����ǰ����̫��
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