#include <iostream>
#include <cstring>
#include <string>

using namespace std;

#define MAX 1000

string seq = "";

int check(int begin, int end) {
	for (int i = begin; i <= (begin + end) / 2; i++)
		if (seq[i] != seq[end - i + begin])
			return 0;
	return 1;
}

int main() {
	getline(cin, seq);
	int max_len = -1;
	for (int i = 0; i < seq.size(); i++) {
		for (int j = i; j < seq.size(); j++) {
			if (check(i, j) && j - i + 1 > max_len)
				max_len = j - i + 1;
		}
	}
	printf("%d", max_len);
	return 0;
}