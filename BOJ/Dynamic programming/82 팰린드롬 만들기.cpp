#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 5001
using namespace std;
int n; int a[MAX]; int dp[MAX][MAX];
/*
	�Ӹ���� : �տ��� �ڷ� ����, �ڿ��� ������ ���� ���� ������ �Ӹ�����̶� �Ѵ�.

	���� : �� ������ �־����� ��, �� ������ �ּ� ������ ���� ���� �־� �Ӹ������ ������.
*/

int solution(int left, int right)
{
	// ���� ���
	if (left > right)
		return 0;

	int& result = dp[left][right];
	if (result != -1)
		return result;

	// ���� ������ �Ѵٸ�
	if (a[left] == a[right])
		result = solution(left + 1, right - 1);
	else
		// �׳� �ٸ� ��쿡�� ���� 1���� �� �ʿ��ϴٴ� �ǹ��̴�.
		result = min(1 + solution(left, right - 1), 1 + solution(left + 1, right));

	return result;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	memset(dp, -1, sizeof(dp));
	cout << solution(1, n) << endl;	

	return 0;
}