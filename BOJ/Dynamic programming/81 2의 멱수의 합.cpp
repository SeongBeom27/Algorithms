#include <iostream>
#include <cstring>
#include <math.h>
#define MOD 1000000000
#define MAX 1000001
using namespace std;
int n;
// dp[n][k]�� 2^k�� �� k�� �Ἥ n�� 2�� ��� ������ ��Ÿ�� �� �ִ� �� ����� ��
int dp[MAX][20];
int klimit = 0;
int solution(int total, int k)
{
	if (total < 0) return 0;
	if (total == 0) return 1;
	if (k == klimit + 1) return 0;
	int& result = dp[total][k];
	if (result != -1)
		return result;

	result = 0;
	return result += (solution(total - pow(2, k), k) % MOD + solution(total, k + 1) % MOD) % MOD;
}

int main()
{
	cin >> n;
	int temp = n;
	while (temp != 1)
	{
		temp /= 2;
		klimit++;
	}
	memset(dp, -1, sizeof(dp));
	cout << solution(n, 0);
	return 0;
}