#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> repository;
vector<vector<int>> totallist;
// �˻��ؾ��ϴ� ���� 2���̴�.
// 1. ���� �� ������ �� ��찡 �ֳ�
// 2. ���� �� ���� �ߺ��� �ֳ�
int choice(int bigidx, int smallidx, vector<int> banlist)
{
	// �̰�찡 ��� �� ���
	if (bigidx == repository.size())
	{
		sort(banlist.begin(), banlist.end());
		for (int i = 0; i < totallist.size(); i++)
		{
			if (totallist[i] == banlist) return 0;
		}
		totallist.push_back(banlist);
		return 1;
	}
	if (smallidx == repository[bigidx].size()) return 0;
	int result = 0;
	// �� �ε����� �� ���
	for (int i = 0; i < banlist.size(); i++)
	{
		// �ߺ����ڰ� �ִ� ���
		if (repository[bigidx][smallidx] == banlist[i]) return result += choice(bigidx, smallidx + 1, banlist);
	}
	banlist.push_back(repository[bigidx][smallidx]);
	result += choice(bigidx + 1, 0, banlist);
	banlist.pop_back();
	// �� �ε����� ���� ���� ���
	result += choice(bigidx, smallidx + 1, banlist);

	return result;
}

int solution(vector<string> user_id, vector<string> banned_id) {
	int answer = 0;
	int i, j, k;
	for (i = 0; i < banned_id.size(); i++)
	{
		// i �� ���� ���̵� �� �� �ִ� j �� ���̵� �ѹ� ����
		vector<int> ban;
		for (j = 0; j < user_id.size(); j++)
		{
			// �ּ��� ��� ���ƾ��Ѵ�,
			if (banned_id[i].length() != user_id[j].length()) continue;
			for (k = 0; k < banned_id[i].length(); k++)
			{
				if (banned_id[i][k] == '*') continue;
				// �ٸ��� ��
				if (banned_id[i][k] != user_id[j][k]) break;
			}
			if (k == banned_id[i].length())
			{
				// ������ ���� ��쿡��
				ban.push_back(j);
			}
		}
		repository.push_back(ban);
	}

	vector<int> banlist;
	answer += choice(0, 0, banlist);
	return answer;
}

int main()
{
	vector<string> user_id; vector<string> banned_id;
	user_id.push_back("frodo"); user_id.push_back("fradi"); user_id.push_back("crodo"); user_id.push_back("abc123"); user_id.push_back("frodoc");
	banned_id.push_back("*rodo"); banned_id.push_back("*rodo"); banned_id.push_back("******"); 
	cout << solution(user_id, banned_id);
	return 0;
}