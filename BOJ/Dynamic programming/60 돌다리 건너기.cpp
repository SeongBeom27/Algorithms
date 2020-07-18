#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string key, bridge[2];
int dp[2][101][21];
/*
1. ����(�������)���� ������(��������)���� �ٸ��� �������� �ϸ�, 
�ݵ�� ������ �η縶���� ���� ���ڿ��� ������� ��� ��� �������� �Ѵ�.

2. �ݵ�� <�Ǹ��� ���ٸ�>�� <õ���� ���ٸ�>�� �����ư��鼭 ���� ��ƾ� �Ѵ�. 
	��, ����� � ���ٸ����� �����ص� �ȴ�.

3. �ݵ�� �� ĭ �̻� ���������� �����ؾ��ϸ�, �ǳʶٴ� ĭ�� ������ ����� ����. 
���� ���ٸ��� ����� �׸� 1�� ���� �η縶���� ���ڿ��� "RGS"��� ���ٸ��� �ǳʰ� �� �ִ� 
���� ������ 3���� ���̴�. (�Ʒ� �׸����� ������ ���ڴ� ��� �������� ���ٸ��� ��Ÿ����.)
*/
int solution(int row, int col, int idx)
{
	// ���� ���, ������ ã�� ���
	if (idx == key.length())
		return 1;

	int& result = dp[row][col][idx];
	if (result != -1)
	{
		return result;
	}

	result = 0;
	for (int i = col; i < bridge[0].length(); i++)
	{
		if (bridge[row][i] == key[idx])
		{
			result += solution(1 - row, i + 1, idx + 1);
			cout << result << endl;
		}
	}
	return result;
}

int main()
{
	int ans = 0;
	cin >> key;
	cin >> bridge[0]; cin >> bridge[1];
	memset(dp, -1, sizeof(dp));
	// �Ǹ��� ���ٸ����� �����ϴ� ���
	ans += solution(0, 0, 0);
	// õ���� ���ٸ����� �����ϴ� ���
	ans += solution(1, 0, 0);
	cout << ans;
	return 0;
}