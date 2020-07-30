#include <iostream>
#include <cstring>
#define MAX 31
using namespace std;
int n; long long dp[MAX];
long long solution(int width)
{
	// ���� ���
	if (width <= 1)
		return 1;

	long long& result = dp[width];
	if (result != -1)
		return result;

	// �غ��� 2�� ��� (2 * 2, 2 * 1), �غ��� 1�ΰ�� ( 1 * 2 )
	result = 2 * solution(width - 2) + solution(width - 1);
	return result;
}

int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	int result = 0;

	// (�ߺ� + �ߺ� + �ߺ�x + �ߺ�x ) / 2 = �ߺ� + �ߺ�x �̹Ƿ�,

	// Ȧ���̸� ��� 1 * 2 ¥�� �ϳ��� �ְ� �¿� ��Ī�� ���
	if (n % 2)
		result = (solution(n) + solution(n / 2)) / 2;
	// ¦���̸� ��� 1 * 2 ¥�� �� �� Ȥ�� 2 * 2¥�� �ϳ� �ְ� �¿� ��Ī
	// 2 * solution(n / 2 - 1)
	// Ȥ�� ������ �������� �� �� ���� ��Ī
	// solution(n / 2)
	else
		result = ((solution(n) + (solution(n / 2)) + 2 * solution(n / 2 - 1))) / 2;

	cout << result;

	return 0;
}