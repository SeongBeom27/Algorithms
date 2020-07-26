#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstring>
#define MAXCOST 301
#define MAXCOMP 22
using namespace std;
//https://www.acmicpc.net/problem/2662
int n, m;
int table[MAXCOST][MAXCOMP];
// dp[n][m] : m ������� n��ŭ �������� �� ���� �� �ִ� �ִ����ͱ�
int dp[MAXCOST][MAXCOMP];
// investment[���� �����ϰ� �ִ� �ݾ�][���ڱݾ�]�� ����ϰ� ���� �����ϰ� �ִ� �ݾ��� �������ش�.
int investment[MAXCOST][MAXCOMP];
/*
	- ���� ���� -

	�� ����� ���� �������� �� �̵� �� �� �ִ� �̵� ���̺��� �־�����.
	���ھ��� �������ְ�, �� ����� �������� �� 
	���� ���� ������ ���� �� �ִ� ���� ���, ���ͱ��� ���ϴ� ���α׷��� �ۼ��϶�

	- ���� ���� -

	���� ����� ���� ������ ���ڴ� �Ұ����ϴ�.

	- ��� -

	�ִ����ͱ��� ã���� ��, 1 ~ m ������� �� �� �󸶳� �����߰�, �� ���ͱ��� ���

	1 ~ m ������� �� �� �󸶳� �����ߴ��� <- �� �κ� ã�� ���� �߿�
*/

int solution(int company, int money)
{
	// ���� ���
	if (company == m + 1 || money == 0) return 0;
	
	int& result = dp[money][company];
	if (result != -1)
		return result;

	for (int i = 0; i <= money; i++)
	{
		// ���� company���� money��ŭ �����ϴ� ���
		int now = solution(company + 1, money - i) + table[i][company];
		if (result < now)
		{
			// [���� �����ϰ� �ִ� �ݾ�][���ڱݾ�] �� �־��ش�.
			
			investment[money][company] = i;   /****/
			result = now;
		}
	}

	return result;
}

int main()
{
	cin >> n >> m;
	memset(table, 0, sizeof(table));
	memset(investment, 0, sizeof(investment));
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			cin >> table[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	// ���ڱ� n�� �Ѱ��ش�.
	cout << solution(1, n) << endl;
	/***********/
	for (int i = 1; i <= m; i++)
	{
		// ù��° : ������ �ݾ��� n�� �� 1��° ȸ�翡 ������ �ݾ�
		// �ι��� : ������ �ݾ��� n�� �� 2��° ȸ�翡 ������ �ݾ�
		//                            .
		//                            .
		//                            .
		// m��° : ������ �ݾ��� n�� �� m��° ȸ�翡 ������ �ݾ�
		cout << investment[n][i] << " ";
		n -= investment[n][i];
	}
	return 0;
}