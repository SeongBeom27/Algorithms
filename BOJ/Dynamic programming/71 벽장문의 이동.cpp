#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 21
using namespace std;
// ���幮�� �̵�

// �� ���� �տ� �ִ� ���� �̿� ���� �տ� ���� ���ٸ�(��, ������ �����ִٸ�), 
// �� ���� ������ ������ �� �ִ�.
int n;
int use;
int order[MAX];			// ���� ��� ����
// target �ε��� ��ġ ������ ������� ��, ���� open1, oepn2�� �����ִ� ���
// �ּҷ� ������ �̵��ϴ� ���
int dp[MAX][MAX][MAX];

// ������ϴ� ���幮
int solution(int targetidx, int open1, int open2)
{
	if (targetidx == use + 1) return 0;
	int& result = dp[targetidx][open1][open2];
	
	if (result != -1)
		return result;

	// open 1�� target�� �ٲٴ� ���
	//abs(open1 - order[targetidx]) + solution(targetidx + 1, order[targetidx], open2)
	// open 2�� target�� �ٲٴ� ���
	// abs(open2 - order[targetidx]) + solution(targetidx + 1, open1, order[targetidx])
	return result = min(abs(open1 - order[targetidx]) + solution(targetidx + 1, order[targetidx], open2),
		abs(open2 - order[targetidx]) + solution(targetidx + 1, open1, order[targetidx]));
}


int main()
{
	int ans = 0;
	// ������ �ΰ��� ������ �����ִ�.
	cin >> n;
	int open[2];
	cin >> open[0] >> open[1];
	cin >> use;
	for (int i = 1; i <= use; i++)
		cin >> order[i];

	memset(dp, -1, sizeof(dp));

	cout << solution(1, open[0], open[1]) << endl;
	return 0;
}