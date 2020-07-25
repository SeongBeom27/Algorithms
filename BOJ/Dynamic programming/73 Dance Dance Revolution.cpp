#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;
int order[MAX];
// idx ���� left, right�� �� ��ġ�� ��� ���� ��� �ּڰ�
int dp[MAX][5][5];
int n = 0;
/*
	DDR ������

	  1
	2 0 4
	  3

	���� ����

	���� 1. ����, ������ ���� ���� �����δ�. ( �� �� ����x )
	���� 2. �� ���� ���� ��ġ�� ���� �� ����.

	��� ����

	1. �߾ӿ� �ִ� ���� �̵��ϸ� �� : 2
	2. �밢������ �̵��ϸ� �� : 3
	( �� : ���� - > ��, ���� -> �Ʒ� )
	3. �ݴ�� �����̸� �� : 4
	( �� : �� -> �Ʒ�, ���� -> ������ )
	4. ���� ������ �ѹ� �� ������ �� : 1
*/
int calculation(int start, int end)
{
	// �߾ӿ� �ִ� ���� �̵��ϴ� ���
	if (start == 0)
	{
		return 2;
	} else if(abs(start - end) == 2)
	{
		// �ݴ�� �̵��ϴ� ���
		return 4;
	}
	else if (start - end == 0)
	{
		// ���� ��ġ�� ��� ���
		return 1;
	}
	else {
		// �밢������ �̵��Ϸ��� ���
		return 3;
	}
}

int solution(int idx, int left, int right)
{
	// ���� ����
	if (idx == n + 1) return 0;

	// ���� ���, �� ���� ���� ���� ������ �ȵȴ�.
	if (left != 0  && left == right)
		return 987654321;
	
	int& result = dp[idx][left][right];

	if (result != -1)
		return result;

	// �޹߷� idx ��ġ�� �ű�� ���
	// solution(idx + 1, order[idx], right) + calculation(left, order[idx])
	// �����߷� idx ��ġ�� �ű�� ���
	// solution(idx + 1, left, order[idx]) + calculation(right, order[idx])
	return result = min(solution(idx + 1, order[idx], right) + calculation(left, order[idx]),
		solution(idx + 1, left, order[idx]) + calculation(right, order[idx]));
}
int main()
{
	int temp;
	while (1)
	{
		scanf("%d", &temp);
		if (temp == 0) break;
		n++;
		order[n] = temp;
	}
	memset(dp, -1, sizeof(dp));
	cout << solution(1, 0, 0) << endl;
	return 0;
}