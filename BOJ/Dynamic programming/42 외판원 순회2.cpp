#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int w[20][20];

int main()
{
	cin.tie(0);
	cin >> n;
	vector<int> d(n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> w[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		d[i] = i;				// 0 ~ 15���� ����
	}
	int ans = 2147483647;		// int�� �ִ밪

	do {
		bool ok = true;
		int sum = 0;
		for (int i = 0; i < n - 1; i++)
		{
			if (w[d[i]][d[i + 1]] == 0)
			{
				ok = false;		// ���� ���ϴ� ���
				break;
			}
			else
			{
				sum += w[d[i]][d[i + 1]];
				if (sum > ans) break;
			}
		}
		// n - 1���� ���� �����ش�.
		if (ok && w[d[n - 1]][d[0]] != 0)		// ���������� ������� ���� �ü� �ִ� ���
		{
			sum += w[d[n - 1]][d[0]];
			if (ans > sum) ans = sum;
		}
	} while (next_permutation(d.begin() + 1, d.end()));
	cout << ans;
	return 0;
}