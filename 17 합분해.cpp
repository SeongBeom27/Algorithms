#include <iostream>
using namespace std;
#define Mod 1000000000
long long d[201][201];

int main()
{
	int n, k; cin >> n >> k;
	// d[k][n] �� n���� k���� ������ ���ؼ� n�̵Ǵ� ����� ��
	d[0][0] = 1LL;
	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			for (int l = 0; l <= j; l++)
			{
				d[i][j] += d[i - 1][j - l];
				d[i][j] %= Mod;
			}
		}
	}

	cout << d[k][n];
	
	return 0;
}