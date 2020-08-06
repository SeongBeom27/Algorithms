#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 31
using namespace std;
// https://www.acmicpc.net/problem/2133
/*
	���� ����

	1. Ȧ���� ���� Ÿ���� ���� �� ����.
*/
int n;
int dp[MAX];

int solution(int width)
{
	// ���� ���
	if (width % 2 == 1)
		return 0;
	else if (width == 0)
		return 1;
	else if (width == 2)
		return 3;

	int& result = dp[width];
	if (result != -1)
		return result;

	result = 3 * solution(width - 2);

	// �� �� ��������� 2�����ִ�.
	for (int i = 0; i <= width - 4; i++)
		result += 2 * solution(i);

	return result;
}

int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	cout << solution(n);
	return 0;
}