#include <iostream>
#include <map>
using namespace std;
// 0 <= n <= 10^12
long long n, p, q;
map<long long, long long> dp;

long long solution(long long N)
{
	if (dp.count(N))
	{
		return dp[N];
	}
	else
		return dp[N] = solution(N / p) + solution(N / q);
}

int main()
{
	cin >> n >> p >> q;

	// n�� 10^12�� �Ǹ� dp �迭 ũ�⸦ �ʰ��Ұ��̴�.
	dp[0] = 1;
	cout << solution(n);
	return 0;
}