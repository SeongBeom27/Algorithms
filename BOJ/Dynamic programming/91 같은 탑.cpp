#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 51
#define MAXHEIGHT 500000
#define INF 987654321

int n;
int top[MAX];
int ans = -1;
// �� ž�� �ְ� ���̴� MAXHEIGHT / 2 + 1�̴�.
int dp[MAX][MAXHEIGHT / 2 + 1];

// �� ���� ���� 4���� ����� ���� �ʿ��ϴ�.
// 1. �ش� ���� ���� �ʴ� ���
// 2. �ش� ���� �� ���� ž�� �״� ���
// 3. �ش� ���� �� ���� ž�� �״� ���
//    3.1 �ش� ���� ž ���� ���������� Ŭ ���
//    3.2 �ش� ���� ž ���� ���������� ���� ���

// ž ���� �������� �ʰ� or ������ ��ϱ��� ����ص� �������� �����ϸ� ���� x

using namespace std;

int solution(int idx, int heightdiff)
{
	if (heightdiff > MAXHEIGHT / 2)
		return -INF;
	if (idx == n + 1 && heightdiff)			// height�� �� ž�� �������̴�
		return -INF;

	// ��� ���� ����
	if (idx == n + 1 && heightdiff == 0)
		return 0;

	int& result = dp[idx][heightdiff];
	if (result != -1) 
		return result;

	result = -INF;
	// idx ����� �Ⱦ��� ���
	result = max(result, solution(idx + 1, heightdiff));

	// idx�� ���� �� ���� ž�� ��� �ϴ� ��쿡�ٰ� top[idx]�� �����ָ� �ȵǴ� ����..?
	// idx ������ �� ���� ž�� ����ϴ� ���
	result = max(result, solution(idx + 1, heightdiff + top[idx]));


	// idx ������ �� ���� ž�� ����ϴ� ���
		// ��ϳ��̰� ž�� ���̺��� �� ū ���
	if (top[idx] > heightdiff)
		result = max(result, heightdiff + solution(idx + 1, top[idx] - heightdiff));
	else
		// ž�� ���̰� ��ϳ��̺��� �� ū ���
		result = max(result, top[idx] + solution(idx + 1, heightdiff - top[idx]));
	return result;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); //cin �ӵ� ���
	cin >> n; 
	for (int i = 1; i <= n; i++)
		cin >> top[i];
	memset(dp, -1, sizeof(dp));

	int ans = solution(1, 0);
	if (ans)
		cout << ans << endl;
	else
		cout << -1 << endl;
	return 0;
}