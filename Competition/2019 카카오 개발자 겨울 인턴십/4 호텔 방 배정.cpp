#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#define MAX 200002
using namespace std;
/*
        k���� ���� �����ϴ� ����

        1. �� ���� �� �� ��û�� ������� ���� �����մϴ�.
        2. ���� �����ϱ� ���ϴ� �� ��ȣ�� �����մϴ�.
        3. ���� ���ϴ� ���� ��� �ִٸ� ��� �����մϴ�.
        4. ���� ���ϴ� ���� �̹� �����Ǿ� ������ ���ϴ� �溸�� ��ȣ�� ũ�鼭 ����ִ� �� �� ���� ��ȣ�� ���� ���� �����մϴ�.

        �Է�

        1. ��ü �� ���� : k��
        2. ���ϴ� �� 

        ���

        ������ ������ ��
*/
unordered_map<long, long> m;
vector<long long> answer;

long long find_n(long long n)
{
    if (m[n] == 0)
    {
        m[n] = n + 1;
        answer.emplace_back(n);
        return n;
    }
    return m[n] = find_n(m[n]);
}
vector<long long> solution(long long k, vector<long long> room_number) {
 
    m.reserve(MAX); 
    answer.reserve(MAX);

    for (int i = 0; i < room_number.size(); i++)
    {
        long long n = room_number[i];
        // ���� ���������
        if (m[n] == 0)
        {
            answer.emplace_back(n);
            m[n] = n + 1;
        }
        else {
        // ���� ������� ������
            find_n(n);
        }
    }
    return answer;
}

int main()
{
    int k = 0;
    vector<long long> room_number;
    room_number.push_back(1); room_number.push_back(3); room_number.push_back(4); room_number.push_back(1); room_number.push_back(3); room_number.push_back(1);
    vector<long long > answer;
    answer =  solution(k, room_number);

    for (auto b : answer)
    {
        cout << b << " ";
    }
	return 0;
}