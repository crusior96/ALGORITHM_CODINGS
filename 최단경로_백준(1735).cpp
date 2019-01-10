#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//������ V���� �ְ�, �� ���̸� �����ϴ� ���⼺�� �ִ� ������ E���� �ִ�.
//�̶�, ������ start���� ������ ������ ������ �ٸ� �������� ���� ����� �� �ִܰŸ��� ��� ����ϴ� ����.
//V�� 2�� ������ �ڿ����̸� E�� 30�� ������ �ڿ����̴�.
int start, V, E;


typedef struct NODE {
	int end;
	int val;
};

vector<NODE> way_length[300001]; //���� ��� ������ ������ �����ϴ� ����
int dist[20001] = { 0 };		 //���������� �ٸ� �������� �Ÿ����� �����ϴ� �迭

void daik() //�̹� �������� ����ϴ� ���ͽ�Ʈ�� �˰���. �켱���� ť�� �Բ� ����Ѵ�.
{
	priority_queue<pair<int, int>> pq; 
	pq.push({ 0,start });
	

	while (!pq.empty())
	{
		
		
		int now_NODE = pq.top().second;

		int cost = -1 * pq.top().first;
		pq.pop();

		//��θ� Ž���ϴ� ������ ��忡�� �ٸ� ���� ���ϴ� �������� ��� Ž���Ѵ�.
		for (int i = 0;i < way_length[now_NODE].size();i++)
		{
			int new_val = dist[now_NODE] + way_length[now_NODE][i].val;
			int before_val = dist[way_length[now_NODE][i].end];

			//���ݱ��� �߷��� ���� ���� �ִܰŸ��� ��� ���� �Ÿ��� ���Ͽ� �ִܰŸ��� ���ŵǴ°��
			//�켱���� ť�� ���� ������ ����� ���������� ��忡���� �Ÿ� �񱳸� ���� �պκп� ������ �����صд�.
			if (new_val < before_val) {
				dist[way_length[now_NODE][i].end] = new_val;
				pq.push({ -1 * new_val,way_length[now_NODE][i].end });
			}
		}
	}
}

int main()
{
	cin >> V >> E >> start;
	int S, T, value; //S�� ����ϴ� ����ȣ, T�� �����ϴ� ����ȣ, value�� ��� -> ���� �� ���̿� ���� ������ ����ġ���̴�.
	for (int i = 0;i < E;i++)
	{
		scanf("%d %d %d", &S, &T, &value);
		//������ ��߳�忡�� ������ �� �ִ� ����ȣ �� �� ���� ���� ����ġ�� way_length ���Ϳ� �����صд�.
		way_length[S].push_back(NODE{ T,value });
	}

	for (int i = 1;i <= V;i++)
	{
		dist[i] = 1000000000;
	}
	//�Ÿ��� ���ϴ� ������ �Ǵ� ������ 0���� �ʱ�ȭ�ϰ�, �� ���� �κ��� �ִ����� �������ش�.
	//�ִ����� �����Ǿ��ִ� �κ��� �װ����� ���� �Ÿ��� ���� �� ������ "INF"��� ���ڿ��� ����ϰ� �ȴ�.
	dist[start] = 0;

	daik();

	for (int i = 1;i <= V;i++)
	{
		if (dist[i] != 1000000000)
		{
			printf("%d\n", dist[i]);
		}
		else
		{
			printf("INF\n");
		}
	}

	return 0;
}

//���ͽ�Ʈ�� �˰����� ������ ���� ���ش� �Ǿ����� ���� ���� �ǽ��� �ʿ��غ��δ�.