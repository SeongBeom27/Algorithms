#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#define MAX 100000
using namespace std;
// ���� : https://eunchanee.tistory.com/90
/*
    ����

    1. ������ ��� ������ ������ ��� 1�� �̻� �����ϴ� ���� ª�� ������ ã�Ƽ� ����

    2. ���� ª�� ������ ã�Ƽ� ���� ������ ��ȣ, �� ������ ��ȣ�� �迭�� ��Ƽ� ����
*/

vector<int> solution(vector<string> gems) {
    vector<int> answer = { 0, 0 };
    queue<string> q;
    map<string, int> m;

    int gems_size = 0, start = 0, end = MAX + 1, tmp = 0;

    // ��� gems�� key ���� 1�� �����.
    // �ߺ��� �����ϴ� �Ͱ� ����
    for (auto i : gems)
        m[i] = 1;

    // �ּ��� 1���� ��ߵǴ� �� ���� ����
    gems_size = m.size();
    m.clear();


    for (int i = 0; i < gems.size(); i++)
    {
        // ���� ���� ������ ��´�
        if (m[gems[i]] == 0)
            m[gems[i]] = 1;
        else
        // ��Ҵ� �����̸� ������ ���������ش�.
            m[gems[i]] += 1;
        // ���� ������ q�� �ִ´�. <- queue�� ũ�Ⱑ ���� ����
        q.push(gems[i]);

        while (1)
        {
            // ������ ���� �տ� �ִ� ������ �ڿ� �� �ִٸ� ���� �տ� �ִ� ������
            // ���� ���̸� �����Ѵ�.
            if (m[q.front()] > 1)
            {
                // �׷��Ƿ� �������൵ �ȴ�.
                m[q.front()] -= 1;
                q.pop();

                // �׷� �����ϴ� ������ ������Ƿ� tmp�� �� ���� ���ش�.
                tmp++;
            }
            else
                break;
        }

        // ������ �� ��Ұ�, 
        // end : q.size()�� �ִ� ���̹Ƿ� ���ݱ��� ���� �� �ּ� �������� Ȯ�����ش�.
        if (m.size() == gems_size && end > q.size())
        {
            end = q.size();
            start = tmp;
        }
    }
    // 0���� ���������Ƿ� start + 1�� ���ش�.
    answer[0] = start + 1;
    // ���� ��ġ + �������̰� end��ġ
    answer[1] = start + end;
    return answer;
}

int main()
{
    vector<string> gems = { "DIA", "RUBY", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" };
    vector<int> ans;
    ans =  solution(gems);
    cout << ans[0] << " " << ans[1];
    return 0;
}