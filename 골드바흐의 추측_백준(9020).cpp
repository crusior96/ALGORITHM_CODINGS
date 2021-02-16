#include<iostream>
#pragma warning(disable:4996)

int primary[1000001] = {};

//100�� ������ ¦���� ���� �ٸ� �� �Ҽ��� ��µ��� �����ָ� �ȴ�.
//�̶�, ���� ���� ����� �ִٸ� �� �Ҽ����� ���̰� ���� ū ���� �켱������ ����Ѵ�.
//���� �� �Ҽ����� ���� �� ���ٸ� ������й��� ������ش�.
//�Է��� 0���� �ް� �Ǹ� �����ų ��.

int main()
{
	bool doit = true;
	primary[1] = 1;
	for (int i = 2;i <= 1000;i++)
	{
		if (primary[i] == 1)
		{
			continue;
		}
		for (int j = i + i;j <= 1000000;j += i)
		{
			primary[j] = 1;
		}
	}

	while (doit)
	{
		int temp;
		int possible = 0;
		scanf("%d", &temp);
		if (temp == 0)
		{
			doit = false;
			break;
			//while�� ����
		}
		else
		{
			for (int i = 2;i <= temp / 2;i++)
			{
				//¦�������� ���� �Ҽ����� ���� ��, �� �� ���� �Ҽ���� ����
				//�� �Ҽ����� ���̰� ū ���� ����ؾ��ϱ� ������
				//���� �Ҽ����� �����ش�
				if (primary[temp - i] == 0 && primary[i]==0)
				{
					printf("%d = %d + %d\n", temp, i, temp - i);
					possible = 1;
					break;
				}
			}

			if (possible == 0)
			{
				printf("Goldbach's conjecture is wrong.\n");
			}
		}
	}

	return 0;
}