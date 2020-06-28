#include <iostream>
#include <vector>
#define MAX 101
using namespace std;

vector<int> a[MAX];		// ����
int d[MAX];				// ��Ʈ�ϰ� ��Ī�� �� ��� �ε����� ���� �迭
bool c[MAX];			// Ư���� ���� ó���ߴ���
int n = 3, m;

bool dfs(int x)
{
	for (int i = 0; i < a[x].size(); i++)
	{
		int t = a[x][i];
		// �̹� ó���� ���� �� �ʿ� ����.
		if (c[t] == true) continue;
		c[t] = true;

		// ����ְų� ���� ��忡 �� �� ������ �ִ� ���
		// dfs(d[t]) �� �ٸ� ���� ������� �ٸ� ������ �� �� �ִ��� ����� ��
		if (d[t] == 0 || dfs(d[t]))
		{
			d[t] = x;
			return true;
		}
	}
	
	return false;
}


int main()
{
	a[1].push_back(1);
	a[1].push_back(2);
	a[1].push_back(3);
	a[2].push_back(1);
	a[3].push_back(2);
	int count = 0;
	for (int i = 1; i <= n; i++)
	{
		fill(c, c + MAX, false);			// �Ź� ��Ī�� ������ c�� �ʱ�ȭ
		if (dfs(i)) count++;
	}

	cout << count << endl;

	for (int i = 1; i < MAX; i++)
	{
		if (d[i] != 0)
		{
			printf("%d -> %d\n", d[i], i);
		}
	}
}