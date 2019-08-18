#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 10000

int coin[MAX];

vector<int> tmp, re;

void choose(int index, int n, int left) {
	//if (index >= n)
	//	return;
	if (left == 0) {
		// 排序后找到的第一组解即最小解
		if (re.empty())
			re = tmp;
		//else {
		//	for (int i = 0; i < tmp.size() && i < re.size(); i++) {
		//		if (tmp[i] > re[i])
		//			return;
		//		else if (tmp[i] == re[i])
		//			continue;
		//		else {
		//			re = tmp;
		//			return;
		//		}	
		//	}
		//}
	}
	else {
		if (index >= n)
			return;
		if (left < coin[index])
			return;
		if (re.empty() == false)
			return;
		/*
		若index=n-1，即最后一个，算上这枚硬币后index=n，left仍然有可能=0
		所以不能在开始的地方判断index>=n
		*/
		tmp.push_back(coin[index]);
		choose(index + 1, n, left - coin[index]);
		tmp.pop_back();
		choose(index + 1, n, left);
	}

}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
		//if (coin[i] > m) {
		//	i--;
		//	n--;
		//}
	}
	sort(coin, coin + n);
	choose(0, n, m);
	if (re.empty())
		printf("No Solution");
	else {
		for (int i = 0; i < re.size(); i++) {
			if (i == 0)
				printf("%d", re[i]);
			else
				printf(" %d", re[i]);
		}
	}
	return 0;
}