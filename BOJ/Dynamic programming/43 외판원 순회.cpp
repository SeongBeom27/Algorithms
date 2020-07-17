/*
OR ����, AND ���� ���� ��� Ǯ���
�ſ��߿�
*/
#include <iostream>
using namespace std;
#define CITY 16
#define MAX 17000000
int n;
int arr[CITY][CITY];
int d[1 << CITY][CITY] = { 0 };
int TSP(int visit, int now)
{
	visit |= (1 << now);			// now ��ġ�� visit�� 1�θ���

	if (visit == (1 << n) - 1)			// ��� �湮���� ���
	{
		if (arr[now][0] != 0)
		{
			return arr[now][0];
		}
		return MAX;
	}

	int& ret = d[visit][now];
	if (ret > 0)
		return ret;

	ret = MAX;
	for (int i = 0; i < n; i++)
	{
		if (i != now && (visit & (1 << i)) == 0 && arr[now][i] > 0)
		{
			int temp = TSP(visit, i) + arr[now][i];
			if (ret > temp)
			{
				ret = temp;
			}
		}
	}
	return ret;
}


int main()
{
	int ans;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}
	ans = TSP(0, 0);
	cout << ans;
	return 0;
}