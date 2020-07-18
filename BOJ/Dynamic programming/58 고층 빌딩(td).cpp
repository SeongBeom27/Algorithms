#include <iostream>
#include <cstring>
#define MOD 1000000007
#define MAX 101
using namespace std;
int n, l, r;
long long cache[MAX][MAX][MAX];
long long solution(int number, int left, int right)
{
	// ���� ���
	if ((left == 1 && right == number) || (left == number && right == 1))
		return 1;

	// �Ұ����� ���
	if (number == 0 || left == 0 || right == 0)
		return 0;

	long long& result = cache[number][left][right];
	if (result != -1)
		return result;

	result = 0;
	result = ((solution(number - 1, left, right) * (number - 2)) + solution(number - 1, left - 1, right)
		+ solution(number - 1, left, right - 1)) % MOD;
	return result;
}
int main()
{
	cin >> n >> l >> r;
	memset(cache, -1, sizeof(cache));

	cout << solution(n, l, r) % MOD;
	return 0;
}