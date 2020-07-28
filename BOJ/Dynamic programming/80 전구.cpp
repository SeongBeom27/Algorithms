#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXLEN 201
#define INF 987654321
using namespace std;
int n, k;
int map[MAXLEN];
// �־��� ���� �Ͽ� dp[left][right]�� [left, right] ������ ���� ���� ���� 
// ���� ������ ���� �� �ִ� ����� �ּڰ�
int dp[MAXLEN][MAXLEN];
/*
	1. ��ǥ : ��� ������ ���� �ϳ��� ������ ������ �ּ� ��� ������ ���� �ٲپ�� �ϴ����� ������.

	2. ����

	�� ������ ������ �ٲ� �� �ִµ�, �ϳ��� ���� ���� �ٲٴ� ���!

	-> ���� �ٲ�� ������ ������ ������ ���� ���̸�, �� ������ ���� ���� �ٲ�� �Ǹ�
	   ������ ������ �ٸ� ���� ���� ������ ��� �ٲ�� �ȴ�
*/

int solution(int left, int right)
{
	if (left == right) return 0;
	int& result = dp[left][right];
	if (result != -1)
		return result;
	result = INF;
	for (int i = left; i < right; i++)
	{
		int temp = (map[left] != map[i + 1] ? 1 : 0);
		result = min(result, solution(left, i) + solution(i + 1, right) + temp);
	}
	return result;
}

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> map[i];
	memset(dp, -1, sizeof(dp));
	cout << solution(1, n);
	return 0;
}