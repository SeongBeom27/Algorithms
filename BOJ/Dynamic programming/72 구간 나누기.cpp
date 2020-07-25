#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MININF -98765321
#define MAX 101
using namespace std;
// n ���� ���� �̷���� 1���� �迭
// m ���� ������ �����ؼ� ������ ���� ������
int n, m;
int a[MAX];
// dp[i][m][2] �� i ��ġ�� m ������ [1] ���Խ�Ų ���,[0] �� ���Խ�Ų���
int dp[MAX][MAX / 2][2];

void initialize()
{
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX / 2; j++)
			for (int k = 0; k < 2; k++)
				dp[i][j][k] = MININF;
}

int solution(int idx, int term, bool choice)
{
	// ���� ���� ( ������ �� ä�� ��� )
	if (term == m) return 0;

	// ���� ���
	if (idx == n + 1)
	{
		// ������ ������ ���� ���� ����
		if (term == m - 1 && choice)
		{
			return 0;
		}
		else {
			// �� ���� �ּڰ� ��������
			return -32768 * 100;
		}
	}

	int& result = dp[idx][term][choice];
	if (result != MININF)
		return result;

	// ���ο� ���� ( choice�� �� ���)
	if (!choice)
	{
		// �׳� ����ġ�� , idx���� �����ϱ�
		return result = max(solution(idx + 1, term, false), a[idx] + solution(idx + 1, term, true));
	}
	else {
		// ���� ������ (idx - 1 ������ ������ ���) , ���� ������ �߰��ϱ�
		return result = max(solution(idx + 1, term + 1, false), a[idx] + solution(idx + 1, term, true));
	}
}

int main()
{
	cin >> n >> m;
	// MININF�� ���� ������ �������� -32768���� �־����⶧��
	// memset(dp, -1, sizeof(dp)); <- -1���ϴ� memset�� ������ �Ұ��ϴ�.
	initialize();
	// m���� ������ �����ؼ� ������ ���� ������ ������ �ִ밡 �ǰ� �ؾ��Ѵ�.
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	cout << solution(1,0,false) << endl;
}