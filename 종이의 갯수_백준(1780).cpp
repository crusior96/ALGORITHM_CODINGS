#include <iostream>
using namespace std;
#pragma warning(disable:4996)

//3�� �ŵ��������� N*Nĭ��ŭ�� ���̰� �ִٰ� ��������
//������ ���� ������ -1, 0, 1�� ���ڰ� ��������.
//������ ������ ���� ���̰� 3�� �ŵ������� ���̸� ���� ���̰� �� ���� ����.
//�ִ��� ���� ���̰� �� ���̵���� ���ٰ� ������ ��, ������ ���ڵ�� �̷���� ���̵��� ������ ���Ͽ���.


const int MAX = 2187; //3^7

int N;
int arr[2187][2187]; //������ ������ ����Ǵ� �迭
int result[3];		 //���̿� ���� ���� ���� �� �������� ����Ǿ����� �迭



void func(int n, int y, int x)

{
	//���� ���
	if (n == 1)
	{
		result[arr[y][x] + 1]++;
		return;
	}

	bool minus = true, zero = true, plus = true; //���̿� ���� ��ȣ���� ����ڸ��� true�� ����ȴ�.
	for (int i = y; i < y + n; i++)
	{
		for (int j = x; j < x + n; j++)
		{
			if (arr[i][j] == -1)
			{
				zero = false;
				plus = false;
			}
			else if (arr[i][j] == 0)
			{
				minus = false;
				plus = false;
			}
			else
			{
				minus = false;
				zero = false;
			}
		}
	}
	//���� ������ ���̰� ���� �� 0���� 1���� 2���� ���Ѵ�.
	//�׷��� ���� ���̶�� ���� ���� �������� �����Ͽ� �ٽ� Ž���Ѵ�.
	//������ ������ ���� ���� ������ ��Ȯ�ϰ� 9���� ���簢������ �ڸ� �����̸� 
	if (minus)
		result[0]++;
	else if (zero)
		result[1]++;
	else if (plus)
		result[2]++;
	else
	{
		int div = n / 3;
		func(div, y, x);
		func(div, y, x + div);
		func(div, y, x + 2 * div);

		func(div, y + div, x);
		func(div, y + div, x + div);
		func(div, y + div, x + 2 * div);

		func(div, y + 2 * div, x);
		func(div, y + 2 * div, x + div);
		func(div, y + 2 * div, x + 2 * div);

	}

	return;

}



int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];

	func(N, 0, 0);
	for (int i = 0; i < 3; i++)
		cout << result[i] << "\n";

	return 0;

}