#include <iostream>
#include <algorithm>
#include <cstring>
#define  MAX 50000
using namespace std;
int total, sub;
int seat[MAX + 1];
int dp[3][MAX + 1];		// n ���� �������� k���� ����������� �ִ�� ����� �� �ִ� �մ��� ��
// https://www.acmicpc.net/problem/2616
// ����簡 ���� ���� ������ ���� �� ������ Ÿ�� �ִ� �մ��� ��.
// ���� ������� �ִ�� �� �� �ִ� ������ ���� �־��� ��
// ���� ����� 3�밡 �ִ�� ����� �� �ִ� �մ��� ���� ���Ͽ���
// ( ���� ������� ��ȣ�� ���������� �̾��� ������ �� �� �ִ�. )

// �˰���
// �ش� ĭ�� ���� ���� �ʰų�
// �ش� ĭ�� �ִ� �� �� �ִ¸�ŭ ���� ����.

int solution(int trainnum, int idx)			// train number, n ��������
{
	// ���� ���
	if (trainnum == 3 || idx >= total) return 0;

	int& result = dp[trainnum][idx];
	if (result != -1) return result;

	result = 0;

	if (idx + sub - 1 <= total)
	{
		int x, y = 0;
		for (x = idx; x < idx + sub; x++)
		{
			y += seat[x];
		}
		// idx ��° ������ �� ���� ���, ���� ���
		// �ִ��� ã�� ��� ������ ���� ������ ���ؼ� return�ؼ� ū ���� result�� �־��ش�.
		result = max(solution(trainnum, idx + 1), solution(trainnum + 1, idx + sub) + y);
	}
	return result;
}

int main()
{
	cin >> total;
	for (int i = 1; i <= total; ++i)
		cin >> seat[i];
	cin >> sub;

	memset(dp, -1, sizeof(dp));
	cout << solution(0, 1);

	return 0;
}