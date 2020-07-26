#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 1001
#define MOD 1000000
using namespace std;
//https://www.acmicpc.net/problem/1563
int n;
// dp[n][i][j] , n�� �߿� i�� ����, "����" j �� �Ἦ�� �� ���
// �迭�� ���� ������ ���� �ε��� 1���� �����ϱ�� �ߴ�.
long long dp[MAX][3][4];
/*
	O : �⼮, L : ����, A : �Ἦ

	���ٻ� �� �޴� ����

	-> ������ �� �� �̻� or �Ἦ �� �� �������� �� ���

	1 �б�� N���̴�.
	-> N�� �־����� �� ���ٻ��� ���� �� �ִ� ��������� ������ ���� ���α׷��� �ۼ��϶�

	���� ���

	1. �⼮, ���� , �Ἦ�� �� �� ���� ���ϰ� 0 , 1 , 2 �� ���ڷ� �ٲ۴�.

	2. N�߿� 1�� �� �� �� or 2�� ���� 3�� �ִ� ��� ���� ���� �� �޴´�.
*/

long long solution(int day, int late, int absent)
{
	if (day == n)
	{
		if (late == 2 || absent == 3)
			return 0;
		else
			// ���ٻ� �޴� ���
			return 1;
	}
	// ���ٻ� �� �޴� ���
	if (late == 2 || absent == 3) return 0;

	long long& result = dp[day][late][absent];
	if (result != -1)
		return result;

	result = 0;
	// �Ἦ�� �� ���
	//result += solution(day + 1, late, absent + 1);
	// �Ἦ�� �������̾���ϹǷ� �Ἦ���� ���� �� (���� or ���� �⼮)
	// �� �Ἦ�� 0���� �ʱ�ȭ���ش�.
	// ������ �� ���
	//result += solution(day + 1, late + 1, 0);
	// ����, �Ἦ �Ѵ� ���� ���
	//result += solution(day + 1, late, 0);
	
	return result += (solution(day + 1, late, absent + 1) + solution(day + 1, late + 1, 0)
		+ solution(day + 1, late, 0)) % MOD;
}

int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	// ù�� ���� �⼮�� ���, ������ ���, �Ἦ�� ��츦 ���� �����ش�.
	cout << (solution(1, 0, 0) + solution(1, 0, 1) + solution(1, 1, 0)) % MOD;
	return 0;
}