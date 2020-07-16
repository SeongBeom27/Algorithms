//#include <cstdio>
//#include <cstring>
//#include <vector>
//using namespace std;
//int n, t;
//int a[2001];
//int dp[2001][2001];
////https://www.acmicpc.net/problem/10942
//// ��ͷ� Ǯ��
//int palin(int x, int y)
//{
//	if (x >= y) return 1;
//	int &ret = dp[x][y];			
//	if (ret != -1) return ret;
//	if (a[x] == a[y])
//	{
//		//ret = palin(x + 1, y - 1);
//		//dp[x][y] = ret;
//		return ret = palin(x + 1, y - 1);	 // &ret�� �����Ͽ����Ƿ�
//		//	   dp[x][y] = palin(x + 1, y - 1) ���� ���� �Ȱ����� ���̰� ���� �ȴ�.
//	}
//	else {
//		return 0;
//	}
//	return true;
//}
//
//int palin2(int x, int y)
//{
//	int i, j;
//	for (i = x, j = y; i < j; i++, j--)
//	{
//		if (a[i] == a[j])
//		{
//			// ���⼭ dp[i][j]�� 1�� �ֱ⿡�� 
//			// ������������ �Ӹ�������� �� �� ������
//			// ����Լ��� �Ἥ ���ö� 1�� �־��ִ� ����� ������ ����ߴ�.
//		}
//	}
//}
//
//int main()
//{
//	int s, e;
//	memset(dp, -1, sizeof(dp));
//	scanf("%d", &n);
//	for (int i = 1; i <= n; ++i)
//	{
//		scanf("%d", &a[i]);
//		dp[i][i] = true;				// ���̰� 1
//	}
//	scanf("%d", &t);
//	while (t--)
//	{
//		scanf("%d %d", &s, &e);
//		printf("%d\n", palin(s, e));
//	}
//	return 0;
//}
#include <cstdio>
#include <cstring>
#define MAX 2000
using namespace std;
int a[MAX + 1];
int dp[MAX + 1][MAX + 1];			// x���� y������ �Ӹ�������� �ƴ��� Ȯ�� �� �޸������̼�
int n,m, s, e;
int falin(int x, int y)
{
	if (x >= y) return 1;			// ���� ��� 
	int& ret = dp[x][y];
	if (ret != -1) return ret;
	if (a[x] == a[y])
	{
		return ret = falin(x + 1, y - 1);
	}
	else {
		return 0;
	}
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	memset(dp, -1, sizeof(dp));
	scanf("%d", &m);
	while (m--)
	{
		scanf("%d %d", &s, &e);
		printf("%d ", falin(s, e));
	}
	return 0;
}