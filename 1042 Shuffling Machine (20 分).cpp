#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX 54
vector<string> cards, tmp;
int order[MAX];

void init() {
	char colors[4] = { 'S','H','C','D' };
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= 13; j++) {
			cards.push_back(colors[i] + to_string(j));
		}
	}
	cards.push_back("J1");
	cards.push_back("J2");
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < MAX; i++)
		cin >> order[i];
	init();
	for (int i = 0; i < n; i++) {
		vector<string> tmp(MAX);
		for (int j = 0; j < MAX; j++) {
			tmp[order[j] - 1] = cards[j];
		}
		cards = tmp;
	}
	for (int i = 0; i < cards.size(); i++) {
		if (i == 0)
			cout << cards[i];
		else
			cout << " " << cards[i];
	}
	return 0;
}