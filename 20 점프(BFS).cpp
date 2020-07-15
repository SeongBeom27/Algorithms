#include <iostream>
#include <queue>
// BFS�δ� �޸��ʰ��� ����.
using namespace std;
int n;
// �� ������ ��Ģ�� ��Ģ�� �°� �����ؼ� ������ ���� �Ʒ��� �����ϴ� ���̴�.
// �� ĭ�� �����ִ� ���� ���� ĭ���� �� �� �ִ� �Ÿ��� �ǹ��Ѵ�.
// �ݵ�� ������ or �Ʒ������θ� �̵��ؾ��Ѵ�.
// 0�� ���̻� ������ ���� ������, �׻� ���� ĭ�� �����ִ� ����ŭ ������ or �Ʒ���
// ���� : ���� ���� ������ ������ �Ʒ����� ���� ����� ����
int a[101][101];

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	long long ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	
	if (a[1][1] == 0) cout << 0 << endl;
	else {
		queue<pair<int, int>> q;
		q.push(make_pair(1, 1));
		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			if (x == n && y == n)
			{
				ans++;
				continue;
			}
			else if(a[x][y] == 0)
			{
				continue;
			}
			if (x + a[x][y] <= n)
			{
				q.push(make_pair(x + a[x][y], y));
			}
			if (y + a[x][y] <= n)
			{
				q.push(make_pair(x, y + a[x][y]));
			}
		}

		cout << ans;
	}
	
	
	return 0;
}