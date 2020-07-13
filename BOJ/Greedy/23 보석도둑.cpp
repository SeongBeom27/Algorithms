#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> p;

p jew[1000000];
int bag[300000];
int n, k, m, v, c, i, j;

bool check[1000000];

int main()
{
	scanf("%d %d", &n, &k);
	for (i = 0; i < n; ++i)
	{
		scanf("%d %d", &jew[i].first, &jew[i].second);
	}
	for (i = 0; i < k; ++i)
		scanf("%d", &bag[i]);

	sort(jew, jew + n);
	sort(bag, bag + k);

	/*for (auto b : jew)
	{
		cout << b.first << " " << b.second << endl;
		if (b.first == 0) break;
	}*/
	long long sum = 0;
	priority_queue<int> pq;
	for (i = 0, j = 0; i < k; ++i)
	{
		while (j < n && jew[j].first <= bag[i])			// i ���濡 ���� �� �ִ� ������ pq�� ���
			pq.push(jew[j++].second);					// ���Ե��� �ִ´�.
		if (!pq.empty())								// �켱���� queue�� ��� ���� ���� ���
		{
			sum += pq.top();							// top���� ���� ū ���� ������
			pq.pop();									// pq�� �ִ� �� �߿� top�� �ִ� ���� �����ϸ�ȴ�.
		}
	}

	cout << sum << endl;

	return 0;
}