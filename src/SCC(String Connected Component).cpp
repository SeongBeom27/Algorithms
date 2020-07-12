#include <iostream>
#include <vector>
#include <stack>
#define MAX 10001				// ������ �� NODE�� ����
using namespace std;
int min(int a, int b) { return (a < b) ? a : b; }
int id, d[MAX];					// �� ��帶�� ������ ��ȣ�� �Ҵ��� �� ����
bool finished[MAX];				// ���� Ư���� ��忡 ���� dfs�� �������� Ȯ��
								// ���� : ���� 1 ��尡 dfs�� ������ ���� ���¿��� 2,3 �θ� ��尡 1�̵� ��
vector<int> a[MAX];				// ��帶�� ���� ���� �迭
vector<vector<int>> SCC;
stack<int> s;
		
// dfs�� �� ������ ������ŭ ����
int dfs(int x)
{
	d[x] = ++id;		// �ڱ��ڽ��� �θ�� �Ҵ�
	s.push(x);			// ���ÿ� �ڱ� �ڽ��� �Ҵ�

	int parent = d[x];
	for (int i = 0; i < a[x].size(); i++)
	{
		int y = a[x][i];
		// �� �̿��� ������ parent�� �ִ´�.
		if (d[y] == 0) parent = min(parent, dfs(y));		// �湮���� ���� �̿�
		else if (!finished[y]) parent = min(parent, d[y]);	// ó�� ���� �̿�
	}

	if (parent == d[x])			// �θ� ��尡 �ڱ� �ڽ��� ���
	{
		vector<int> scc;		// ���� scc �׷� �Ѱ��� ���� vector�� �����.
		while (1)
		{
			int t = s.top();
			s.pop();
			scc.push_back(t);	
			finished[t] = true;
			if (t == x) break;			// �θ� ��尡 ���� �� ���� pop�� �ؼ� scc�� �ִ´�.
		}
		SCC.push_back(scc);
	}

	return parent;
}



int main()
{
	int v = 11;

	a[1].push_back(2);
	a[2].push_back(3);
	a[3].push_back(1);
	a[4].push_back(2);
	a[4].push_back(5);
	a[5].push_back(7);
	a[6].push_back(5);
	a[7].push_back(6);
	a[8].push_back(5);
	a[8].push_back(9);
	a[9].push_back(10);
	a[10].push_back(11);
	a[11].push_back(3);
	a[11].push_back(8);
	for (int i = 1; i <= v; i++)
	{
		if (d[i] == 0) dfs(i);
	}

	cout << "SCC�� ���� : " << SCC.size() << endl;

	for (int i = 0; i < SCC.size(); i++)
	{
		cout << i + 1 << "��° SCC : ";
		for (int j = 0; j < SCC[i].size(); j++)
		{
			cout << SCC[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}