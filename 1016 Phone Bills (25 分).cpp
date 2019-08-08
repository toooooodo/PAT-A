#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

#define MAX 1000

struct record {
	string name, status;
	int month, date, hour, min;
	int time_stamp;
};
struct record records[MAX];
int toll[25] = { 0 };
map<string, vector<record> >cus;

bool cmp(record a, record b) {
	if (a.name != b.name)
		return a.name < b.name;
	return a.time_stamp < b.time_stamp;
}

double calculate(record a) {
	double total = a.date * 60 * toll[24] + a.min * toll[a.hour];
	for (int i = 0; i < a.hour; i++) {
		total += toll[i] * 60;
	}
	return total / 100;
}

int main() {
	for (int i = 0; i < 24; i++) {
		cin >> toll[i];
		toll[24] += toll[i];
	}
		
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> records[i].name;
		scanf("%d:%d:%d:%d", &records[i].month, &records[i].date, &records[i].hour, &records[i].min);
		cin >> records[i].status;
		records[i].time_stamp = records[i].date * 24 * 60 + records[i].hour * 60 + records[i].min;
	}
	sort(records, records + n, cmp);
	for (int i = 0; i < n - 1; i++) {
		if (records[i].name == records[i + 1].name&&records[i].status == "on-line"&&records[i + 1].status == "off-line") {
			cus[records[i].name].push_back(records[i]);
			cus[records[i + 1].name].push_back(records[i + 1]);
		}
	}
	for (auto it = cus.begin(); it != cus.end(); it++) {
		vector<record> re = it->second;
		printf("%s %02d\n", it->first.c_str(), re[0].month);
		double total_amount = 0;
		for (int i = 0; i < re.size(); i += 2) {
			double total = calculate(re[i + 1]) - calculate(re[i]);
			printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", re[i].date, re[i].hour, re[i].min, re[i + 1].date, re[i + 1].hour, re[i + 1].min, re[i + 1].time_stamp - re[i].time_stamp, total);
			total_amount += total;
		}
		printf("Total amount: $%.2f\n", total_amount);
	}
	return 0;
}