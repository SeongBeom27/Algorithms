#include <iostream>
#include <string>
#include <cstring>
#define MAX 1001
using namespace std;
string S;
int len;
bool palindrome(int idx)
{
	for (int i = 0; idx + i < len - i - 1; i++)
		if (S[idx + i] != S[len - i - 1])		// ��� �����ؾ� �Ӹ����
			return false;

	return true;
}

int main()
{
	cin >> S; len = S.length();
	int result = 0;

	// 1. �־��� ���ڿ��� ���̰� len�� �� palindrome �Ǵ��� Ȯ��
	// 2. 1���� ���� �ȵǸ� len + 1�� �� palindrome �Ǵ��� Ȯ��

	// ��, ������ �� �Ӹ���Һ��� �����ؼ� �غ���. 
	for (int i = 0; i < len; i++)
	{
		if (palindrome(i))
		{
			result = len + i;
			break;
		}
	}

	cout << result << endl;
	return 0;
}