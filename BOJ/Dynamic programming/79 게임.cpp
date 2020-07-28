#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#define INF 987654321
#define MININF -987654321
#define MAX 51
using namespace std;
// https://www.acmicpc.net/problem/1103
/*
	 1. H�� ASCII : 72�̹Ƿ� �׳� int�� ���� ������ ������ ������ �����Ƿ� int �迭�� ����ϰڴ�.
	 
	 2. �����̰� ������ ���ѹ� ������ �� �ִٸ� -1�� ����Ѵ�. ( ����Ŭ�� ����� ��� )
*/
int n, m;
string cmap[MAX];
int map[MAX][MAX];
bool check[MAX][MAX];
// dp[n][m] : n�� m���� �湮���� �� ���� �ִ� ������ ������ ��
int	dp[MAX][MAX];

int solution(int x, int y)
{
	// ���̻� ������ ���
	if (x < 1 || x > n || y < 1 || y > m || map[x][y] == 'H')
		return 0;
	// ����Ŭ�� ����� ���
	if (check[x][y])
	{
		cout << -1;
		exit(0);
	}		

	int& result = dp[x][y];
	if (result != MININF)
	{
		return result;
	}
	check[x][y] = true;
	// ������ �� �ִ� ��
	int move = map[x][y];
	int dx[] = { move, -move, 0, 0 };
	int dy[] = { 0, 0, move, -move };
	// ������ ��� �� �� ���� ��츦 �ƴ� ���� �߿�
	for (int k = 0; k < 4; k++)
	{
		int next_x = x + dx[k];
		int next_y = y + dy[k];
		result = max(result, solution(next_x, next_y) + 1);
	}
	// check = false�� ���ִ� ������
	// �� ��η� ���� �� �湮�� ���̹Ƿ� ���߿� �ٸ� ��η� ���Ƽ� ���� ��쿡�� �湮�� ���̶�� �߸�
	// �߸��̴�.

	// for�� �ۿ� ���ִ� ������
	// ���� ���� x, y���� �°��� �翬�ѰŰ� �ű⼭ ���� ���� �̱� �����̴�.
	check[x][y] = false;
	return result;
}


int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dp[i][j] = MININF;
	
	for (int i = 1; i <= n; i++)
		cin >> cmap[i];
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (cmap[i][j - 1] == 'H')
				map[i][j] = cmap[i][j - 1];
			else map[i][j] = cmap[i][j - 1] - '0';
		}
	}
	
	cout << solution(1, 1);
	return 0;
}
