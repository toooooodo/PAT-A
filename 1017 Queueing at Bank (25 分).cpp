#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10000

struct customer {
	int hour, min, sec;
	int processing_time;
	int waiting_time;
	int time_stamp;
}customers[MAX];
int windows[MAX];

bool cmp(customer a, customer b) {
	return a.time_stamp < b.time_stamp;
}

void find_window(int index,int k) {
	int min_index = -1, min_value = 0x3fffffff;
	for (int i = 0; i < k; i++) {
		if (windows[i] < min_value) {
			min_value = windows[i];
			min_index = i;
		}
	}
	customers[index].waiting_time = max(windows[min_index] - customers[index].time_stamp, 0);
	windows[min_index] = max(windows[min_index], customers[index].time_stamp) + customers[index].processing_time * 60;
	//windows[min_index] += customers[index].processing_time * 60;
}

int main() {
	int n, k, total_served = 0, total_waiting = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d:%d:%d %d", &customers[i].hour, &customers[i].min, &customers[i].sec, &customers[i].processing_time);
		customers[i].time_stamp = customers[i].hour * 60 * 60 + customers[i].min * 60 + customers[i].sec;
		//cout << customers[i].time_stamp << endl;
	}
	sort(customers, customers + n, cmp);
	fill(windows, windows + k, 8 * 60 * 60);
	for (int i = 0; i < n; i++) {
		if (customers[i].time_stamp > 17 * 60 * 60) {
			break;
		}
		find_window(i, k);
		total_served += 1;
		total_waiting += customers[i].waiting_time;
	}
	if (total_served == 0)
		printf("0.0\n");
	else
		printf("%.1f\n", total_waiting / (total_served*60.0));
	return 0;
}