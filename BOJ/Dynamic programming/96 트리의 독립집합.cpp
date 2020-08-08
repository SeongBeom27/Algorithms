#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAX 10001
using namespace std;
int n;
int vertex[MAX];			// ������ ����ġ
vector<int> edge[MAX];		// �׷���
// dp[idx][0 or 1] : idx ��带 �����ϴ� ���, ���� ���ϴ� ���
int dp[MAX][2];
vector<int> ans;
/*
	���� ����

	1. ���� ������ ũ�Ⱑ �ִ��� ���� ������ ���ϴ� ��
	2  ���� �����̶�, �κ� ���� S�� ���� ��� �������� ���� �������� ���� S�� ���������̶�� �Ѵ�.

	����

	1. dp�� �ִ밪�� ã�µ� �� ��θ� ���;� �Ѵ�.

	������ �� ���� ���� ���� ��带 ����ϰ� �ִٸ� ���� ���� ������ ������ �ʰ� ���� ���̰�,


	���� ��尡 ���ǰ� ���� �ʴٸ�,
	�̶��� dp���� Ȯ���Ͽ� ���� ���� ����� �� dp���� �� ���ٸ� �������� ������ְ�
	�׷��� �ʴٸ� ���� ���� ������� �ʴ� ������� ������ �س�����.

*/

int solution(int prev, int cur, bool state)
{
	int& result = dp[cur][state];
	if (result != -1)
		return result;

	if (state)
	{
		result = vertex[cur];
	}
	else {
		// �� ��带 ���� ���� ���
		result = 0;
	}
	for (int i = 0; i < edge[cur].size(); i++)
	{
		int next_node = edge[cur][i];
		if (next_node == prev)
			continue;
		// �� ��带 ������ ���
		if (state)
		{
			result += solution(cur, next_node, 0);
		}
		else {
			// �� ��带 ���� ���� ���
			result += max(solution(cur, next_node, 0), solution(cur, next_node, 1));
		}
	}

	return result;
}

void tracking(int prev, int cur, bool state)
{
	// state�� ���´ٴ� ���� �� ������ ���ٴ� ���� �ִ��� �ǹ��̴�.
	if (state)
	{
		ans.push_back(cur);
		for (auto next : edge[cur])
		{
			if (next == prev)
				continue;
			tracking(cur, next, 0);
		}
	}
	else {
		for (auto next : edge[cur])
		{
			if (next == prev)
				continue;
			if (dp[next][1] >= dp[next][0])
				tracking(cur, next, 1);
			else
				tracking(cur, next, 0);
		}
	}
}

int main()
{
	memset(dp, -1, sizeof(dp));

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> vertex[i];

	for (int i = 0; i < n - 1; i++)
	{
		int v, e; cin >> v >> e;
		edge[v].push_back(e);
		edge[e].push_back(v);
	}

	int temp1 = solution(-1, 1, 0);				// ��� 1�� ���� x
	int temp2 = solution(-1, 1, 1);				// ��� 1�� ����

	// dp�� 1�������� �� ����� ���������� �������� �ִ��̴�.
	// �׷��Ƿ� �� �ִ��� ���󰡸鼭 Ʈ��ŷ�ϸ� �ȴ�.
	if (temp1 > temp2)
	{
		tracking(-1, 1, 0);
	}
	else {
		tracking(-1, 1, 1);
	}
	
	sort(ans.begin(), ans.end());

	cout << max(temp1, temp2) << endl;
	for (auto i : ans)
		cout << i << " ";

	return 0;
}