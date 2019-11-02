#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

//N���� ���ڸ� �Է¹޾Ƽ� ���밪�� ���� ���ں��� ����Ѵ�.
//�̶�, ���밪�� ���� ���ڰ� �ΰ� �̻� �ִٸ�, �� ���ڵ� �� �������� �켱������ ����Ѵ�.
//���� ����� ���ڰ� �������� �ʴٸ� 0�� ����Ѵ�.

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//����� �ð��� ���̱� ���� �ڵ�
	priority_queue <int> PQ_plus;
	priority_queue <int> PQ_minus;
	//���� �Է¹��� ���� ���, ������ �� ����Ǿ����� �켱���� ť
	//���ǿ� �°� �����ϱ� ���� plus ť�� ���� ������ �� -1�� �����ش�.
	//�׷��� ���밪�� ������������ ���ڰ� ���ĵȴ�.
	int N;
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		int temp;
		cin >> temp;
		if (temp == 0)
		{
			//��� �� ���ڰ� ���� ������ 0 ���
			if (PQ_plus.empty() == 1 && PQ_minus.empty() == 1)
			{
				cout << "0\n";
			}
			else
			{
				if (PQ_plus.empty() == 0 && PQ_minus.empty() == 1)
				{
					cout << PQ_plus.top() * -1 << "\n";
					PQ_plus.pop();
				}
				else if (PQ_plus.empty() == 1 && PQ_minus.empty() == 0)
				{
					cout << PQ_minus.top() << "\n";
					PQ_minus.pop();
				}
				//��� �� ���ڰ� ���� ť���� ������ �� ���� top()�� ���
				else if (PQ_plus.empty() == 0 && PQ_minus.empty() == 0)
				{
					if (abs(PQ_plus.top()) >= abs(PQ_minus.top()))
					{
						cout << PQ_minus.top() << "\n";
						PQ_minus.pop();
					}
					else if (abs(PQ_plus.top()) < abs(PQ_minus.top()))
					{
						cout << PQ_plus.top() * -1 << "\n";
						PQ_plus.pop();
					}
					//�� �� �� ���ڰ� �����ִٸ� �������� ť�� top()�� ���Ͽ� ���밪�� ���� ���ں��� ����Ѵ�.
					//�� ��, ������ ���ڰ� ���ٸ�, ���� ���ڸ� ����Ѵ�.
				}
			}
		}
		else if(temp!=0)
		{
			if (temp > 0)
			{
				PQ_plus.push(-temp);
			}
			else if (temp < 0)
			{
				PQ_minus.push(temp);
			}
		}
	}
	return 0;
}