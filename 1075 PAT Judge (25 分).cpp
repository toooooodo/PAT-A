#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 10001
#define MAXK 6

struct user {
	int id, rank;
	int score[MAXK];  // 提交过但没通过编译：-1，没提交过：-2；
	int total_score, ac;
	bool submit;
	user() {
		fill(score, score + MAXK, -2);
		submit = false;
		ac = 0;
		total_score = 0;
	}
}users[MAXN], sub_users[MAXN];
int full_mark[MAXK];

bool cmp(user a, user b) {
	if (a.total_score != b.total_score)
		return a.total_score > b.total_score;
	else if (a.ac != b.ac)
		return a.ac > b.ac;
	else
		return a.id < b.id;
}

int main() {
	int n, k, m, count = 0;
	cin >> n >> k >> m;
	for (int i = 1; i <= k; i++)
		cin >> full_mark[i];
	for (int i = 0; i < m; i++) {
		int user_id, problem_id, score;
		cin >> user_id >> problem_id >> score;
		users[user_id].id = user_id;
		if (score != -1) {
			users[user_id].submit = true;
		}
		if (users[user_id].score[problem_id] < score) {
			users[user_id].score[problem_id] = score;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (users[i].submit == false)
			continue;
		for (int j = 1; j <= k; j++) {
			if (users[i].score[j] >= 0)
				users[i].total_score += users[i].score[j];
			if (users[i].score[j] == full_mark[j])
				users[i].ac++;
		}
		sub_users[count++] = users[i];
	}
	sort(sub_users, sub_users + count, cmp);
	for (int i = 0; i < count; i++) {
		if (i == 0)
			sub_users[i].rank = 1;
		else {
			if (sub_users[i].total_score == sub_users[i - 1].total_score)
				sub_users[i].rank = sub_users[i - 1].rank;
			else
				sub_users[i].rank = i + 1;
		}
	}
	for (int i = 0; i < count; i++) {
		printf("%d %05d %d", sub_users[i].rank, sub_users[i].id, sub_users[i].total_score);
		for (int j = 1; j <= k; j++) {
			if (sub_users[i].score[j] == -2)
				printf(" -");
			else if(sub_users[i].score[j] == -1)
				printf(" 0");
			else
				printf(" %d", sub_users[i].score[j]);
		}
		printf("\n");
	}
	return 0;
}