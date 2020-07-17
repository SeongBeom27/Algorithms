#include <iostream>

#define MAX 1000
#define R_INF -987654321
using namespace std;

int n, m, ans;
int a[MAX][MAX];
int dp[MAX][MAX][3];		// dp[a][b][c]�� a,b���� c�������� ������ ���� �ִ�
bool visit[MAX][MAX];

int dx[] = {0, 0, 1};
int dy[] = {1, -1, 0};

int max(int A, int B) { 
	if (A > B) return A; 
	return B; 
}
int dfs(int x, int y, int Dir)
{
	if (x == n - 1 && y == m - 1) return a[x][y];
	if (dp[x][y][Dir] != R_INF) return dp[x][y][Dir];		// �湮�ߴ� ���̸� �� �� ����

	visit[x][y] = true;
	int big_value = R_INF;

	for (int i = 0; i < 3; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < m)
		{
			if (visit[nx][ny] == false)
			{
				big_value = max(big_value, dfs(nx, ny, i));
			}
		}
	}
	visit[x][y] = false;		// �ٽ� false�� ����� �Ѵ�.
	dp[x][y][Dir] = a[x][y] + big_value;
	return dp[x][y][Dir];		// dfs�� ���� ���� �̰����� �����ϰ� �ȴ�.
}

void solution()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dp[i][j][0] = R_INF;
			dp[i][j][1] = R_INF;
			dp[i][j][2] = R_INF;
		}
	}

	ans = dfs(0, 0, 0);
	cout << ans << endl;
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	
	solution();
	return 0;
}