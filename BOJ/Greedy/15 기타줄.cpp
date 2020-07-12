#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// ���ο� ���� ��ų� ��ü�ؾ� �Ѵ�.
	// 6�� ��Ű���� �� �����ְ�, 1�� �Ǵ� �� �̻��� ���� ������ �� ���� �ִ�.
	int n;	 cin >> n;		// ������ ��Ÿ���� ����
	int m;	 cin >> m;		// ��Ÿ�� �귣��
	int package, one, a, b, price1(1000), price2(1000), price3(1000);
	vector<int> min_package;
	vector<int> min_one;
	// ���� �귣�带 ���� �ʿ� ����.
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		min_package.push_back(a);
		min_one.push_back(b);
	}
	package = *min_element(min_package.begin(), min_package.end());
	one = *min_element(min_one.begin(), min_one.end());


	// ��Ÿ���� 6�� ������ ���?
	if (n % 6 != 0)
	{
		// ��Ű���θ�
		price1 = (n / 6 + 1) * package;
		// ��Ű�� + ����
		price2 = ((n / 6) * package) + ((n % 6) * one);
	}
	else
	{
		price1 = (n / 6) * package;
	}
	// ����
	price3 = n * one;

//	cout << price1 << " " << price2 << " " << price3 << endl;
	cout << min(price1, min(price2, price3));
	
	return 0;
}