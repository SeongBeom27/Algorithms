#include <iostream>
#define MOD 1000000003
#define MAX 1000
using namespace std;
int n, k; int dp[MAX + 1][MAX + 1];
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = 1;
		dp[i][1] = i;								// dp[i][1]�� i�� �ȴ�.
	}
	// i ��° ĭ�� ĥ�ϴ� ��� = dp[i - 2][j - 1]
	// i ��° ĭ�� �� ĥ�ϴ� ��� = dp[i - 1][j]
	// dp[i][j] = dp[i - 2][j - 1] + dp[i - 1][j]
	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= n; j++)
		{
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
		}
	}

	// n��° ĭ�� ĥ�ϴ� ���
	// 1��ĭ, n - 1��° ĭ�� ĥ�ϸ� �ȵǴϱ� 2 ~ N - 2��° ĭ ����  K - 1 ���� ���� �������� �ʰ� ĥ�ϴ� ����̹Ƿ�
	// n - 3�� ������ n���� ����ȯ�߿� 1, n - 1, n �� �� ������ ���� ��  k - 1���� ��ĥ�Ǿ�� �ϹǷ�
	// dp[N - 3][K - 1] �̴�.

	// n��° ĭ�� ĥ���� �ʴ� ���
	// 1 ~ (N - 1) ��° ĭ���� K���� ���� �������� �ʰ� ��ĥ�ϴ� ����̹Ƿ�
	// dp[n - 1][k]
	cout << (dp[n - 3][k - 1] + dp[n - 1][k]) % MOD;
	return 0;
}