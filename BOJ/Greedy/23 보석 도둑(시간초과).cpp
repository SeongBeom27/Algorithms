#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, k; cin >> n >> k;
	vector<int> m(n), v(n), c(k);
	int sum = 0;
	for (int i = 0; i < n; i++) cin >> m[i] >> v[i];
	for (int i = 0; i < k; i++)	cin >> c[i];

	sort(c.begin(), c.end());						// ������ �ɷ�ġ �������� ����
	//sort(v.begin(), v.end(), greater<int>());		// ������ ���� ���� ���� ����

	for (int i = 0; i < k; i++)
	{
		vector<int>::iterator itv, itm;
		int maxv = 0;
		for (int j = 0; j < v.size(); j++)
		{
			if (c[i] >= m[j])				// ������ ������ �� �� �ִ� �ɷ��� �ȴ�.
			{
				if (maxv < v[j])				// �� �� �ִ� ������ �� ���� ��δ�.
				{
					maxv = v[j];
					itv = v.begin() + j;	// ���濡 ���� ���� ���� ��ġ
					itm = m.begin() + j;	// ���濡 ���� ���� ���� ��ġ
				}
			}
		}
		// ���濡 ���� ������ ���������� ��������Ѵ�.
		v.erase(itv);
		m.erase(itm);
		for (auto abc : v) cout << abc << endl;
		sum += maxv;							// �� �� �ִ� �͵��� ���� ��� ���� �����ش�.
	}

	cout << sum << endl;

	return 0;
}