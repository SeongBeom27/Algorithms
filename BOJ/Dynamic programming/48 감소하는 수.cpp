//#include <iostream>
//#include <string>
//using namespace std;
//long long dp[1000001];
//// ����� X�� �ڸ����� ū �ڸ������� ���� �ڸ������� �����Ѵٸ�, �� ���� �����ϴ� ������Ѵ�.
//// Ex 1. 432, 950�� �����ϴ� ������ 322, 928�� �ƴϴ�.
//// ���� : N��° �����ϴ� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
//
//// ���� �ľ� : �����ϴ� ���� ã�� ���ε� 0�� 0��° ���� 1�� 1��° �����ϴ� ���̴�..?
////				���� N��° �����ϴ� ���� ���ٸ� -1�� ����ؾ� �Ѵ�.
//bool check(string a)
//{
//	for (int i = 0; i < a.length() - 1; i++)
//	{
//		if (a[i] <= a[i + 1])
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//int main()
//{
//	int n; cin >> n;
//	for (int i = 0; i <= 10; i++)		// 1�� �ڸ��� ���� ä�� �ֱ�
//	{
//		dp[i] = i;
//	}
//	int num = 19;
//	for (int i = 11; i <= n; i++)
//	{
//		// �����ϴ� ������ Ȯ���ؾ��Ѵ�. 11���� ����
//		while (1)
//		{
//			num++;
//			// �����ϴ� ���� ������ �Ǹ� ó���� 10�� �ڸ� �� ������ ���� �ڸ�
//			// �ְ��ڸ����� ���� �������ش�.
//			if (check(to_string(num)))			// check �Լ��� num�� �����ϴ� ������ Ȯ�εǸ�
//			{
//				dp[i] = num;
//				break;
//			}
//		}
//	}
//	cout << dp[n];
//
//	return 0;
//}
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 1000000;

int n;
int idx = 9;	// 1 ~ 9�� �̹� ���Ҽ���� ����
// idx�� idx��°�� �����ϴ� ���� ��ġ�� �ȴ�.
queue<long long> q;
long long descending[MAX + 1];

void preCalculate()
{
	while (idx <= n)
	{
		if (q.empty())
			return;
		long long descendingNum = q.front();		// ó������ 1�� ���� ���̴�. << �����ϴ� ��
		q.pop();
		// ������ ���� Ȯ��
		int lastNum = descendingNum % 10;			//
		// ������ �ڸ� ���ں��� ���� ���ڵ��� �ٿ� ������.
		for (int i = 0; i < lastNum; i++)
		{
			q.push(descendingNum * 10 + i);
			descending[++idx] = descendingNum * 10 + i;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= 9; i++)
	{
		q.push(i);
		descending[i] = i;
	}
	preCalculate();

	if (!descending[n] && n)		// N�� ���� �ʰ��ϸ�
		cout << -1 << endl;
	else {
		cout << descending[n] << endl;
	}
	return 0;
}