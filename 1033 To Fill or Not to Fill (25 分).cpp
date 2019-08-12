#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 501
const double infi = 1000000;

struct station{
	double dis;
	double price;
}stations[MAXN];

bool cmp(station a, station b) {
	return a.dis < b.dis;
}


int main() {
	int n;
	double c_max, d, d_avg;
	cin >> c_max >> d >> d_avg >> n;
	for (int i = 0; i < n; i++) {
		cin >> stations[i].price >> stations[i].dis;
	}
	stations[n].dis = d;
	stations[n].price = 0;
	sort(stations, stations + n + 1, cmp);
	if (stations[0].dis != 0)
		cout << "The maximum travel distance = 0.00" << endl;
	else {
		double total = 0, now_tank = 0;
		int now = 0;
		while (now <= n) {
			int min_index = -1;
			double min_price = infi;
			for (int i = now + 1; stations[now].dis + c_max * d_avg >= stations[i].dis&&i <= n; i++) {
				if (stations[i].price < min_price) {
					min_price = stations[i].price;
					min_index = i;
					if (min_price < stations[now].price)
						break;
				}
			}
			if (min_index == -1)
				break;
			double need = (stations[min_index].dis - stations[now].dis) / d_avg;
			if (min_price < stations[now].price) {
				// 在可到达的范围内有价格更低的station
				if (now_tank > need) {
					// 油箱里的油足够到达
					now_tank -= need;
				}
				else {
					total += (need - now_tank)*stations[now].price;
					now_tank = 0;
				}
			}
			else {
				// 在可到达的范围内这是价格最低的，把油箱装满
				total += (c_max - now_tank)*stations[now].price;
				now_tank = c_max - need;
			}
			now = min_index;
		}
		if (now == n)
			printf("%.2f\n", total);
		else
			printf("The maximum travel distance = %.2f\n", stations[now].dis + c_max * d_avg);
	}
	return 0;
}