#include <iostream>
#include <algorithm>
#include <cstring>
#define INF 987654321
#define MAX 301
//https://www.acmicpc.net/problem/2157
using namespace std;
/*
	���� ����

	1. N���� ������ ���ʿ��� �������� "�������" ��ġ�� �ִ�.
	2. ���� ��δ� M�� ������ ���ø� 1������ �����ؼ� N�� ���ÿ��� ������ �Ѵ�. ( M���� ���ÿ� ���Ե� )
	3. ���� ��ȣ�� �����ϴ� ������θ� �̵��ϱ�� �ߴ�. ( �������θ� �̵� )
	4. ���ø��� �ٸ� ���÷� �� �� �ִ� ���� �������ִ�. �׸��� �⳻�� ������ �������ִ�.
	
	���

	-> M���� ���ø� �����Ǿ� �ִ� �׷θ� ���� ���鼭 �԰� �Ǵ� �⳻�� ������ �ִ�
*/

int n, m, k;
int a, b, c;
// route[i][j] : i -> j �� �� ��, �⳻���� ����
int route[MAX][MAX];
// dp[i][j[vist]] : i -> j �� �� ������ visit���� ���ø� ������ ��� �⳻���� �ִ� ����

// -> dp[cur][visit] : ���� ���ñ��� vist���� ���ø� ������ �� ��� �⳻���� �ִ� ����
int dp[MAX][MAX];

int solution(int cur, int visit)
{
	// ���� ��� : m���� ���ø� �����µ� n ���ÿ� �������� ���� ���
	if (visit == m && cur != n)
		return -INF;
	
	// ���� ����
	if (cur == n)
		return 0;

	int& result = dp[cur][visit];
	if (result != -1)
		return result;
	
	result = 0;
	// ����ϴ� ������ �� �� �ִ� ���� ������. x
	// ���ʹ������θ� �� �� �ִ�.
	for (int i = cur + 1; i <= n; i++)
	{
		// �׷ΰ� ���ų�, ����� ���� �����ϴ� ���� ���ų�, �湮�ߴ� ���ö�� continue
		if (route[cur][i] == -1 || i == cur) continue;
		result = max(result, solution(i, visit + 1) + route[cur][i]);
	}

	return result;
}

int main()
{
	cin >> n >> m >> k;
	memset(dp, -1, sizeof(dp));
	memset(route, -1, sizeof(route));
	for (int i = 1; i <= k; i++)
	{
		cin >> a >> b >> c;
		// a ���ÿ��� b ���÷� �� �� c ������ �⳻���� ���� �� �ִ�.
		// route[1][3] ���� �ߺ��� �Ͼ�� 
		// 1������ 3������ �� �� �ִ� ��ΰ� ���� ���� ���� �� �ִٴ� ��

		// a ���� b�� ���� ��ΰ� �ߺ��Ǿ� �ִٸ� �� �⳻�� ������ ���� �͸� �ִ´�.
		if (route[a][b] != -1)
		{
			route[a][b] = max(c, route[a][b]);
		}
		else {
			route[a][b] = c;
		}		
	}
	cout << solution(1, 1);

	return 0;
}