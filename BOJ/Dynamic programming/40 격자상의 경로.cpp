#include <iostream>
#include <cstring>
using namespace std;
int n, m, k;
int a[16][16];
int dp[16][16];
int main()
{
	cin >> n >> m >> k;
	if (k)
	{
		int mid_i, mid_j;
		// 1��° ĭ���� n*m ĭ ��� ���ʷ� ä��ϴ�.
		int count = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				count++;
				// ���� ĭ�� k��° ĭ�̸� mid_i, mid_j�� �������ݴϴ�.
				if (count == k) {
					mid_i = i;
					mid_j = j;
				}
			}
		}
		dp[1][1] = 1;
		for (int i = 1; i <= mid_i; i++) {
			for (int j = 1; j <= mid_j; j++) {
				if (i == 1 && j == 1) continue;
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		int mid = dp[mid_i][mid_j];

		memset(dp, 0, sizeof(dp));
		dp[mid_i][mid_j] = 1;
		for (int i = mid_i; i <= n; i++)
		{
			for (int j = mid_j; j <= m; j++)
			{
				if (i == mid_i && j == mid_j) continue;
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		cout << mid * dp[n][m];
	}
	else {
		dp[1][1] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (i == 1 && j == 1) continue;
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		cout << dp[n][m];
	}
	return 0;
}