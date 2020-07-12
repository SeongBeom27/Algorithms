#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// 1���� ������ ���� ���� ���� == �ְ��� ����

	int n; cin >> n;		// ������ ���� ��
	int A; int B;			// dow, topping�� ����
	int dow_cal; 
	int total_cal = 0; int price = 0;		// �� ����, �� ����
	vector<int> topping_cal(n);	// �� ���ε��� ����
	cin >> A >> B;
	cin >> dow_cal;			// ������ ����
	for (int i = 0; i < n; i++)
	{
		cin >> topping_cal[i];
	}

	total_cal = dow_cal;
	price = A;
	sort(topping_cal.begin(), topping_cal.end());
	reverse(topping_cal.begin(), topping_cal.end());
	// ���� ������ ���� Į�θ����� ������� �����غ���
	for (int i = 0; i < n; i++)
	{
		// 1���� ������ �� �������� ���� ����
		if ((total_cal + topping_cal[i]) / (price + B) >= total_cal / price)
		{
			price += B;
			total_cal += topping_cal[i];
		}
		else {
			break;
		}
	}

	// �� ���� �� ������ �����ص��ǰ� ���ص��ȴ�.
	cout << total_cal/price;
	
	return 0;
}