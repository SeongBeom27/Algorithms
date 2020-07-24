#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 101
using namespace std;

int n;
long long dp[MAX];

// button�� ���� idx
long long solution(int idx)
{
	long long& result = dp[idx];
	if (result != -1)
		return result;

	result = solution(idx - 1) + 1;			// A�߰� ��Ų ���

	// CTRL A , CTRL C , CTRL V ������
	// ���� 2,3,4�� �ϳ��� �������� ���� �Ѵ�.
	// �׷��Ƿ� ��� ��ư�� 2�������� 3�� �̻���� ����� �� �ִ�.
	if(idx >= 3)
		for (int i = 1; i <= idx - 2; i++)
		{
			result = max(result, solution((idx - 2) - i) * (i + 1));
		}
	return result;
}

int main()
{
	cin >> n;
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	cout << solution(n) << endl;
}

// bottom up

/*
#include<iostream>
#include<algorithm>
typedef long long ll;

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	int maxNum;
	ll DP[101];

	cin >> n;

	DP[0] = 0;
	DP[1] = 1;
	DP[2] = 2;
	DP[3] = 3;
	DP[4] = 4;
	DP[5] = 5;

	for (int i = 6; i <= n; i++) {
		DP[i] = max({ DP[i - 1] + 1, DP[i - 3] * 2, DP[i - 4] * 3, DP[i - 5] * 4 });
	}

	cout << DP[n] << endl;

	return 0;
}
*/

// �� Ʋ�� ��
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 101
using namespace std;
// button�� n�� ������.
int n;
// Ű���带 n�� ���� ��� A�� �ִ�� ��µ� ��
int dp[MAX];
// button ���� Ƚ��
int solution(int screen,int buffer ,int push, bool drag)
{
	// screen�� �ִ� ����, buffer�� �ִ� A����
	if (push < 0) return 0;

	int& result = dp[push];

	if (result != -1)
		return result;

	result = 0;
	int a1, a2, a3, a4;
	a1 = a2 = a3 = a4 = -984321;
	// ȭ�鿡 A�� ����ϴ� ���
	a1 = solution(screen + 1, buffer, push - 1, drag) + 1;
	// ��ü ������ �ϴ� ���, << ��ü ������ �ؾ߸� ȭ�鿡 �ִ� ������ ������ �� �ִ�.
	// drag�� true���� �� �� �ִ�.
	// drag�� �ȵǾ��ִ� ���¿����� �ϸ� �ȴ�.
	if (!drag)
	{
		drag = true;
		a3 = solution(screen, buffer, push - 1, drag);
		drag = false;
	}
	// ȭ�鿡 �ִ� ������ �����ϴ� ���
	if (drag)
	{
		int pre_buf = buffer;			// ������ buffer�� �ִ� ���� �ٽ� ������ �־���Ѵ�.
		drag = false;
		buffer = screen;
		a2 = solution(screen, buffer, push - 1, drag);
		buffer = pre_buf;
	}
	// Ctrl + V

	a4 = solution(screen + buffer, buffer, push - 1, drag) + buffer;
	return result = max(max(a1, a2), max(a3, a4));
}

int main()
{
	// ȭ�鿡 A�� ����ϴ� ���
	cin >> n;
	memset(dp, -1, sizeof(dp));
	cout << solution(0, 0, n, false);
	return 0;
}

*/
