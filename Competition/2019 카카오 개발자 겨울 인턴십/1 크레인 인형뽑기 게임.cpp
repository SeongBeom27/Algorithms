#include <iostream>
#include <string>
#include <vector>
#include <stack>
/*
    0�� ��ĭ, 1 ~ 100�� �� �� �ٸ� ������ ���Ѵ�.

*/
using namespace std;
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int len = board[0].size();
    stack<int> barket;
    int column;
    for (int i = 0; i < moves.size(); i++)
    {
        // ���� ũ������ ��ġ
        column = moves[i] - 1;

        // loc ���� ���� Ž��
        for (int j = 0; j < len; j++)
        {
            int target = board[j][column];
            board[j][column] = 0;
            // 0�̸� ����ø��� �ʴ´�.
            if (target == 0) continue;

            // �ٱ��ϰ� ������� ���� ���
            if (!barket.empty())
            {
                // �ٱ��� ������ �ִ� ���� ������
                if (barket.top() == target)
                {
                    barket.pop();
                    answer += 2;
                }
                else {
                // �ٱ��� ������ �ִ� ���� �ٸ���, �׳� �ִ´�.
                    barket.push(target);
                }
            }
            else {
            // ������� ���� ��쿣 �׳� �ִ´�.
                barket.push(target);
            }
            // 0�� �ƴϸ�, ����÷��� �ٱ��Ͽ� �ִ´�.
            break;
        }
        
    }
    return answer;
}

int main()
{
    //int board[5][5] = { {0, 0, 0, 0, 0} ,{0, 0, 1, 0, 3},{0, 2, 5, 0, 1},{4, 2, 4, 4, 2},{3, 5, 1, 3, 1} };
    //
    //vector<int> moving;
    //moving.push_back(1); moving.push_back(5); moving.push_back(3); moving.push_back(5); moving.push_back(1); moving.push_back(2); moving.push_back(1); moving.push_back(4);
    //cout << solution(board, moving);
    return 0;
}