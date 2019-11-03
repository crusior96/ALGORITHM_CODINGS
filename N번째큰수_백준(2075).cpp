#include<iostream>
#include<queue>
using namespace std;

//N*N���� ���ڰ� ������ �迭�� �ִ�. �̶�, ������ ���ڵ��� ���� �������� �Ʒ��� �ִ� ���� �ٷ����� �ຸ�� ���ڰ� ũ��
//���� ��Ģ�� ����ä�� ���ڵ��� �ִ� �迭�ӿ� N��° ū ���� ���Ͽ���. (N <= 1500)

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	priority_queue <int> PQ;
	//PQ���� �ִ� ���� ����ϰ��� �ԷµǴ� �����鿡 -1�� �����ش�.
	int N;
	cin >> N;
	for (int i = 0;i < N;i++)
	{
		int temp;
		cin >> temp;
		PQ.push(-temp);
	}
	//ù ��° ���� ���� �ϴ� PQ�� ����

	for (int i = 1;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			int temp;
			cin >> temp;
			PQ.push(-temp);
		}
		for (int j = 0;j < N;j++)
		{
			PQ.pop();
		}
		//�̾����� ����� ���� PQ�� ��������ش�.
		//���� N���� ���ڸ��� ���ܵ� ä ������ ������ �켱������ ���� POP���ش�.
		//���� �ּ� ������ �����Ǿ��ֱ� ������ ���밪�� ���� ��������� POP�Ǿ�����.
		//�Ŀ� ���� N���� ���� �� TOP�� �ִ� ������ -1�� ���Ͽ� ��½����ָ� N��° ū���� �ȴ�.
	}
	cout << PQ.top() * -1 << "\n";

	return 0;
}