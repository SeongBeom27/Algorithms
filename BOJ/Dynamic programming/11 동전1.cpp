#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int coins[101];
int dp[100001] = { 0, };
int cnt = 0;

int main()
{
	// ����� ���� 2^31 ���� �����Ƿ� int������ ����ص� �ȴ�.
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> coins[i];
	}
	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = coins[i]; j <= k; j++)
		{
			if (j - coins[i] >= 0)
			{
				dp[j] += dp[j - coins[i]];			// �� ��ȭ���� ��� ���Դ���
			}
		}
	}

	cout << dp[k];
	return 0;
}