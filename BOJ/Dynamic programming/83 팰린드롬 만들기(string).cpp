#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#define MAX 1001
//https://www.acmicpc.net/problem/1254
using namespace std;
// dp[left][right] : left ~ right���� �Ӹ���� ����
/*
	���ڿ� S �ڿ� 0���� ���ڸ� �߰��ؼ� �Ӹ������ �����.
	���� ª�� ���ڿ��� ���� ��� �� ���̸� ����϶�.

	�ڿ��� ��������ϴ� ������ �ּҰ����� ã�´�.
*/
string S;			// abab
int len;

int solution()
{
	int result = 0;

	for (int i = 0; i < len - 1; i++)
	{
		// �� ���� ���ٸ�
		if (S[i] == S[len - 1])
		{
			// �ϳ��� ���� ����.
			int start = i;
			int end = len - 1;
			// (len - i) / 2 �� ���ڰ� �߿�
			// len : 4, i : 1 �̹Ƿ� 3/2 = 1 �̴ϱ� j = 0�϶� for���� ����
			for (int j = 0; j < (len - i) / 2; j++)
			{
				if (S[start] == S[end])
				{
					start++;
					end--;
				}
				else {
					result++;
					break;
				}
			}
			// ���̻� ��� �� ���� ���
			if (start >= end)
				break;
		}
		else
			result++;
	}

	return result;
}

int main()
{
	cin >> S; len = S.length();

	// ���ڿ� ���� �ִ� ���� �� �Ӹ������ ���̰� ���
	cout << len + solution();

	return 0;
}