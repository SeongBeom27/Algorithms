#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAX 300000
using namespace std;

/*
	���� ����

	1. �׸��� ���� ��� �����ϸ�, ���̰� �ٸ� ���� �ִ�.
	2. �� �׸��� ������ �Ű��� �ִ�
	3. �׸��� ������� ������ �� �� �ʿ��� ���̴� �׸��� �ܸ����� ���δ�.
	4. ���̰� ���� �׸��� �ߺ������� �� �׸��� ������ �ȴ�.
	5. �̶� Ư�� ���� S�̻� �׸��� ���̸� ������ ������ ��Եȴ�. �� �׸��� �ǸŰ��� �׸��̶�� �Ѵ�.

	���

	�� �׸����� ������ ���� �ִ밡 �ǵ��� ��ġ���� �� �� �ִ� ���� ����Ѵ�.
*/
int n, s, h, c;
vector<pair<int, int>> picture;
// dp[idx] : idx �׸����� �߿� ���ǿ� �����ϴ� �ִ�
int dp[MAX + 1];


bool swaps(pair<int, int> t1, pair<int, int> t2)
{
	return t1.first < t2.first;				// first�� �������� ������������ �����Ѵ�.
}


int main()
{
	cin >> n >> s;
	picture.push_back(make_pair(0, 0));
	for (int i = 0; i < n; i++)
	{
		cin >> h >> c;
		picture.push_back(make_pair(h, c));
	}
	memset(dp, 0, sizeof(dp));
	sort(picture.begin(), picture.end(), swaps);

	for (int i = 1 , j = 0; i <= n; i++)
	{
		while (picture[j + 1].first <= picture[i].first - s) j++;
		dp[i] = max(dp[i - 1], dp[j] + picture[i].second);
	}
	cout << dp[n] << endl;
	return 0;
}