#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAX 1000001
using namespace std;
int n, u, v;
vector<int> a[MAX];
vector<int> oneway[MAX];
int dp[MAX][2];			// ��尡 n�� 0(early adaptor)�ƴ� �� �� �ּ� early adaptor ��
						// ��尡 n�� 1(early adaptor)�� �� �� �ּ� early adaptor ��
bool visited[MAX];
/*
	LOGIC

	1. Ʈ����� ������ �����Ƿ� ��Ʈ���� �����ؼ� Ȯ���غ���.
	2. �ܹ��� �׷����� �ٲ��ش�.

	3. ���� ��尡 early adaptor��� ���� ���� early adaptor�̾ �ǰ� �ƴϾ �ȴ�.
	4. ���� ��尡 early adaptor �ƴ϶�� ���� ���� early adaptor�̾�� �Ѵ�.
*/

void make_oneway_graph(int curnode)
{
	// �湮 �������
	visited[curnode] = true;

	// ���� �׷��� �׷��� ���鼭 �ܹ��� �׷����� �ٲ��ֱ�
	for (int i = 0; i < a[curnode].size(); i++)
	{
		// ���� ��� ���� ����
		int nextnode = a[curnode][i];
		// �� ��尡 �湮 ���� ���� ����ΰ�?
		if (!visited[nextnode])
		{
			// ��Ʈ���� ���ܳ��(leaf node)�� ���� �������� �����Ƿ� �̷� ������ �־��شٸ�,
			// �ܹ��� �׷����� �����ȴ�.
			oneway[curnode].push_back(nextnode);
			// �湮���� �ʾҴٸ� �湮�Ϸ� ����
			make_oneway_graph(nextnode);
		}
	}
}

// ���̵�� ���ٴϴ� �ν�
int inssa(int curnode, bool early)
{
	int& result = dp[curnode][early];
	if (result != -1)
		return result;

	// �� LOGIC�� 3, 4�� ������ ��� 
	if (early)
	{
		// ���� ��尡 early adaptor�̱� ������ result�� 1���� �־��ش�
		result = 1;
		// �ܹ��� �׷����� Ž���غ���.
		for (int i = 0; i < oneway[curnode].size(); i++)
		{
			int nextnode = oneway[curnode][i];
			result += min(inssa(nextnode, true), inssa(nextnode, false));
		}
	}
	else {
		// �νΰ� �ƴϸ� �� ���� ģ���� �ݵ�� �ν��̾�� �Ѵ�.
		result = 0;
		for (int i = 0; i < oneway[curnode].size(); i++)
		{
			int nextnode = oneway[curnode][i];
			result += inssa(nextnode, true);
		}
	}


	return result;
}

int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	// ���� ���� (�׷��� �׸��� �κ�)
	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	make_oneway_graph(1);			// ��Ʈ���� ����

	cout << min(inssa(1, true), inssa(1, false));
	return 0;
}