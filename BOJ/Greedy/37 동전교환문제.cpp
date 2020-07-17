#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 100
using namespace std;
int k[MAX];
int min_cnt = 10000; // ����
void BruteForceChange(int M, vector<int> &c, int d, int index, int cnt, int sum, int dp[])
{
	// index : c�� �ε���
	// cnt ���� ����
	if (index == d) return;
	if (sum == M)
	{
		if (cnt < min_cnt)
		{
			min_cnt = cnt;
			for (int i = 0; i < d; i++)
			{
				k[i] = dp[i];
			}
		}
	}
	// ���� �ε��� ������ �ְ� �Ѿ�� ���
	if (sum + c[index] <= M)
	{
		sum += c[index];
		dp[index] += 1;
		cnt++;
		BruteForceChange(M, c, d, index + 1, cnt, sum, dp);
		cnt--;
		sum -= c[index];
		dp[index] -= 1;

		sum += c[index];
		dp[index] += 1;
		cnt++;
		BruteForceChange(M, c, d, index, cnt, sum, dp);
		cnt--;
		sum -= c[index];
		dp[index] -= 1;
	}
	// ���� �ε��� ������ ���� ���� ���
	BruteForceChange(M, c, d, index + 1, cnt, sum, dp);

	
}
int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int M, d;
	cin >> M;
	int dp[MAX];
	memset(dp, 0, sizeof(dp));
	vector<int> c;
	do {
		int a;
		scanf("%d", &a);
		c.push_back(a);
	} while (getc(stdin) == ' ');
	d = c.size();
	BruteForceChange(M, c, d, 0, 0, 0, dp);
	
	for (int i = 0; i < d; i++)
	{
		cout << k[i] << " ";
	}

	return 0;
}