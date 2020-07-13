#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, k, cnt(0);
	cin.tie(0);
	cin >> n >> k;		// n : ��Ƽ�� ���� ����, k : ����� ������ǰ ����
	vector<int> v(k);			// ����� ���� ��ǰ
	vector<int> multi;		// ��Ƽ�ǿ� ���� �����ִ� �͵�
	for (int i = 0; i < k; i++)
	{
		cin >> v[i];
	}
	int index = 0;
	while (1)
	{
		multi.push_back(v[index]);			// ó�������ϴ� �ϳ��� �ȱ� ����	
		if (multi.size() == n)
		{
			multi.erase(unique(multi.begin(), multi.end()), multi.end());
			if (multi.size() != n)
			{
				continue;
			}
			else {
				break;
			}
		}
		index++;
		if (index == k)
		{
			cout << 0 << endl;
			return 0;
		}
	}

	int i(0), j(0);
	// index == 1, k == 7
	for (i = index; i < k; i++)
	{
		vector<int> _new;
		vector<int> use;
		for (j = 1; j <= n; j++)		// �ڿ� �ִ� ������ ��Ƽ�� ũ�� ��ŭ ����.
		{
			if (i + j >= k) break;
			//cout << "i + j : " << i + j << endl;
			if (multi.end() == find(multi.begin(), multi.end(), v[i + j]))		// ���� == ���ο� ������ǰ
			{
				_new.push_back(v[i + j]);				//	 ���ο� ������ǰ ���ڸ� ����
				//cout << "i : "<< i << ", v[i + j] : " << v[i + j] << endl;
			}
			else {																// �ִ� == ���� �Ŷ� �ߺ�
				use.push_back(v[i + j]);					//	  �ߺ��Ǵ� ��ǰ�� ����
			}
		}
		// �ߺ��Ǵ� ��ǰ�� �ƴ� �ܼ�Ʈ ����
		for (j = 0; j < _new.size() + use.size(); j++)
		{
			// ���ο� ��ǰ�� �ٲ�� �ϴ� �ֵ�
			if (use.end() == find(use.begin(), use.end(), multi[j]))
			{
				multi.erase(multi.begin() + j);
				int temp = _new.back(); _new.pop_back();
				//cout << "temp : " << temp << endl;
				multi.push_back(temp);
				cnt++;
			}
		}

		//for (int m : multi)
		//	cout << "m : " << m << " ";
		//cout << endl;
		i = i + n - 1;
		if (i + j >= k) break;
	}
	
	cout << cnt;
	return 0;
}