#include <iostream>
#define mod 1000000000
using namespace std;
int dp[101][11];
int main()
{
	int n; cin >> n;
	long long ans = 0;
	// 길이가 1일때는 전부 1을 넣어준다.
	for (int i = 1; i <= 9; i++)
	{
		dp[1][i] = 1;
	}
	for (int i = 2; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			if (j == 0)
			{
				dp[i][0] = dp[i - 1][1] % mod;
			}
			else if (j == 9)
			{
				dp[i][9] = dp[i - 1][8] % mod;
			}
			else {
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % mod;
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		ans += dp[n][i];
	}
	ans = ans % mod;
	cout << ans;
	return 0;
}