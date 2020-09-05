#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int pad[4][3];
pair<int, int> left_finger = make_pair(3, 0);
pair<int, int> right_finger = make_pair(3, 2);

int Calcdistance(pair<int,int> fingerloc, pair<int, int> targetloc)
{
    int dist;

    int x = abs(fingerloc.first - targetloc.first);
    int y = abs(fingerloc.second - targetloc.second);

    return x + y;
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    for (int i = 0; i < numbers.size(); i++)
    {
        int cur = numbers[i];
        if (cur == 1 || cur == 4 || cur == 7)
        {
            // ���� 0�� , -1�ؼ� 3���� ���� �࿡ ������ �ȴ�.
            left_finger = make_pair((cur - 1) / 3, 0);
            answer += 'L';
        }
        else if (cur == 3 || cur == 6 || cur == 9)
        {
            // ���� 2��
            right_finger = make_pair((cur / 3 ) - 1, 2);
            answer += 'R';
        }
        else {
            // ���� 1��, �Ÿ� ����ؾ��ϴ� �� 
            if (cur == 0) cur = 11;         // ����� ���ϰ� �ϱ� ����
            pair<int, int> target_num = make_pair((cur - 2) / 3, 1);
            int left_dist = Calcdistance(left_finger, target_num);
            int right_dist = Calcdistance(right_finger, target_num);

            // �Ÿ��� ���� ���, ������ Ȯ��
            if (left_dist == right_dist)
            {
                if (hand == "left")
                {
                    left_finger = target_num;
                    answer += 'L';
                }
                else {
                    right_finger = target_num;
                    answer += 'R';
                }
            }
            else if(left_dist > right_dist) {
                right_finger = target_num;
                answer += 'R';
            }
            else {
                left_finger = target_num;
                answer += 'L';
            }
        }
    }
    return answer;
}

int main()
{
    vector<int> numbers = { 7, 0, 8, 2, 8, 3, 1, 5, 7, 6, 2 };

    cout << solution(numbers, "left");
    return 0;
}