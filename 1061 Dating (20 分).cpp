#include <iostream>
#include <string>

using namespace std;

string strs[4];
string days[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };

int main() {
	for (int i = 0; i < 4; i++)
		cin >> strs[i];
	bool first = true;
	for (int i = 0; i < strs[0].size() && i < strs[1].size(); i++) {
		if (first) {
			if (strs[0][i] == strs[1][i]) {
				if (strs[0][i] >= 'A'&&strs[0][i] <= 'Z') {
					cout << days[strs[0][i] - 'A'] << " ";
					first = false;
				}
			}
		}
		else { // 
			if (strs[0][i] == strs[1][i]) {
				if (strs[0][i] >= 'A'&&strs[0][i] <= 'N' || strs[0][i] >= '0'&&strs[0][i] <= '9') {
					int hour;
					if (strs[0][i] >= 'A'&&strs[0][i] <= 'N') {
						hour = 10 + (int)(strs[0][i] - 'A');
					}
					else {
						hour = (int)(strs[0][i] - '0');
					}
					printf("%02d:", hour);
					break;
				}
			}
		}
	}
	for (int i = 0; i < strs[2].size() && i < strs[3].size(); i++) {
		if (strs[2][i] == strs[3][i]) {
			if (isalpha(strs[2][i])) {
				printf("%02d", i);
				break;
			}

		}
			
	}
	return 0;
}