#include <iostream>

#define MAX 1000
// https://www.acmicpc.net/problem/2873
using namespace std;

int a[MAX][MAX];

int main()
{
	int R, C;
	int sum(0);
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	
	int x(0), y(0);
	if (R % 2)		// ���� Ȧ���̴�. RRDLL ������ �� �� �ִ�.
	{
		while (1)
		{
			// ���������� �̵�
			while (y != C - 1)
			{
				++y;
				printf("%c", 'R');
			}
			if (x == R -1  && y == C - 1)
			{
				return 0;	// ����
			}
			x++;
			printf("%c", 'D');
			while (y != 0)
			{
				--y;
				printf("%c", 'L');
			}
			x++;
			printf("%c", 'D');
		}
	}
	else if (C % 2) // ���� Ȧ �� �̴�.
	{
		while (1)
		{
			// �Ʒ������� �̵�
			while (x != R - 1)
			{
				++x;
				printf("%c", 'D');
			}
			if (x == R - 1 && y == C - 1)
			{
				return 0;	// ����
			}
			y++;
			printf("%c", 'R');
			while (x != 0)
			{
				--x;
				printf("%c", 'U');
			}
			y++;
			printf("%c", 'R');
		}
	}
	else if(!(R % 2) && !(C % 2))
	{	
		
	}
	
	return 0;
}