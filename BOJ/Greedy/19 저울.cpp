#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000000001;
int n;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);		// cin ����ӵ� ���
	cin >> n;

	v.resize(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	// 1 �� ������ �ٷ� ��
	if (v[0] != 1)
	{
		cout << 1 << endl;
	}
	else {
		int sum = 1;
		// ��������� �� + 1 ���� ū ���� ���� �ε����� ����Ǿ� �ִٸ�
		// ������ �ߵ�� ���Ը� ���� ���� ���� ���°� �ȴ�.
		for (int i = 1; i < n; i++)
		{
			if (v[i] > sum + 1) break;
			sum += v[i];
		}
		cout << sum + 1 << endl;
	}
	
	return 0;
}
