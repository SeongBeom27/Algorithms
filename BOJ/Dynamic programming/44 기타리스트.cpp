//bottom up

//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int v[101];
//bool dp[101][1001];
//int n, m, s;
//int ans = 0;
//int main()
//{
//	cin.tie(0);
//	cin >> n >> s >> m;
//	v[0] = s; dp[0][s] = true;
//	for (int i = 1; i <= n; i++) cin >> v[i];
//	// n * m �̸� �ð� ���� ����� ����
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 0; j <= m; j++)
//		{
//			if (dp[i - 1][j])		// ���� ������ ��
//			{
//				// �� ��ġ�� ���� ������ j �� �ȴ�.
//				if (j + v[i] <= m) dp[i][j + v[i]] = true;
//				if (j - v[i] >= 0) dp[i][j - v[i]] = true;
//			}
//		}
//	}
//	for (int i = m; i >= 0; i--)
//	{
//		if (dp[n][i])
//		{
//			cout << i;
//			return 0;
//		}
//	}
//	cout << -1;
//	return 0;
//}

// top down
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int v[101];
int dp[101][1001];
int n, m, s;
int ans = 0;
// ��� ���� ����'�� '�Ұ���'�� ��츦 �ٸ� ���ڷ� ǥ���ϴ� ���� �ٽ�
// ��� ���� ���� : -1
// �Ұ��� : - 100
int play(int index, int value)
{
	if (value > m || value < 0) return -100;
	if (index == n)
	{
		return value;
	}
	// ������ �̺κ��� �޸������̼� �ڵ��� �Ѵ�.
	// return result�� ���� ���� dp[value][index] ���� ���� ���� �ȴ�.
	int& result = dp[index][value];
	if (result != -1) return result;

	return result = max(play(index + 1, value + v[index + 1]), play(index + 1, value - v[index + 1]));
}

int main()
{
	cin.tie(0);
	cin >> n >> s >> m;
	for (int i = 1; i <= n; i++) cin >> v[i];
	memset(dp, -1, sizeof(dp));

	int ans = play(0, s);
	if (ans == -100) cout << -1;
	else cout << ans;
	return 0;
}

// �޸� �ʰ� ���
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int v[101];
//vector<int> dp[101];
//int n, m, s;
//int main()
//{
//	cin.tie(0);
//	cin >> n >> s >> m;
//	int ans = 10000;
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> v[i];
//	}
//	dp[0].push_back(s);
//	for (int i = 1; i <= n; i++)
//	{
//		for (int j = 0; j < dp[i - 1].size(); j++)
//		{
//			if (dp[i - 1][j] + v[i] <= m)
//			{
//				dp[i].push_back(dp[i - 1][j] + v[i]);		// ����
//			}
//			if (dp[i - 1][j] - v[i] >= 0)
//			{
//				dp[i].push_back(dp[i - 1][j] - v[i]);			// ����
//			}
//		}
//	}
//	if (dp[n].size() == 0) cout << -1;
//	else{
//		cout << *max_element(dp[n].begin(), dp[n].end());
//	}
//	return 0;
//}
