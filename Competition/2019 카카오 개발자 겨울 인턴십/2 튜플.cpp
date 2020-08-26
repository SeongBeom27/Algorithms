#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#define MAX 100000
using namespace std;

bool check[MAX];
class setinfo {
public:
    vector<int> num;
    int total = 0;
};

bool moving(class setinfo t1, class setinfo t2)
{
    if (t1.total < t2.total) return true;
    return false;
}

vector<int> solution(string s) {
    vector<int> answer;
    int finish = 0;
    int element_num = 1;
    vector<class setinfo> v;
    // parsing
    // ���� ū { } �� �����ϱ� ���ؼ� �Ʒ��� ���� ����, ��
    class setinfo now;
    // 1. ���ҿ� ���� ũ�⸦ �����ϴ� Ŭ������ ���Ϳ� ��´�.
    for (int i = s.length() - 2; i > 0; i--)
    {
        char cur = s[i];
        if (cur == '}')
        {
            element_num = 1;
        }
        if (cur == '{')
        {
            // ���� �� 
            now.total = element_num;
            v.push_back(now);
            now.num.clear();
            now.total = 1;
            finish = 1;
        }
        // 1.1 string ���ڸ� int�� ������ ��ȯ�ؼ� class�� ���Ϳ� �ִ´�.
        if ('0' <= cur && '9' >= cur)
        {
            finish = 0;
            int idx = 0;
            int cur_number = 0;
            while (1)
            {
                cur_number += ((cur - '0') * pow(10, idx));
                if ('0' <= s[i - 1] && '9' >= s[i - 1])
                {
                    idx++; i--;
                    cur = s[i];
                }
                else {
                    break;
                }
            }
            now.num.push_back(cur_number);
        }
        //  1.2 �� ���ҵ��� ���� ���� �� ������ ','�� ������ ������ ������Ű�� ���̴�.
        if (finish == 0 && cur == ',')
        {
            element_num++;
        }
    }
    
    // ������ ������ �������� ���� ���� ����
    sort(v.begin(), v.end(), moving);

    // ������ ������ ���� Ŭ�������� ���ڸ� �ߺ����� answer�� �ʰ� ��Ƴִ´�
    // check�� ���� ���� true�� �־��ָ鼭 �ߺ��� ���� ���� �ʰ����ش�.
    // ������ �ִ� ũ�Ⱑ 100000�̹Ƿ� bool �ڷ��� 2byte�δ� �޸� �ʰ��� ���� �ʴ´�.
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].num.size(); j++)
        {
            // �湮���� �ʾҴ� ���ڸ� ���� �ֱ�
            if (!check[v[i].num[j]])
            {
                answer.push_back(v[i].num[j]);
                check[v[i].num[j]] = true;
            }
        }
    }
    return answer;
}

int main()
{
    string a = "{{20,111},{111}}";
    vector<int> ans;
    ans = solution(a);
    
    for (auto& abc : ans)
    {
        cout << abc << " " << endl;
    }
    return 0;
}