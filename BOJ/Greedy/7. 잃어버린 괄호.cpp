#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int sum = 0;
	string a; cin >> a;

	vector<char> gual;
	vector<int> c;
	string temp;
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] != '-' && a[i] != '+')
		{
			temp += a[i];						// ���ڵ� ����
		}
		else {
			c.push_back(atoi(temp.c_str()));	// �����س��� ���ڸ� ����
			temp = "";
			gual.push_back(a[i]);				// ��ȣ�� ����
		}
		if(i == a.length() -1) c.push_back(atoi(temp.c_str()));	// ������ ���ڱ��� ����
	}
	// ���� ���� �س���
	for (int i = 0; i < gual.size(); i++)
	{
		vector<int>::iterator it;
		if (gual[i] == '+')
		{
			c[i + 1] = c[i] + c[i + 1];
			c.erase(c.begin() + i);
			gual.erase(gual.begin() + i);
			i--;
		}
	}
	
	sum = c[0];
	for (int i = 1; i < c.size(); i++)
	{
		sum -= c[i];
	}
	cout << sum;

	return 0;
}