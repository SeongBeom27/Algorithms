#include <iostream>
#include <algorithm>
using namespace std;
int a[1001];
int dp[1001];
int n;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			// ù��° ���� : �����ؾ��ϹǷ� �տ� ������ �۾ƾ��Ѵ�.
			// �ι�° ���� : ù��° ������ �����ϸ鼭 ���̴� ���� ������ ���� �����Ѵ�.
			if (a[i] < a[j] && dp[j] + 1 > dp[i])		
			{
				dp[i] = dp[j] + 1;
			}
		}
	}
	cout << *max_element(dp, dp + n);
	return 0;
}