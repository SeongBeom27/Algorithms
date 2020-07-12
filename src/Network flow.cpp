#include <iostream>
#include <queue>
#include <vector>

#define MAX 100
#define INF 1000000000							// ���Ѵ� ǥ��	
using namespace std;

int n = 6 , result;
int c[MAX][MAX], f[MAX][MAX], d[MAX];			// �뷮, ����, ���ư��� ���� �� ��� ��� (���� Ư�� ��带 �湮�� �ߴ����� ���� �迭)
vector<int> a[MAX];								// ����� ������ ǥ��

void maxFlow(int start, int end)
{
	while (1)
	{
												// ��� ������ �湮���� ���� ���·�
		fill(d, d + MAX, -1);					// �� ��ΰ� ���� ������ d�� ���� -1�� �ʱ�ȭ �ȴ�.
		queue<int> q;
		q.push(start);
		while (!q.empty())
		{
			int x = q.front();
			q.pop();
			for (int i = 0; i < a[x].size(); i++)
			{
				int y = a[x][i];
				// �湮���� ���� ��� �߿� �뷮�� ���� ���, �� ������ �� �带 �� �ִ� ���
				if (c[x][y] - f[x][y] > 0 && d[y] == -1)			
				{
					q.push(y);
					d[y] = x;					// ��θ� ����մϴ�.
					if (y == end) break;		// ������
				}
			}
		}

		// ������ end���� ���� ���Ѵٴ� ���� �뷮�� �� á�ٴ� �ǹ�										
		if (d[end] == -1) break;		// ��� ��θ� �� ã�� Ż���Ѵ�.

		int flow = INF;
		
		// i = d[i] �ǹ̴� �ڽ� ������ �ִ� ���� ���ƿ��鼭 �Ųٷ� ���ư��� ��.
		for (int i = end; i != start; i = d[i])					// �Ųٷ� �ּ� ���� Ž��
		{
			// ù��°�� ��쿡�� �ּ� �뷮�� flow�� �� ���̴�.
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);			// ���� ���� ���� ������ ���� ������ �����������.
		}

		// �ּ� ������ŭ �߰��Ѵ�.
		for (int i = end; i != start; i = d[i])
		{
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;
		}

		result += flow;
		//cout << "Ȯ�� : " << f[2][3] << endl;
		//cout << "2 - > 3  �뷮 : " << f[2][3] << endl;
		//cout << "2 - > 3  ���� : " << f[2][3] << endl;
		//cout << "3 - > 2  ���� : " << f[3][2] << endl;
	}
}
// https://koosaga.com/18  �� ���� �˰��� ����
int main()
{
	a[1].push_back(2);
	a[2].push_back(1);
	c[1][2] = 12;

	a[1].push_back(4);
	a[4].push_back(1);
	c[1][4] = 11;

	a[2].push_back(3);
	a[3].push_back(2);
	c[2][3] = 6;

	a[2].push_back(4);
	a[4].push_back(2);
	c[2][4] = 3;

	a[2].push_back(5);
	a[5].push_back(2);
	c[2][5] = 5;

	a[2].push_back(6);
	a[6].push_back(2);
	c[2][6] = 9;

	a[3].push_back(6);
	a[6].push_back(3);
	c[3][6] = 8;

	a[4].push_back(5);
	a[5].push_back(4);
	c[4][5] = 9;

	a[5].push_back(3);
	a[3].push_back(5);
	c[5][3] = 3;

	a[5].push_back(6);
	a[6].push_back(5);
	c[5][6] = 4;


	maxFlow(1, 6);
	cout << result << endl;
	return 0;
}