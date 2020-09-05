#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#define INF 987654321
#define MAX 30
using namespace std;
/*
    �������� : 100��
    �ڳ� : 500��
*/
// �����¿�

// 1. �Դ� ���� �ٽ� ���°� �ǹ̰� �����Ƿ� ����
// 2. �ڳʸ� ã�� ���� ����� 
/*
    dir�� 2, 3�̾��µ� ���� ���� ������ 0, 1�ΰ��
    dir�� 0, 1�̾��µ� ���� ���� ������ 2, 3�ΰ��
*/
// 3. ��ó�� �����Ҷ� 0���ν����ϹǷ� �̶��� ������ �������θ� ��ġ�ϴ� ���̶�� ���� ó��

// 0 : �Ʒ�
// 1 : ��
// 2 : ������
// 3 : ����
const int dx[] = { 0,0,-1,1 }, dy[] = { -1,1,0,0 };
struct path {
    int x, y, z;
};

int solution(vector<vector<int>> board) {
    int answer = 0;
    int siz = board[0].size();
    int dist[26][26][4];
    memset(dist, 1000000, sizeof(dist));
    queue<path> q;
    // �Ʒ� ������ ���� ����
    q.push({ 0,0,1 });
    q.push({ 0,0,3 });
    dist[0][0][1] = dist[0][0][3] = 0;
    while (!q.empty())
    {
        int x = q.front().x, y = q.front().y;
        int z = q.front().z; q.pop();
        int lastcost = dist[x][y][z];
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx < 0 || nx >= siz || ny < 0 || ny >= siz || board[nx][ny]) continue;
            if (k == z) { //���� �������� �̵��� ��
                if (dist[nx][ny][k] > lastcost + 100) {
                    dist[nx][ny][k] = lastcost + 100;
                    q.push({ nx,ny,k });
                }
            }
            else if (dist[nx][ny][k] > lastcost + 600) { //�ٸ� �������� �̵��Ҷ� �ڳ� ��� �߰�
                dist[nx][ny][k] = lastcost + 600;
                q.push({ nx,ny,k });
            }
        }
    }
    // �������� ���������� ���� ��, ���������� ��
    answer = min(dist[siz - 1][siz - 1][1], dist[siz - 1][siz - 1][3]);
    return answer;
}

int main()
{
    vector<vector<int>> board;
    board = { {0, 0, 1, 0 },{0, 0, 0, 0 },{0, 1, 0, 1 },{1, 0, 0, 0 } };
    cout << solution(board);
    return 0;
}

/*
    [[0, 0, 0, 0, 0, 0, 0, 1], [0, 0, 0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 1, 0, 0], [0, 0, 0, 0, 1, 0, 0, 0], [0, 0, 0, 1, 0, 0, 0, 1], [0, 0, 1, 0, 0, 0, 1, 0], [0, 1, 0, 0, 0, 1, 0, 0], [1, 0, 0, 0, 0, 0, 0, 0]]
*/