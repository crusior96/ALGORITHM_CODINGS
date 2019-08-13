#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

//M�� ��ġ�� ����� N�� �ִ� ����� �������� 3 ���� ������� �̵��Ͽ� �����Ϸ��Ѵ�.
//������ ����� M���� M+1 Ȥ�� M-1�� �ɾ�ų�, M*2�� ��ġ�� �����̵��ϴ� ���̴�.
//�ɾ�� �������� 1�ʰ� �Ҹ�ǰ� �����̵��� �ϴ°������� �ð��Ҹ� ������
//M���� N���� �����ϴ� �ִܼҸ�ð��� ���Ͽ���


int main()
{
	int M, N; //M���� N���� �����ϴ¹���
	int visited[100001] = {}; //��ġ i�� ���ʸ��� �ִܽð����� �����ߴ��� �������ִ¹迭
	deque <int> checker; 
	//BFS����� �̿��Ͽ� ������ Ǯ�����Ѵ�. �־�����ġ���� pop_front()���ְ�,
	//�� ��ġ���� +1 / -1 / *2�� ��ġ�� �̵��Ѱ��� checker�� push_back���ش�.
	cin >> M >> N;
	checker.push_back(M);
	while (checker.empty() != 1)
	{
		int temp = checker.front();
		//������ġ�� ��ǥ���� ���ٸ�
		if (temp == N)
		{
			while (checker.empty() != 1)
			{
				//checker �� ���ǰ��� ��� ����ش�.
				checker.pop_front();
			}
			break;
		}
		else
		{
			//���� ��ġ�� ��ǥ������ �ڿ� �ִٸ�
			if (temp > N)
			{
				//��ǥ������ �������ؼ� ������ġ���� -1�ϴ� �ൿ�ۿ� ���Ѵ�.
				if (visited[temp - 1] == 0)//�湮�� ���� ���� ��ġ���
				{
					visited[temp - 1] = visited[temp] + 1;
					checker.push_back(temp - 1);
					//���� �����ð��� visited�迭�� �������ְ�, �� ��ġ�� checker�� push_back
				}
				else if (visited[temp - 1] > visited[temp] + 1)//�湮�� ���� �ִ� ��ġ������ �̵��ϴµ� �ɸ� �ð��� �ִ����� ����ȴٸ�
				{
					visited[temp - 1] = visited[temp] + 1;
					checker.push_back(temp - 1);
					//�ִ� �����ð��� visited�迭�� �������ְ�, �� ��ġ�� checker�� push_back
				}
			}
			//���� ��ġ�� ��ǥ������ �տ� �ִٸ�
			else if (temp < N)
			{
				//if���� �����ִ� ������ *2�϶��� ����, �� ���� +1�� -1�� �ڿ� �˾Ƽ� ���� �ȴ�.
				//*2�϶� 0�ʰ� �ɸ��ٴ������� BFS�� �������ִ� ����ġ�� �����Ǿ��ִ°����� �����ȴ�.
				//������ 2���� if������ �̷���� 3���� if ~ else if���� ���Ͱ��� ��Ģ�� ���� ������ �۵��Ѵ�.
				if ((temp * 2 <= 100000) && (visited[temp * 2] == 0))
				{
					visited[temp * 2] = visited[temp];
					checker.push_back(temp * 2);
				}
				else if ((temp * 2 <= 100000) && (visited[temp * 2] > visited[temp] + 1))
				{
					visited[temp * 2] = visited[temp];
					checker.push_back(temp * 2);
				}

				if (visited[temp + 1] == 0)
				{
					visited[temp + 1] = visited[temp] + 1;
					checker.push_back(temp + 1);
				}
				else if (visited[temp + 1] > visited[temp] + 1)
				{
					visited[temp + 1] = visited[temp] + 1;
					checker.push_back(temp + 1);
				}

				if ((temp - 1 != -1) && (visited[temp - 1] == 0))
				{
					visited[temp - 1] = visited[temp] + 1;
					checker.push_back(temp - 1);
				}
				else if ((temp - 1 != -1) && (visited[temp - 1] > visited[temp] + 1))
				{
					visited[temp - 1] = visited[temp] + 1;
					checker.push_back(temp - 1);
				}
			}
		}
		checker.pop_front();
		//��ġŽ���� ����߾��� checker.front()�� �� ����.
	}
	cout << visited[N] << endl;
	return 0;
}