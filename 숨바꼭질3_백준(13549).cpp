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
	ios::sync_with_stdio(false);
	cin.tie(0);
	int M, N; //M���� N���� �����ϴ¹���
	int visited[200001] = {}; //�������� �� �ش���ġ���� ���µ� �ɸ� �ּ� �̵�Ƚ��
	bool vis[200001] = {};	  //�ش� ��ġ�� �湮�ߴ°��� ���� ���� ����
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
			//��ǻ� �̹� �˰����� BFS�� ����ϱ�� �ϴµ� 0-1 BFS �˰����� ����Ѵٰ� �Ѵ�
			//BFSŽ���� ���ÿ� Ž���� �Ϸ�� ���� ���� ��ġ�� ���Ѵٴ� ��
			//�ٸ� �װ��� ������� �ʰ� deque �ڷᱸ�� ��� �� deque�� �ڷᰪ �ִ� ������ 
			//�ҿ�ð��� 0�� �����̵����� �ִ°����� ���ϰ� Ǯ�� ���� ������ �Ѵ�
			if ((temp * 2 <= 100000) && (visited[temp * 2] == 0) && (vis[temp * 2] == false))
			{
				visited[temp * 2] = visited[temp];
				vis[temp * 2] = true;
				checker.push_back(temp * 2);
			}

			if ((temp - 1 >= 0) && (visited[temp - 1] == 0) && (vis[temp - 1] == false))
			{
				visited[temp - 1] = visited[temp] + 1;
				vis[temp - 1] = true;
				checker.push_back(temp - 1);
			}

			if (visited[temp + 1] == 0 && (vis[temp + 1] == false))
			{
				visited[temp + 1] = visited[temp] + 1;
				vis[temp + 1] = true;
				checker.push_back(temp + 1);
			}
			checker.pop_front();
		}
	}
	cout << visited[N] << endl;
	return 0;
}