#include<iostream>
#include<string>
using namespace std;

//N���� �׽�Ʈ���̽����� brace ������ ��ȣ�� ����� (�� )�� ����Ͽ� �Էµȴ�.
//��ȣ�� ����� () ���ó�� �Ǿ��ִ°��� x�� ����. �̸� ������ ��ȣ�� Ī�Ѵ�.
//�̷� ����� ��ȣ�� �ٸ� ������ �� ������, ���� �ٿ����� ��쿡�� ������ ��ȣ�� �� �� �ִ�.
//�Է¹��� brace������ ������ ��ȣ���� �ƴ��� �Ǵ�����.

int main()
{
	int N;
	int balancer = 0;
	string brace;
	cin >> N;
	//brace���ڿ��� �ִ� ��ȣ���� ��翡 ���� balancer������ ���� ��ȭ��Ų��.
	//'('�� ��쿡�� balancer++ , ')'�� ��쿡�� balancer--�� �ȴ�.
	//�߰��� balancer ���� ������ �Ǿ�����ų� ���ڿ� ������ ������ 0�� �ƴѰ�쿣 'NO'
	//���ڿ� ������ ���� ����غ������� 0�� ������ 'YES'�� ����Ѵ�.
	for (int i = 0;i < N;i++)
	{
		cin >> brace;
		for (int j = 0;j < brace.length();j++)
		{
			if (balancer < 0)
				break;


			if (brace[j] == '(')
				balancer++;
			else if (brace[j] == ')')
				balancer--;
		}

		if (balancer == 0)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}

		balancer = 0;		
	}

	return 0;
}