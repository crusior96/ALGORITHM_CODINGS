#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//N*Nũ���� ���簢�� �ǿ� �پ��� ���� �������� �ִ�.
//������ �� �ٿ� �����Ǿ��ִ� ������ ������ ����(������, ���Ͽ�)�� �������� ���� �� �ִ�.
//���⼭ �� ���� �̿��� ������ ��ġ�� ���� �ٲ㼭 �������� �ִ��� ���� �� �ִ� ������ ������?

int main()
{
	char candyshop[53][53] = {}; //������ ������ ����Ǵ°�.
	int N;
	string candyline;
	int max_candy = 0;
	int temp_max = 0;
	char now_max; //�������� ������ �Դ� ������ ���۵� ��, � ������ �������� �Դ��� �˷��ִ� ��ǥ.
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		cin >> candyline;
		for (int j = 0;j < N;j++)
		{
			candyshop[i][j] = candyline[j];
		}
		//������ ������ ���ڿ��� �޾Ƽ� char������ ������ candyshop�迭�� �����Ѵ�.
	}

	//������ ��ġ�� �ٲٱ� ��, ������ �������� ������ ���� ��, �������� �ִ��� ���� �� �ִ� ������ ���Ѵ�.
	for (int i = 0;i < N;i++)
	{
		temp_max = 0;
		now_max = candyshop[i][0]; //�� ���۽�, ù��° ĭ�� ���� ������ �������� ���Ѵ�.
		for (int j = 0;j < N;j++)
		{
			if (candyshop[i][j] == now_max) //�տ� ���� ������ ������ ���� ���ٸ�
			{
				temp_max++; //�������� ���� �� �ִ� ���� ����.
			}
			else if(candyshop[i][j]!=now_max) //�տ� ���� ������ ������ ���� �ٸ��ٸ�
			{
				if (max_candy < temp_max) //�������� ���� �� �ִ� ������ ������ �ִ񰪺��� ũ�ٸ�
				{
					max_candy = temp_max; //�ִ��� ���� ���� �������� ���� �� �ִ� ������ �ٲ۴�.
					now_max = candyshop[i][j]; //�ٸ� ������ ������ �������� �ٽ� �񱳸� �����Ѵ�.
					temp_max = 1;
				}
				else
				{
					temp_max = 1;
					now_max = candyshop[i][j];
					//�׷��� �ʴٸ�, �̹��� ���� ������ ������ �������� �ٽ� ���Ѵ�.
				}
			}
		}
		if (max_candy < temp_max)
		{
			max_candy = temp_max;
			temp_max = 1;
		}

	}

	//������ ��ġ�� �ٲٱ� ��, ������ �������� ������ ���� ��, �������� �ִ��� ���� �� �ִ� ������ ���Ѵ�. 
	//�ִ��� ���ϴ� ����� ���� �ּ��� ���� �����Ͽ� ����.
	for (int i = 0;i < N;i++)
	{
		temp_max = 0;
		now_max = candyshop[0][i];
		for (int j = 0;j < N;j++)
		{
			if (candyshop[j][i] == now_max)
			{
				temp_max++;
			}
			else if (candyshop[j][i] != now_max)
			{
				if (max_candy < temp_max)
				{
					now_max = candyshop[j][i];
					max_candy = temp_max;
					temp_max = 1;
				}
				else
				{
					now_max = candyshop[j][i];
					temp_max = 1;
				}
			}
		}
		if (max_candy < temp_max)
		{
			max_candy = temp_max;
			temp_max = 1;
		}
	}

	//�������� �������� �̿��� �� ���� ������ ��ġ�� ���� �ٲ�����, �ִ��� ���� �� �ִ� �ִ��� ���Ѵ�.
	//�̶�, ������ ��ġ�� �ٲٴ� ������ �������� �������� ����ǰ�, ������ ���� �� �ִ� �ִ��� ����, ���ι��� �� �� ���غ���.
	for (int i = 0; i < N;i++)
	{
		for (int j = 0;j < N - 1;j++)
		{
			char temp = candyshop[i][j];
			candyshop[i][j] = candyshop[i][j + 1];
			candyshop[i][j + 1] = temp;
			//���� �̿��ϴ� ������ ��ġ�� �ٲ��� ��, �ִ��� ���ϴ� ������ �����Ѵ�.
			now_max = candyshop[i][0];
			temp_max = 0;
			for (int k = 0;k < N;k++)
			{
				if (candyshop[i][k] == now_max)
				{
					temp_max++;
				}
				else if (candyshop[i][k] != now_max)
				{
					if (max_candy < temp_max)
					{
						now_max = candyshop[i][k];
						max_candy = temp_max;
						temp_max = 1;
					}
					else
					{
						now_max = candyshop[i][k];
						temp_max = 1;
					}
				}
			}
			if (max_candy < temp_max)
			{
				max_candy = temp_max;
			}
			now_max = candyshop[0][j];
			temp_max = 0;
			for (int k = 0;k < N;k++)
			{
				if (candyshop[k][j] == now_max)
				{
					temp_max++;
				}
				else if (candyshop[k][j] != now_max)
				{
					if (max_candy < temp_max)
					{
						now_max = candyshop[k][j];
						max_candy = temp_max;
						temp_max = 1;
					}
					else
					{
						now_max = candyshop[k][j];
						temp_max = 1;
					}
				}
			}
			if (max_candy < temp_max)
			{
				max_candy = temp_max;
			}
			now_max = candyshop[0][j+1];
			temp_max = 0;
			for (int k = 0;k < N;k++)
			{
				if (candyshop[k][j+1] == now_max)
				{
					temp_max++;
				}
				else if (candyshop[k][j+1] != now_max)
				{
					if (max_candy < temp_max)
					{
						now_max = candyshop[k][j+1];
						max_candy = temp_max;
						temp_max = 1;
					}
					else
					{
						now_max = candyshop[k][j+1];
						temp_max = 1;
					}
				}
			}
			if (max_candy < temp_max)
			{
				max_candy = temp_max;
			}
			temp = candyshop[i][j + 1];
			candyshop[i][j + 1] = candyshop[i][j];
			candyshop[i][j] = temp;
		}
	}

	//�̹����� ���� ���� �������� �̿��ϴ� �� ���� ������ ��ġ�� �ٲ㺻��.
	//����������, ������ ��ġ�� ���� ���� �������� �ٲٰ�, �������� ���� �� �ִ� �ִ��� ������ ������ ���, ���θ� �������� ���Ѵ�.
	for (int i = 0; i < N-1;i++)
	{
		for (int j = 0;j < N;j++)
		{
			char temp = candyshop[i][j];
			candyshop[i][j] = candyshop[i+1][j];
			candyshop[i+1][j] = temp;
			now_max = candyshop[i][0];
			temp_max = 0;
			for (int k = 0;k < N;k++)
			{
				if (candyshop[i][k] == now_max)
				{
					temp_max++;
				}
				else if (candyshop[i][k] != now_max)
				{
					if (max_candy < temp_max)
					{
						now_max = candyshop[i][k];
						max_candy = temp_max;
						temp_max = 1;
					}
					else
					{
						now_max = candyshop[i][k];
						temp_max = 1;
					}
				}
			}
			if (max_candy < temp_max)
			{
				max_candy = temp_max;
			}
			now_max = candyshop[i+1][0];
			temp_max = 0;
			for (int k = 0;k < N;k++)
			{
				if (candyshop[i+1][k] == now_max)
				{
					temp_max++;
				}
				else if (candyshop[i+1][k] != now_max)
				{
					if (max_candy < temp_max)
					{
						now_max = candyshop[i+1][k];
						max_candy = temp_max;
						temp_max = 1;
					}
					else
					{
						now_max = candyshop[i+1][k];
						temp_max = 1;
					}
				}
			}
			if (max_candy < temp_max)
			{
				max_candy = temp_max;
			}
			now_max = candyshop[0][j];
			temp_max = 0;
			for (int k = 0;k < N;k++)
			{
				if (candyshop[k][j] == now_max)
				{
					temp_max++;
				}
				else if (candyshop[k][j] != now_max)
				{
					if (max_candy < temp_max)
					{
						now_max = candyshop[k][j];
						max_candy = temp_max;
						temp_max = 1;
					}
					else
					{
						now_max = candyshop[k][j];
						temp_max = 1;
					}
				}
			}
			if (max_candy < temp_max)
			{
				max_candy = temp_max;
			}
			temp = candyshop[i + 1][j];
			candyshop[i + 1][j] = candyshop[i][j];
			candyshop[i][j] = temp;
		}
	}

	cout << max_candy << endl;
	return 0;
}