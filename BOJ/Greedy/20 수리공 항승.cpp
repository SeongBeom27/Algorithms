#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, l, cnt(0);		// n : ���� ���� �� ����, l : �������� ����
	cin >> n >> l;
	vector<int> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	int i, j;
	for (i = 0; i < n; i++)
	{
		cnt++;
		if (i == n - 1)
		{
			break;
		}
		// ���� ���̶� �� ���� ���� �� �ִ� ���
		if (v[i + 1] - v[i] < l)
		{
			// ������ �� ���� ���� �� �ִ��� �ٿ�����.
			for (j = 2; i + j < n; j++)
			{
				if (v[i + j] - v[i] >= l)
				{
					j--;
					break;
				}
			}
			i = i + j;
		}
	}

	cout << cnt << endl;
	return 0;
}