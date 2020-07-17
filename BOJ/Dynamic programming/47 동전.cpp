#include <iostream>
#include <cstring>
using namespace std;
int coin[21];
int dp[10001];
int main()
{
	int t; cin >> t;
	int n, m;
	while (t--)
	{
		memset(coin, 0, sizeof(coin));
		memset(dp, 0, sizeof(dp));
		cin >> n;
		int ans = 0;
		// n ���� ������ �ݾ��� ������������ ���ĵǾ� �־�����.
		for (int i = 0; i < n; i++)
		{
			cin >> coin[i];	// ����� �� �ִ� ȭ���� ����
		}
		cin >> m;			// coin�� �ִ� ������� ���� �ݾ� m
		// �������� ���� �� �ִ� ��� ������ ������?
		for (int i = 0; i < n; i++)
		{
			dp[coin[i]]++;
			for (int j = coin[i] + 1; j <= m; j++)
			{
				dp[j] = dp[j] + dp[j - coin[i]];
			}
		}
		cout << dp[m] << endl;
	}
	return 0;
}

