#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 51
using namespace std;
// https://www.acmicpc.net/problem/1043
/*
	����

	-> �̾߱��� ������ �ƴ� ����� �տ����� ������ ���ؾ��Ѵ�.
	-> ����� �� N, �̾߱��� ������ �ƴ� ����� �־�����.

	� ����� � ��Ƽ������ ������ ���, �Ǵٸ� ��Ƽ������ ����� 
	�̾߱⸦ ����� ���� �����̴� ���������̷� �˷����� �ȴ�. �����̴� �̷� ���� ��� ���ؾ� �Ѵ�.
	or
	����� ���� ��� ���߿� ��¥ �̾߱⸦ �ϸ� �װ͵� �ɸ���.

	��� : ����� �̾߱⸦ ��Ű�� �ʴ� ������ �ִ��� ����ǰ� �̾߱⸦ �� �� �ִ� ��Ƽ ������ �ִ�
*/

int n, m;
int nknown;
bool known[MAX];
vector<int> partyinfo[MAX];
int dp[MAX][MAX];

//////////////////////////////////// �Ʒ� �Լ� 3���� Union Find �˰����� ���� �Լ�
// x�� �θ� ��带 ã�� �Լ�			<< �θ� ��带 �������ִ� �Լ�

// Union Find �˰������� ���� ����Ǿ��ֳ� Ȯ���غ���.
int parent[MAX];
int getParent(int parent[], int x)
{
	// �ش� �θ� ���� x���� ���� ���
	if (parent[x] == x) return x;			// 1�� ��� �����ϸ� �� �κ��� ����ϴ� ���� 1�̵� ���̴�.
	// ���� �θ� ã�� ����
	return parent[x] = getParent(parent, parent[x]);
}

// �� �θ� ��带 ��ġ�� �Լ�		<< ��尣�� �������ִ� �Լ�
void unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

// ���� �θ� �������� Ȯ��		<< ��尣�� �������� �̷����ִ��� Ȯ���ϴ� �Լ�
int findParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);

	if (a == b) return 1;
	return 0;
}
//////////////////////////////////// �� 3�� �Լ��� Union Find �˰����� ���� �Լ�


int solution(int peopleidx, int partyidx)
{
	// ��Ƽ���� �������� �� �ִ� ���
	if (peopleidx == 0) return 1;

	int& result = dp[peopleidx][partyidx];
	if (result != -1)
		return result;

	result = 0;
	// ���� peopleidx�� ����� �������� �˰� �ְ�
	if (known[peopleidx])
	{
		// �� ��Ƽ�� �������ִ� �ο����� Ȯ���غ���
		for (int i = 0; i < partyinfo[partyidx].size(); i++)
		{
			if (peopleidx == partyinfo[partyidx][i])
			{
				// �� ��� �������� �� �� ���� ��Ƽ�� �ȴ�.
				return 0;
			}
		}
		// ��Ƽ�� �������ִ� �ο��� ���� �ο��̶�� ����

		result = solution(peopleidx - 1, partyidx);
	}
	else {
		// �𸣴� ����̶�� ����
		result = solution(peopleidx - 1, partyidx);
	}

	return result;
}

int main()
{
	cin >> n >> m;
	cin >> nknown;
	vector<int> knownclub;
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}
	for (int i = 1; i <= nknown; i++)
	{
		int people; cin >> people;
		knownclub.push_back(people);
		known[people] = true;
	}
	for (int i = 1; i <= m; i++)
	{
		int many, who; cin >> many;
		for (int j = 0; j < many; j++)
		{
			cin >> who;
			partyinfo[i].push_back(who);
			// ���� ��Ƽ�� �����ϴ� �ο����� ���� �׷����� �����ش�.
			unionParent(parent, partyinfo[i][0], partyinfo[i][j]);
		}
	}
	// ����� �˰��ִ� ����� ���� ������� known �迭�� ���� true�� �ٲ��ش�.
	for (int j = 0; j < knownclub.size(); j++)
	{
		for (int i = 1; i <= n; i++)
		{
			// ���� ���
			if (findParent(parent, knownclub[j], i) == 1)
			{
				known[i] = true;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= m; i++)
	{
		memset(dp, -1, sizeof(dp));
		ans += solution(n, i);
	}
	cout << ans << endl;
	return 0;
}