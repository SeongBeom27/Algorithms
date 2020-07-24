#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#define MAX 16 + 1
#define INF 987654321
int min(int a, int b) { return a < b ? a : b;}
using namespace std;
int n;
int p;
int cost[MAX][MAX];
// �������� ���°� string���� �־������� 'Y' = 1, 'N' = 0���� �ٲپ ��Ʈ ���·� ǥ���ϸ� 
// �޸������̼��� �� �� �ֱ� ������ ��Ʈ����ŷ�� �̿��߽��ϴ�.
int bit = 1 << MAX;
// dp[n][m] �� n ������, ������ ��������
int dp[MAX][1 << MAX];
string state;


// ��Ʈ ���� 1 ���� ��
int countone(int x)
{
	int cnt = 0;
	while (x)
	{
		cnt += x & 1;
		x >>= 1;
	}
	return cnt;
}

int solution(int idx, int curstate)
{
	// ���� ����
	// -1 ���ִ� ������ bit = 1 << MAX �̱� ������ �� ���ʿ� 1�� �ֱ� �����̴�.
	// ���� ������ ��� 0�� �������ִ� ������ 
	// result = min(result, cost[idx][i] + solution(i, nextState)); �� �ٿ���
	// cost[idx][i]�� �����ֱ� ������ 0�� �������ָ� ����� ���� ���� ���� ���� �� �ִ�.
	if (countone(curstate) - 1 >= p)
		return 0;

	int& result = dp[idx][curstate];
	if (result != -1)
		return result;

	result = INF;
	for (int i = 0; i < n; i++)
	{
		if ((curstate & (1 << i)) == 0)		// i��° �����Ұ� �����ִ� �������� ���
		{
			int nextState = curstate | (1 << i);		// �� i��° �����Ҹ� �� ���·� �����

			// ���� �����ִ� �����ҿ� ���ؼ� �ٽ� ��������.
			// idx �����Һ��� ��� i��° �����Ҹ� �� �����ұ��� �����ִ� ��� �����ҿ��� �ٽ� �����ִ� �����Ҹ� ���� �Ѻ���. �� �� ����� �ּڰ��� result�� ���� �� ���̴�.
			for (int j = 0; j < n; j++)
			{
				if ((nextState & (1 << j)))				
					result = min(result, cost[idx][i] + solution(j, nextState));
			}
		}
	}

	return result;
}

int main()
{
	// n���� �����Ұ� �ְ� ��� p���� �����Ұ� ���峪�� �ʰ� �ؾ��Ѵ�.
	// ��  i ������fh j �����Ҹ� ������� �� ����� �߻��ϰ� �װ��� �迭�� ��Ÿ�� �ִ�.

	// �Ұ����� ��� -1 ���
	// ��� p��ŭ �����Ҹ� ���ľ��ϴ� ��
	cin >> n;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> cost[i][j];
		
	cin >> state >> p;
	
	for (int i = 0; i < state.length(); i++)
	{
		if (state[i] == 'Y')
			bit |= (1 << i);
	}

	if (p == 0)
		cout << 0 << endl;
	else {
		memset(dp, -1, sizeof(dp));
		int result = INF;
		for (int i = 0; i < n; i++)
		{
			if (state[i] == 'Y')
				result = min(result, solution(i, bit));
		}

		if (result == INF)
			cout << -1 << endl;
		else
			cout << result << endl;
	}

	return 0;
}