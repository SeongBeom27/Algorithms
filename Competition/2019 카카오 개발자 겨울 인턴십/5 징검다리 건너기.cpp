#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
    �ϴ��� ģ������ ¡�˴ٸ��� �ǳ� ���� ��Ģ

    1. ¡�˴ٸ��� �Ϸķ� ���� �ְ� �� ¡�˴ٸ��� ��������� ��� ���ڰ� ���� ������ ������� ���ڴ� �� �� ���� ������ 1�� �پ��ϴ�.
    2. ������� ���ڰ� 0�� �Ǹ� �� �̻� ���� �� ������ �̶��� �� ���� ������� �ѹ��� ���� ĭ�� �ǳ� �� �� �ֽ��ϴ�.
    3. ��, �������� ���� �� �ִ� ������� ���� ���� ��� ������ ���� ����� ������θ� �ǳʶ� �� �ֽ��ϴ�.
    4. �� ���� ��� �ǳʰ� ������ ���� �ο��� �ǳʰ� �� �ִ�.

    �Է�

    (1) ������� ���� ���� ������� ��� �迭
    (2) �� ���� �ǳʶ� �� �ִ� ������� �ִ� ĭ��

    ���

    -> �ִ� ������ ¡�˴ٸ��� �ǳ� �� �ִ����� return
*/

using namespace std;

bool check(vector<int> stones, int k, int mid) {
	int cnt = 0;
	for (int i = 0; i < stones.size(); i++) {
		// ���� �ο� ���� ���� ���ں��� �� ū ��찡 k�� �̻� ���ӵȴٸ� �Ұ���
		if (stones[i] < mid) {
			cnt++;
			if (cnt >= k) return false;
		}
		else cnt = 0;
	}
	// ���� ���ڰ� 0�̵Ǵ� ��찡 k�� �̻� ���ӵ��� �ʴ´ٸ� ����
	return true;
}


int solution(vector<int> stones, int k) {
	int answer = 0;

	int right = *max_element(stones.begin(), stones.end());
	int left = 1;

	// ¡�˴ٸ��� �ǳʴ� �ο� ���� �������� �̺�Ž��
	while (left <= right) {
		int mid = (left + right) / 2;
		if (check(stones, k, mid)) {
			left = mid + 1;
			if (answer < mid) {
				answer = mid;
			}
		}
		else {
			right = mid - 1;
		}
	}

	return answer;
}

int main()
{
    vector<int> stones = { 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 };
    int k = 3;
    cout << solution(stones, k);
    
	return 0;
}