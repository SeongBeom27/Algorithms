#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<long long> num;
    vector<char> exp, location;
    string n = "";

    // ���ڿ� �����ڸ� ����
    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
        {
            // ���ݱ��� ���� ���� �� �ֱ�
            num.push_back(stoi(n));
            n = "";
            // �������̸� �����ڿ� ���� �ֱ�
            if (find(exp.begin(), exp.end(), expression[i]) == exp.end())
                exp.push_back(expression[i]);
            location.push_back(expression[i]);
        }
        else
            // ���� ã��
            n += expression[i];
    }

    num.push_back(stoi(n));

    // ���� �����ڸ����� ������ �����鼭 Ȯ���Ѵ�. 
    // �ð��� ������ �� �ִ� ���
    sort(exp.begin(), exp.end());

 
    do
    {
        // ���� ���� ���ʱ�ȭ 
        vector<long long> tmp_num = num;
        vector<char> tmp_loc = location;

        // tmp_num�� �ִ� ������ ���� �����ϸ鼭 �ϳ��� ��(���� ���)���� �����.

        // �� ������ ������ŭ ��ȯ
        for (int i = 0; i < exp.size(); i++)
        {
            // �� ������ ������ŭ ��ȯ
            for (int j = 0; j < tmp_loc.size(); j++)
            {
                // j ��°�� �ִ� �����ڿ� ���� �켱�������� �����ڶ� ���ٸ� ����
                if (exp[i] == tmp_loc[j])
                {
                    if (tmp_loc[j] == '+')
                        tmp_num[j] = tmp_num[j] + tmp_num[j + 1];
                    else if (tmp_loc[j] == '-')
                        tmp_num[j] = tmp_num[j] - tmp_num[j + 1];
                    else if (tmp_loc[j] == '*')
                        tmp_num[j] = tmp_num[j] * tmp_num[j + 1];

                    // ���� ���� j�� ������ �����Ƿ� j + 1 ��ġ�� �ִ� ���� �������ش�.
                    tmp_num.erase(tmp_num.begin() + j + 1);
                    tmp_loc.erase(tmp_loc.begin() + j);
                    j--;
                }
            }
        }

        if (answer < abs(tmp_num[0]))
            answer = abs(tmp_num[0]);
    } while (next_permutation(exp.begin(), exp.end()));

    return answer;
}

int main()
{
    string test;
    test = "100-200*300-500+20";

    cout << solution(test);
    return 0;
}
