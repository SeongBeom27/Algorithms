#include <cstdio>
#include <cstring>
using namespace std;
bool a[101];
int n;
int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		// ����ִ� �� false, �����ִ� �� true
		scanf("%d", &n);
		int ans = 0;
		memset(a, true, sizeof(a));			// ù ���� ��� ����.
		for (int i = 2; i <= n; i++)
		{
			for (int j = 1; i * j <= n; j++)
			{
				if (a[i * j]) a[i * j] = false;
				else a[i * j] = true;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (a[i]) ans++;
		}
		printf("%d\n", ans);
	}
	return 0;
}