#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int t, k;
pair<int, int> p[100];
int dp[10001][101];

int solution(int cash, int idx)
{
	// ���� ���
	if (cash == 0) return 1;
	if (idx >= k) return 0;
	int& result = dp[cash][idx];
	if (result != -1)
	{
		return result;
	}

	result = 0;
	// �ش� ������ ������� �ʴ� ���(i == 0) ~ n(i == p[idx].second) �� ����ϴ� ������ �����ֱ�
	for (int i = 0; i <= p[idx].second; i++)
	{
		// cash�� ������ �Ǹ� �ȵǹǷ�
		if (cash - (p[idx].first * i) >= 0)
			// ��� ����� ���� ã�� ��� ���� ��ʿ��� ������ ��� 1�� return���༭ ���� �����ִ� ��� ���
			result += solution(cash - (p[idx].first * i), idx + 1);
	}

	return result;
}

int main()
{
	cin >> t >> k;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < k; i++)
	{
		cin >> p[i].first >> p[i].second;
	}
	cout << solution(t, 0);
	return 0;
}