#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#define MAX 251
using namespace std;
// https://www.acmicpc.net/problem/1793
int n;
string dp[MAX];			// n��°�� string���� ������ �ִ´�.
/*
	�˰����� dp[n] = (dp[n - 2] * 2) + dp[n - 1]) �̴�.

	���⼭ long long���� ǥ���� �� ���� ����. ( MOD�� ���� ���� )
	�׷��Ƿ� ū ������ string�� �̿��ؼ� ��������Ѵ�.
*/

string add(string num1, string num2)
{
	long long sum = 0;
	string result;

	// 1�� �ڸ����� ���ϱ� ����
	while (!num1.empty() || !num2.empty() || sum)
	{
		if (!num1.empty())
		{
			// �� ���� �� �� �����ش�.
			sum += num1.back() - '0';
			// �� ���� ���� pop�Ѵ�.
			num1.pop_back();
		}
		if (!num2.empty())
		{
			// �� ���� �� �� �����ش�.
			sum += num2.back() - '0';
			// �� ���� ���� pop�Ѵ�.
			num2.pop_back();
		}
		// �ٽ� string ���·� ���� push_back�� �Ѵ�.
		result.push_back((sum % 10) + '0');
		sum /= 10;		// 1���ڸ����� 10�� �ڸ��� �ø��� �� ���¶�� 
					    // �� 10�� �ڸ� ���� ���ܵд�. 1 or 0�� ���̴�. 
		cout << sum;
	}
	// 1�� �ڸ����� result�� �־������Ƿ� ������.
	reverse(result.begin(), result.end());
	return result;
}

int main()
{
	dp[0] = dp[1] = '1';
	for (int i = 2; i <= 250; i++)
		dp[i] = add(add(dp[i - 2], dp[i - 2]), dp[i - 1]);
	// n�� ��� �Է¹޴��� �� �� �����Ƿ� ������ ���� �Է��Ѵ�.
	while (~scanf("%d", &n))
	{
		cout << dp[n] << endl;
	}
	return 0;
}