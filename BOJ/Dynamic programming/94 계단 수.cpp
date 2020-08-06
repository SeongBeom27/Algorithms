#include <iostream>
#include <cstring>
#include <algorithm>
#define MAXLEN 100
#define MOD 1000000000
using namespace std;

int n;
// 0 ~ 9���� ��� ���Դ´��� üũ
int check = (1 << 10);

// n��° ��ġ�� 0 ~ 9���� �� ���ڰ� k�� �� ��� ���Ե� ��� ���� �� ��ִ��� ���ϴ� �Լ�
int dp[MAXLEN + 1][1 << 10][10];

int solution(int len, int state, int next)
{
	if (len == n)
	{
		// ��� ���� �� �ִٸ� ����
		if ((((check - 1) << 1) + 1 == state))
			return 1;
		else
			return 0;			// ���� ���
	}

	int& result = dp[len][state][next];
	if (result != -1)
		return result;
	result = 0;

	if (next == 0)
		result += solution(len + 1, state | (1 << 1), 1);
	else if (next == 9)
		result += solution(len + 1, state | (1 << 8), 8);
	else
		result += ((solution(len + 1, state | (1 << next + 1), next + 1))) +
		solution(len + 1, state | (1 << next - 1), next - 1);

	result %= MOD;


	return result;
}

int main()
{
	cin >> n;

	int result = 0;

	for (int i = 1; i <= 9; i++)
	{
		memset(dp, -1, sizeof(dp));
		result += solution(1, 1 << 10 | (1 << i), i);

		result %= MOD;
	}

	cout << result;
	return 0;
}
