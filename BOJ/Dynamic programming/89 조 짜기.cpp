#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 1001
using namespace std;
int n;
int people[MAX]; 
int dp[MAX];				\
int solution(int age)
{
	if (age == n + 1) return 0;

	int& result = dp[age];
	if (result != -1)
		return result;

	result = 0;
	int low = 10001, high = -1;

	for (int i = age; i <= n; i++)
	{
		low = min(low, people[i]);
		high = max(high, people[i]);

		result = max(result, (high - low) + solution(i + 1));
	}
	return result;
}

/*
	����

	�������� ���� �� ¥���ϰ�, �л����� ������ �־����� ��, ���� �� ¥���� ������ �ִ��� ���ؾ��Ѵ�.
	���ϴ� �л���� �� ���ϴ� �л����� ���� ���� ����� �Ѵ�.

	���� ����

	1. ���� ���� ���ϰ� �� �л����� ���� ���̰� ���� �� ��쿡 ������ �������� ȿ���� ����.
	2. �������̰� ���� �ȳ��鼭, ���� ���̰� ���̳��� �Ѵ�.
	
	�� ��ǥ
	
	�� ¥���� ���� : ���� ������ ���� �л��� ����, ���� ������ ���� �л��� ���� ����
*/

int main()
{
	cin >> n; memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++)
		cin >> people[i];

	cout << solution(1);

	return 0;
}