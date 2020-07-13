#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info {
	int sender;
	int receiver;
	int num;
};

bool cmp(info &x, info &y)
{
	if (x.receiver < y.receiver)
		return true;
	else if (x.receiver == y.receiver)
		if (x.sender < y.sender)
			return true;
	return false;
}

int main()
{
	int n, cap;	// ���� ��, Ʈ�� �뷮
	int m;		// ������ �ڽ� ������ ����
	int cnt(0);
	cin.tie(0);
	cin >> n >> cap >> m;
	info a[10000];
	int truck[2001];
	fill_n(truck, 2001, 0);
	for (int i = 0; i < m; i++)
	{
		cin >> a[i].sender >> a[i].receiver >> a[i].num;
	}
	sort(a, a + m, cmp);			// sender�� �������� �������� ����

	for (int i = 0; i < m; i++)
	{
		int boxcnt = 0;
		// �ش� ������ ���鼭 ���� ���� ����� ��
		for (int j = a[i].sender; j < a[i].receiver; j++)
			boxcnt = max(boxcnt, truck[j]);
		// Ʈ���� �� ���� �� �ִ� ��
		int leftspace = min(a[i].num, cap - boxcnt);
		cnt += leftspace;
		// �ش� ������ �� ���� ��Ų��.
		for (int j = a[i].sender; j < a[i].receiver; j++)
			truck[j] += leftspace;
	}

	cout << cnt << endl;
	return 0;
}