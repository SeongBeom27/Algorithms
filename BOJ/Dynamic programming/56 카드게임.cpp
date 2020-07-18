#include <iostream>
#include <cstring>
#include <algorithm>
// ī�� ����
// https://www.acmicpc.net/problem/10835
#define MAX 2000
using namespace std;
int n;
int dp[MAX + 1][MAX + 1];
int a[MAX + 1];
int b[MAX + 1];

int solution(int left, int right)
{
	// ī�� ���̰� �������� ���� ���
	if (left == n || right == n) return 0;
	int& val = dp[left][right];
	if (val != -1) return val;
	// ���� ī���� ���ڰ� ������ ī���� ���ں��� Ŭ ���� ������ ī�带 ���� ���� ��
	// ������ ī���� ���ڰ� ũ�� ���� ī�常 ���� ���� �Ѵ� ���� ��츦 ��
	val = a[left] > b[right] ? max(val, solution(left, right + 1) + b[right]) : max(solution(left + 1, right), solution(left + 1, right + 1));
	return val;
}

int main()
{
	cin >> n; int left, right, value, grade = 0;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	memset(dp, -1, sizeof(dp));
	cout << solution(0, 0);
	return 0;
}