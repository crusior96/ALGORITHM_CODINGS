#include<iostream>
#include<vector>

using namespace std;
int N;
long long B;
int arr[6][6]; //�ŵ������� �ϰ� �� ����� ����.

//N*N�� ����� B�� �ŵ������ϰ� �� ��� ������ ���ĭ�� ������ ���� ���Ѵ�
//���� �ſ� Ŀ���� ������ ��������⶧���� ������ �迭���� 1000���� ���� �������� �����صд�.

vector<vector<int>> timer(long long num)
{
	vector<vector<int>> time(N, vector<int>(N));
	vector<vector<int>> temp(N, vector<int>(N));

	//������ �ؾ� �ϴ� Ƚ�� �� ¦-Ȧ�� ���¿� ���� �ؾ��ϴ� ����� �޶�����.
	//�̴� X^8 = ((X^2)^2)^2�� ���� �ܼ��� 8���� ������ �ƴ�, X^2�� 3�� �ŵ������ϴ� �������
	//������ Ƚ���� �ٿ��� �ð����⵵�� ���̷��� �����̴�.

	//1. ������ ���� �������
	if (num == 1)
	{
		for (int i = 0;i < N;i++)
		{
			for (int j = 0;j < N;j++)
			{
				temp[i][j] = arr[i][j] % 1000;
			}
		}
		//�׳� 1000���� ���� ���������� ����ִ� ����� temp��Ŀ� �����Ͽ� ��ȯ�Ѵ�.
		return temp;
	}
	//2. �����ϴ� Ƚ���� ¦���ϰ��
	else if (num % 2 == 0)
	{
		//�����ϴ� Ƚ���� 2�� ���� ���� timer�Լ��� �־ �����Ͽ� temp�� �־��ش�.
		temp = timer(num / 2);


		//���� �������� ������ �̹� ������ �Ǿ��ִ� temp�迭���� �������ִ� ��.
		for (int i = 0;i < N;i++)
		{
			for (int j = 0;j < N;j++)
			{
				for (int k = 0;k < N;k++)
				{
					time[i][j] += temp[i][k] * temp[k][j];
				}
				time[i][j] %= 1000;
			}
		}

		return time;
	}
	//3. �����ϴ� Ƚ���� Ȧ���ϰ��
	else
	{
		//�����ϴ� Ƚ������ 1 �� ���� timer�Լ��� �־ �����Ͽ� temp�� �־��ش�.
		temp = timer(num - 1);


		//���� �������� ������ �̹� ������ �Ǿ��ִ� temp�迭�� ������ arr�迭�� 1�� �߰��Ͽ� �����ִ� ��.
		for (int i = 0;i < N;i++)
		{
			for (int j = 0;j < N;j++)
			{
				for (int k = 0;k < N;k++)
				{
					time[i][j] += temp[i][k] * arr[k][j];
				}
				time[i][j] %= 1000;
			}
		}

		return time;
	}
}

int main()
{

	cin >> N >> B;
	vector<vector<int>> time(N, vector<int>(N));
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			cin >> arr[i][j];
		}
	}

	time = timer(B);

	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			cout << time[i][j]<< " ";
		}
		cout << "\n";
	}
	return 0;
}