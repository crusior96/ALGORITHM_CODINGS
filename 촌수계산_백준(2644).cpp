#include<iostream>
using namespace std;
int M, N, num1, num2, temp1, temp2;
int answer = 0;


//M���� ����� �ִ� ���, �� ������� 1 ~ M���̶�� ��Ī�Ѵٸ�
//�� ����鰣�� 1�̰��谡 N�� �ִٰ� ����������
//num1�� num2�� �̼����谡 �� �������� �˾ƺ����� �Ѵ�.


int chon[101][101] = {};
//�̼� ���谡 ����Ǿ����� �迭. ���� �̼� ���谡 �´ٸ� 1, �ƴϸ� 0�� �־�д�.

//���� num1, num2(�̼� ���踦 �˾ƺ����� �ϴ� �� ����� ��ȣ)
//cnt�� ���ݱ��� ����� �̼��� ��, before�� now��ġ�� �ִ� �����ȣ�� �ٸ� ����� �̾����־��� ��, �� ����� ��ȣ�̴�.
void chon_search(int end, int now, int before, int cnt)
{
	if (end == now)
	{
		//end�� now�� ���ٸ� ���� ����ϰ� BFS�� ����.
		answer = cnt;
		return;
	}
	else
	{
		//end�� now�� �ٸ��ٸ� BFS���� ��� ������.
		//�ڱ��ڽ�(���⿡�� chon_search�� now)�� �ٸ� ����� �̼������� ������ϰ� chon_search���� �����ش�.
		for (int i = 1;i <= M;i++)
		{
			
			if (chon[now][i] == 0)
			{
				continue;
			}

			if (i == before)
			{
				continue;
			}

			chon_search(end, i, now, cnt + 1);
		}
	}
}

int main()
{
	cin >> M;
	cin >> num1 >> num2;
	cin >> N;

	//temp1�� temp2���� �̼����踦 �����صд�.
	//�ٷ� �̾����� �̼������̹Ƿ� chon[temp1][temp2]�� [temp2][temp1]�� 1�� �����صд�.
	for (int i = 0;i < N;i++)
	{
		cin >> temp1 >> temp2;
		chon[temp1][temp2] = chon[temp2][temp1] = 1;
	}


	chon_search(num1, num2, 0, 0);
	
	//���� 0(�̾����� ���ϴ� �̼������̸�)�̸� -1�� ���
	//�ƴϸ� ���� ����ϸ� �ȴ�.
	if (answer == 0)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << answer << endl;
	}

	return 0;
}