#include<iostream>
#include<string>
using namespace std;

//���ڿ� S�� �Է¹޾�����, �� ���ڿ��� �Ӹ�������� ���� �� �ִٸ� �Ӹ�������� ������ ����.
//���� ���ڸ� ���Ƿ� �Űܼ� �Ӹ�������� ���� �� �ִٸ� ������������ ���� �տ� ���°��� ����Ѵ�.

int main()
{
	int alphabet[26] = {};//'A'���� 'Z'������ ���� ���ĺ����� ������ �����صд�.
	int checked[26] = {};//'A'���� 'Z'������ ���ĺ��� �� ���ڿ� ���ο� �ִ� ���ĺ��� checked�迭�� 1�� �����صд�.
	char alpha[26] = {}; //'A'���� 'Z'������ ���ڰ� ����Ǵ� �迭
	string S;
	int odd = 0;//Ȧ���� ���ĺ��� ������ ����� �����ϴ� ����
	int isodd, status;
	cin >> S;

	for (int i = 0;i < 26;i++)
	{
		alpha[i] = 'A' + i;
	}

	//���ڿ� ��ü ���̿��� ���ĺ��� ���� �� ������ ���翩�θ� �����صд�.
	for (int i = 0;i < S.length();i++)
	{
		alphabet[S[i] - 'A']++;
		checked[S[i] - 'A'] = 1;
	}

	isodd = S.length() % 2; //���ڿ��� ���̰� Ȧ�������� ���θ� ������ ����
	//��� ���ĺ� �������� ������ ���� ��Ȳ�ο�
	for (int i = 0;i < 26;i++)
	{
		//�� ���ĺ��� ������ �� 1�����
		if (alphabet[i] % 2 == 1 && alphabet[i]==1)
		{
			odd++;
			checked[i] = 3;
			status = 2;
		}
		//�� ���ĺ��� ������ Ȧ�������
		else if (alphabet[i] % 2 == 1 && alphabet[i] > 1)
		{
			odd++;
			checked[i] = 2;
			status = 3;
		}

		//Ȧ������ ���ĺ��� ������ 2�� �̻��ϰ��, �Ӹ������ ���� �� ������ �� ������ ������ �ǹ̾���.
		if (odd >= 2)
		{
			break;
		}
	}

	//�Ӹ���ұ����� ��������� �������� �¿쿡 ������ Ƚ����ŭ ���ĺ��� �����⶧����
	//���ĺ� ������ ���ݸ�ŭ ���ʿ��� �������� ������ �ȴ�.
	for (int i = 0;i < 26;i++)
	{
		if (alphabet[i] > 1)
		{
			alphabet[i] = alphabet[i] / 2;
		}
	}

	if (odd >= 2)
	{
		cout << "I'm Sorry Hansoo";
	}
	else if (odd == 1 && isodd == 1) //���� ���� Ȧ�� ���� ���ĺ��� �������� �ְ�, ���� ���̰� Ȧ���ΰ��
	{
		//�� �� ������ ���ĺ��� 1���� �ԷµǾ��������
		if (status == 2)
		{
			for (int j = 0;j < 26;j++)
			{
				for (int k = 0;k < alphabet[j];k++)
				{
					if (checked[j] == 1)
					{
						cout << alpha[j];
					}
				}
			}

			for (int j = 0;j < 26;j++)
			{
				if (checked[j] == 3)
				{
					cout << alpha[j];
					break;
				}
			}

			for (int j = 25;j >= 0;j--)
			{
				for (int k = 0;k < alphabet[j];k++)
				{
					if (checked[j] == 1)
					{
						cout << alpha[j];
					}
				}
			}
		}
		//�� �������� ���ĺ��� 3�� �̻��� Ȧ������ �̷���� �ִ� ���
		else if (status == 3)
		{
			for (int j = 0;j < 26;j++)
			{
				for (int k = 0;k < alphabet[j];k++)
				{
					if (checked[j] == 1 || checked[j] == 2)
					{
						cout << alpha[j];
					}
				}
			}

			for (int j = 0;j < 26;j++)
			{
				if (checked[j] == 2)
				{
					cout << alpha[j];
					break;
				}
			}

			for (int j = 25;j >= 0;j--)
			{
				for (int k = 0;k < alphabet[j];k++)
				{
					if (checked[j] == 1 || checked[j] == 2)
					{
						cout << alpha[j];
					}
				}
			}
		}
	}
	//���ڳ��� ���ĺ����� ��ε� ¦������ŭ �ְ� ������ ���� ���� ¦�����ΰ��
	else if (odd == 0 && isodd == 0)
	{
		for (int j = 0;j < 26;j++)
		{
			for (int k = 0;k < alphabet[j];k++)
			{
				if (checked[j] == 1)
				{
					cout << alpha[j];
				}
			}
		}
		
		for (int j = 25;j >=0; j--)
		{
			for (int k = 0;k < alphabet[j];k++)
			{
				if (checked[j] == 1)
				{
					cout << alpha[j];
				}
			}
		}
	}
	else //�� ���� ����쿡�� �Ӹ������ ������ �ȵȴ�.
	{
		cout << "I'm Sorry Hansoo";
	}

	return 0;
}