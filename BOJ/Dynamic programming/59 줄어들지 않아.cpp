#include <iostream>
using namespace std;
// 0011, 1111, 1112, 1122, 2223 �� �پ���� �ʴ� �����̴�.
// n�ڸ� ���� �پ���� �ʴ� ���� ���ض�
int n;
long long dp[65][10];			// 1 <= n <= 64
					// dp[n]�� n�ڸ� ���� �پ���� �ʴ� ���� ����
int main()
{
	int t; cin >> t;
	for (int i = 0; i < 10; i++)
	{
		dp[1][i] = 1;
	}
	for (int i = 2; i <= 64; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 9; k >= j; k--)
			{
				dp[i][j] += dp[i - 1][k];
			}
		}
	}

	while (t--)
	{
		cin >> n;
		long long ans = 0;
		for (int i = 0; i < 10; i++)
		{
			ans += dp[n][i];
		}
		cout << ans << endl;
	}
	return 0;
}