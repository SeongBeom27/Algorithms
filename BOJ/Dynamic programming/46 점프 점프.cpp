#include <iostream>
#include <cstring>
using namespace std;
int a[1001];
int dp[10001];
int main()
{
	int n; cin >> n;
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) cin >> a[i];

	dp[1] = 1;
	// �������� �� �ƹ����� ������ ���� ��������Ѵ�.
	for (int i = 1; i < n; i++)
	{
		if (dp[i] == 0) break;
		for (int j = 1; j <= a[i]; j++)		// �� �� �ִ� ĭ
		{
			if (i + j > 1000) break;
			if (dp[i + j] > dp[i] + 1 || dp[i + j] == 0)
			{
				dp[i + j] = dp[i] + 1;
			}
		}
	}
	if (dp[n] == 0) cout << -1;
	else cout << dp[n] - 1;
	return 0;
}