#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 50001

struct item {
	int id;
	int freq;
	item() :freq(0) {}
}items[MAX];
int freqs[MAX];

//bool cmp(item a, item b) {
//	if (a.freq != b.freq)
//		return a.freq > b.freq;
//	else
//		return a.id < b.id;
//}

bool cmp(int a, int b) {
	if (items[a].freq != items[b].freq)
		return items[a].freq > items[b].freq;
	else
		return items[a].id < items[b].id;
}

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		items[i].id = i;
		freqs[i] = i;
	}
		
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (i != 0) {
			cout << x << ":";
			for (int j = 1; j <= k; j++) {
				if (items[freqs[j]].freq != 0)
					cout << " " << items[freqs[j]].id;
				else
					break;
			}
			cout << endl;
		}
		items[x].freq++;
		sort(freqs + 1, freqs + n + 1, cmp);
		/*sort(items + 1, items + 1 + n, cmp);*/
	}
	return 0;
}