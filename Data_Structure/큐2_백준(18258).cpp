#include<iostream>
#include<queue>
#include<string>
using namespace std;

//�׳� �⺻���� ť�� ��ɵ鿡 ���� ���� �� ��κ������� ����°� �ð����⵵�� �߽��� �ִ� ����
//N���� ��ɾ �Է��ϰ� �Ǵµ� N�� ������ 1 �̻� 2000000 �����̴�
//���� ���δ�� queue sql ���� �ִ� �Լ��� ����ϸ� �ð� �ʰ��� �Ͼ�� �Ǵ� ȿ�������� ����� ��������

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	string S;
	cin >> N;	
	queue<int> q;

	//ť�� �ִ� ��ɵ� �� �ð� �ҿ並 O(N)�� �ƴ� O(1)�� ���̱� ���� ť�� ����� ���� ������ �������ش�
	//�ش� ������ ���� pop, front, back, empty���� ���� ť ���ο� ���� �ִ��� üũ�ϴ� queue.empty() �Լ��� ��� ���ص� �ȴ�
	//���� size���� queue.size() �Լ��� ��� ���ص� �ȴ�
	//�� 1������ �� ������ �� Ǭ ������ ������ �����ؼ� �ҿ� �ð� ����, ���ڿ� �Է� �ð� ������ ���ؼ���� �����Ѵ�
	int siz = 0;
	for (int i = 0;i < N;i++)
	{
		cin >> S;
		if (S == "push")
		{
			int temp;
			cin >> temp;
			q.push(temp);
			siz++;
		}
		else if (S == "front")
		{
			if (siz == 0)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << q.front() << '\n';
			}
		}
		else if (S == "back")
		{
			if (siz == 0)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << q.back() << '\n';
			}
		}
		else if (S == "pop")
		{
			if (siz == 0)
			{
				cout << -1 << '\n';
			}
			else
			{
				cout << q.front() << '\n';
				q.pop();
				siz--;
			}
		}
		else if (S == "size")
		{
			cout << siz << '\n';
		}
		else if (S == "empty")
		{
			if (siz == 0)
			{
				cout << 1 << '\n';
			}
			else
			{
				cout << 0 << '\n';
			}
		}
	}
	return 0;
}