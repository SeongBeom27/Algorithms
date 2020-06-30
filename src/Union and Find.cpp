#include <stdio.h>

// x�� �θ� ��带 ã�� �Լ�			<< �θ� ��带 �������ִ� �Լ�
int getParent(int parent[], int x)
{
	// �ش� �θ� ���� x���� ���� ���
	if (parent[x] == x) return x;			// 1�� ��� �����ϸ� �� �κ��� ����ϴ� ���� 1�̵� ���̴�.
	// ���� �θ� ã�� ����
	return parent[x] = getParent(parent, parent[x]);
}

// �� �θ� ��带 ��ġ�� �Լ�		<< ��尣�� �������ִ� �Լ�
void unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

// ���� �θ� �������� Ȯ��		<< ��尣�� �������� �̷����ִ��� Ȯ���ϴ� �Լ�
int findParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);

	if (a == b) return 1;
	return 0;
}

int main()
{
	int parent[11];
	for (int i = 1; i <= 10; i++)
	{
		parent[i] = i;
	}

	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);

	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);

	printf("1�� 5�� ����Ǿ� �ֳ���?? : %d\n", findParent(parent,1, 5));

	unionParent(parent, 1, 5);

	printf("1�� 5�� ����Ǿ� �ֳ���?? : %d\n", findParent(parent, 1, 5));
	return 0;
}
