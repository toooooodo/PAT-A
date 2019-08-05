#include <cstdio>
#include <climits>

#define MAX 10000
int seq[MAX];

int main() {
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++)
		scanf("%d", &seq[i]);
	int final_i, final_j;
	int max_sum = INT_MIN;
	//for (int i = 0; i < k; i++) {
	//	int sum = 0;
	//	for (int j = i; j < k; j++) {
	//		sum += seq[j];
	//		if (sum > max_sum) {
	//			final_i = i;
	//			final_j = j;
	//			max_sum = sum;
	//		}
	//	}
	//}
	int temp_i = 0, temp_sum = 0;
	for (int i = 0; i < k; i++) {
		temp_sum += seq[i];
		if (temp_sum < 0) {
			temp_sum = 0;
			temp_i = i + 1;
		}
		else if (temp_sum > max_sum) {
			max_sum = temp_sum;
			final_i = temp_i;
			final_j = i;
		}
	}
	if (max_sum >= 0)
		printf("%d %d %d\n", max_sum, seq[final_i], seq[final_j]);
	else
		printf("0 %d %d\n", seq[0], seq[k - 1]);
	return 0;
}