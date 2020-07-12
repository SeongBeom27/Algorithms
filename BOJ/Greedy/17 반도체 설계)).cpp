#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

// �̺� Ž������ Ǯ��� �ϴ� ����
// lower_bound
// ����Ž�� ����� Ž�� ����̴�.
// ã�����ϴ� key���� ������ key������ ū ���� ���� ���� ���� ã�´�.
// ���� ���Ұ� ���� �� �־ ������� �׻� ������ �ظ� ���� �� �ִ�.

int main() {

    int n, i, temp;
    cin >> n;
    vector<int> dp;
    dp.push_back(0);

    for (i = 0; i < n; i++) {
        cin >> temp;
//        cout << "dp.back () : " << dp.back() << endl;
        if (dp.back() < temp) dp.push_back(temp);
        else {
//            cout << "dp.back : " << dp.back();
            vector<int>::iterator it = lower_bound(dp.begin(), dp.end(), temp);
            cout << " temp : " << temp << endl;
            *it = temp;         // 4�κп� 2�� �ִ´�.
            for (int a : dp)
            {
                cout << "dp�� �� : " << a << endl;
            }
        }
    }

    printf("%lu\n", dp.size() - 1);

    return 0;
}