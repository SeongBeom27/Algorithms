#include <iostream>
#include <algorithm>
#include <cstring>
#define CHU_MAX 30
#define GU_MAX 7
#define CHU_WEIGHT 40000
using namespace std;

/*
	1g, 4g �߰� ���� ���

	��1 : �־��� ������ 1g �߸� ���� ���� ���￡ �÷� ������ �����̸� �־��� ������ 1g�̶�� ���� �� �� �ִ�.
	��2 : ������ 4g���� Ȯ���غ����� 4g�� �� �ϳ��� �÷��� ��� ������ �Ǵ� ���� �� �� �ִ�.

	��ǥ : �־��� �߸��� �̿��ؼ� ������ ���Ը� Ȯ���� �� �ִ���
*/


int chu_n;
int chu_weight[CHU_MAX + 1];

int gu_n;
int gu_weight[GU_MAX + 1];


// �ִ� �߷� ���� �� �ִ� ��� ���Ը� dp�� ������.
// �ߵ鳢�� ���� or �������� ������ ��� ���Ը� ���� �� �ִ�.

// dp[i][weight] :  i��° �߱��� �̿��ؼ� weight�� ���� �� �ִ��� ����
int dp[CHU_MAX + 1][CHU_WEIGHT + 1];

int solution(int chu_idx, int weight)
{
	// ���� ��� (�߸� �� ����ߴµ��� weight�� 0�� �ƴ� ��� )
	if (weight != 0 && chu_idx == 0)
		return 0;

	// ���� ����
	if (weight == 0)
		return 1;

	int& result = dp[chu_idx][weight];
	if (result != -1)
		return result;

	// �ϳ��� ������ ����� ����
	if (solution(chu_idx - 1, weight - chu_weight[chu_idx]) || solution(chu_idx - 1, weight + chu_weight[chu_idx])
		|| solution(chu_idx - 1, weight))
		return result = 1;
	return result = 0;
}

void Input()
{
	// ��
	cin >> chu_n;
	for (int i = 1; i <= chu_n; i++)
		cin >> chu_weight[i];

	// ����
	cin >> gu_n;
	for (int i = 1; i <= gu_n; i++)
		cin >> gu_weight[i];
}

int main()
{
	Input();
	memset(dp, -1, sizeof(dp));
	// ���� �� ������ �̿��ؼ� ���� �ִ� ���Ա��� ���� �� �ִ� ���
	for (int i = 1; i <= gu_n; i++)
	{
		if (solution(chu_n, gu_weight[i]))
		{
			cout << "Y ";
		}
		else {
			cout << "N ";
		}
	}
	
	return 0;
}