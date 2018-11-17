#include<iostream>
#include<algorithm>
#include<cmath>
#include<limits.h>
using namespace std;


//4���� ����� �ִ� ��ư�� Nȸ ������ ���, �ִ��� ���� �� �ִ� â�� ������ ��ΰ�?
//������ ����� 1. â1�� �����, 2. CTRL + A, 3. CTRL + C, 4. CTRL + V

int main()
{
	unsigned long long int board[200] = {};
	int cache[200] = {};
	int N;
	board[1] = 1;
	board[2] = 2;
	board[3] = 3;
	//��ȭ���� ���� �����صδ� �ʱⰪ. �Է� Ƚ���� 1~3ȸ�� ��쿡�� �ܼ��� â�� �߰����ִ� ���� �ִ��� ���� �� �ִ� â�� ������ �˷��ָ�
	//�������� ��ü ���� �� ���縦 �� ���� �ٿ��ֱ⸦ �ϱ������ �Է� Ƚ���� �����ϴ�.
	unsigned long long int answer = 0;
	cin >> N;
	if (N == 1)
	{
		answer = board[1];
	}
	else if (N == 2)
	{
		answer = board[2];
	}
	else if (N == 3)
	{
		answer = board[3];
	}
	else//N�� ���� 4 �̻��� �� ���� ��������� ������ ��, �ܼ��� â�� �߰��� ����, ���� ���� ������ ������ ����� ���� �� ���������� ���Ѵ�.
	for (unsigned long long int i = 4;i <= N;i++)
	{
		int l = 2;
		//i��° �Է�Ƚ������ â�� 1���� �߰��� �� ���� (i-1)��°���� �Է����� ���� �ִ񰪿��� â�� 1�� �߰��� ���� �ִ��� ����.
		unsigned long long int maxNum = max(i, board[i - 1] + 1);
		for (int k = i - 3;k >= 1;k--)//i-3�� ���ִ� ������, ��ü ����(1ȸ), ����(1ȸ), �ٿ��ֱ�(1ȸ) �� 3ȸ�� ������ ���� ���簡 �Ǳ� ����.
		{
			maxNum = max(maxNum, board[k] * l);
			l++;
			//���ʿ� ������ ���� �ٿ������� ���� ���� 2(���⿡ ��� l�� ����Ѵ�.)�谡 �Ǳ� ������
			//���� �� ���� ��� �ٿ��ִ� ������ �����ϱ� ���� l ���� �÷��ش�.
		}
		board[i] = maxNum;
	}

	cout << board[N] << endl;

	return 0;
}