#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// https://www.acmicpc.net/problem/1092
int crain_n, box_n;
vector<int> crain, box;
int cnt = 0;

void Input()
{
	int value;
	cin >> crain_n;
	for (int i = 0; i < crain_n; i++)
	{
		cin >> value; crain.push_back(value);
	}

	cin >> box_n;
	for (int i = 0; i < box_n; i++)
	{
		cin >> value; box.push_back(value);
	}
}
int main()
{
	Input();
	
	// �������� �����Ѵ�.
	sort(crain.begin(), crain.end(), greater<int>());
	sort(box.begin(), box.end(), greater<int>());

	// ���� ���
	if (crain[0] < box[0])
	{
		cout << -1;
	}
	else {
		// box�� ���� �ű� ������ ����
		while (box.size())
		{
			int crain_idx = 0;
			for (int i = 0; i < box.size(); i++)
			{
				// ��� ũ������ ������ ���
				if (crain_idx == crain.size())
					break;
				// �ű� �� �ִ� ���
				if (crain[crain_idx] >= box[i])
				{
					// ���� ũ�������� �̵�
					crain_idx++;
					box.erase(box.begin() + i);
					--i;
				}
			}
			cnt++;
		}
		cout << cnt;
	}

	return 0;
}