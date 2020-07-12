#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int,int> a, pair<int,int> b)
{
	return a.first < b.first;
}
int main()
{
	int T, n;	cin >> T;

	while (T--)
	{
		cin >> n;			// 1 < N < 100000
		vector<pair<int, int>> applicant;
		int doc, inter;		// ������ �ƴ϶� �����̴�. ��������, ��������
		int pass = 1;
		for (int i = 0; i < n; i++)
		{
			cin >> doc >> inter;
			applicant.push_back(make_pair(doc, inter));
		}
		
		// ���� �ɻ� ����� ������� sort�Ѵ�.
		sort(applicant.begin(), applicant.end(), compare);
		
		int rank = applicant[0].second;W
		
		for (int i = 1; i < n; i++)
		{
			// ������ �� ������� ä��
			if (applicant[i].second < rank)
			{
				pass++;
				rank = applicant[i].second;
			}
		}
		cout << pass << endl;
	}
	return 0;
}