#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXINF 987654321
#define MAX 100001
using namespace std;
int n, t;
int graph[MAX][4];		// (1, 1) ���� ������ ���̴�.
int dp[MAX][4];			// idx��, column������ ���� �ּ� ���
/*
	�ﰢ �׷���

	�ǹ� : N �� 3 ���� �̷���� �׷���
	��ǥ : 1�� ��� ���� -> N�� ��� ���������� �ּ� ����� ���

	����

	1. ������ �ƴ϶� ������ ����� ���� ( ����(?) �� �ƴϰ� ���� )
*/

// �Ʒ�, ������ �Ʒ�, ���� �Ʒ�, ������
int dx[] = { 1, 1, 1, 0 };
int dy[] = { 0, 1, -1, 1 };
int solution(int idx, int column)
{
	// ���� ���
	if (idx > n || column > 3) return MAXINF;

	// ����
	if (idx == n && column == 2) return graph[n][2];

	int& result = dp[idx][column];
	if (result != -1)
		return result;

	result = MAXINF;
	// ���� ������ �� 4�� 
	for (int k = 0; k < 4; k++)
	{
		int next_x = idx + dx[k];
		int next_y = column + dy[k];

		// �׷��� ���� ���� �ִ� ���
		if (next_x >= 1 && next_x <= n && next_y >= 1 && next_y <= 3)
		{
			 result = min(result, graph[idx][column] + solution(next_x, next_y));
		}
	}
	return result;
}

int main()
{
	int test_case = 0;
	int onemore;
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		// ���� ��� ���� ��ƺ��ô�
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= 3; j++)
				cin >> graph[i][j];

		memset(dp, -1, sizeof(dp));
		cout << ++test_case << ". " << solution(1, 2) << endl;
	}

	return 0;
}