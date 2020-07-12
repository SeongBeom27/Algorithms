#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<int> compare;
	string a; cin >> a;
	int len = a.length();			// ������ ����
	int input_num[10];
	fill_n(input_num, 10, 0);
	for (int i = 0; i < len; i++)
	{
		input_num[a[i] - '0']++;
	}
	
	if (input_num[0] > 0)				// 0 �̾����� �Ұ���
	{
		// 3�ǹ���� ��� �ڸ��� ���� 3�� ����̴�.
		int sum = 0;
		for (int j = 1; j < 10; j++)
		{
			sum += j * input_num[j];		// ��� �ڸ��� ���غ���
		}
		if (sum % 3 == 0)			// ��� �ڸ��� ���� 3�� ������� Ȯ��
		{
			// ������ ���� ū �� ���?
			for (int i = 9; i >= 0; i--)
			{
				for (int j = 0; j < input_num[i]; j++)
				{
					cout << i;
				}
			}
			return 0;
		}
	}
	
	cout << -1;
	
	return 0;
}