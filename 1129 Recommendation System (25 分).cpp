#include <iostream>
#include <set>

using namespace std;

#define MAX 50001

int freq[MAX] = { 0 };
struct item {
	int id;
	int freq;
	item(int id, int freq) : id(id), freq(freq) {}
	bool operator < (const item &a) const {
		if (freq != a.freq)
			return freq > a.freq;
		else
			return id < a.id;
	}
};
set<item> items;

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (i != 0) {
			cout << x << ":";
			int cnt = 0;
			for (auto it = items.begin(); it != items.end(); it++) {
				if (cnt < k)
					cout << " " << (*it).id;
				else
					break;
				cnt++;
			}
			cout << endl;
		}
		auto it = items.find(item(x, freq[x]));
		if (it != items.end())
			items.erase(it);
		items.insert(item(x, ++freq[x]));
	}
	return 0;
}