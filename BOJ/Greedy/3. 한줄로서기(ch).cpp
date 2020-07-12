#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10;
int line[MAX];

int main()
{
	int n; cin >> n;

	for (int i = 0; i < n; i++)
	{
		int left; cin >> left;

		// ���� ��ȸ�ϴ� �κ�
		for (int j = 0; j < n; j++)
		{
			// �ڽź��� ū����� ���� , �ڸ��� ����ִٸ� �ɱ�
			if (left == 0 && line[j] == 0)
			{
				line[j] = i + 1;
				break;				// �ɾ����Ƿ� ���� ��� �� ��ȸ�ϱ�
			}						
			else if(line[j] == 0)		// ���ʿ� �ڱ⺸�� ū ����� �� �־�� �ϴµ� �ڸ��� ����ִٸ�
			{
				left--;					// �� �¼��� �ƴ� ���� �¼��� �����Ѵ�.
			}
		}
	}

	for (int i = 0 ; i < n; i++)
	{
		cout << line[i] << " ";
	}
	return 0;
}


/*
int main()
{
	int n; cin >> n;
	vector<int> a(n), b(n);

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n; i++)
	{
		int temp = a[i];

		while (b[temp])
		{
			temp++;
		}
		b[temp] = i + 1;
	}

	for (int &c : b)
	{
		cout << c << " ";
	}
	return 0;
}
*/