#include <iostream>
#include <string>
using namespace std;

const int MAX = 50;

string board;

int main()
{
	cin.tie(0); cin >> board;
	int cnt(0);

	for (int i = 0; i < board.length(); i++)
	{
		if (board[i] == 'X')
		{
			cnt++;
		} 
		else {
			if (cnt % 2)			// Ȧ �� �϶� ������ ��ä������
			{
				cout << -1;
				return 0;
			}
			cnt = 0;
		}
		if (cnt == 4)
		{
			// ���� i - 3 ��ġ���� i ���� ���� A�� �ִ´�.
			board[i - 3] = board[i - 2] = board[i - 1] = board[i] = 'A';
			cnt = 0;
		}
		if (cnt == 2)
		{
			if (i + 1 == board.length())
			{
				board[i - 1] = board[i] = 'B';
			} else if (board[i + 1] == '.')		// ���� �� .�̶� 2���� ��
			{
				board[i - 1] = board[i] = 'B';
				cnt = 0;
			}
		}
	}
	if (cnt % 2)
	{
		cout << -1;
	}
	else cout << board << endl;
	return 0;
}