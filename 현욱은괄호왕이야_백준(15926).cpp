#include<iostream>
#include<stack>
#include<string>
using namespace std;

//���̰� 1 ~ 200000�� �Ұ�ȣ�θ� �̷���� ���ڿ��� �ִ�
//��ȣ�� ()�Ͱ��� ��Ģ�� �̷�����߸� ������ ��ȣ�̸�, ��Ģ�� ���� ��ȣ�鳢�� �̾����ְų� ���� ���ԵǾ��ִٸ� �װ��� �ϳ��� ������ ��ȣ�� �� �� �ִ�
//�̶� ���ڿ� ������ ���� �� �ִ� ������ ������ ��ȣ���̸� ���Ͽ���

int main()
{
	int N;
	int answer = 0;
	string brace;		//�Է¹��� �Ұ�ȣ���ڿ�
	stack<int> bracer;	//������̸� �˾Ƴ������� ���� ����
	cin >> N;
	cin >> brace;
	bracer.push(-1);
	for (int j = 0;j < brace.length();j++)
	{
		if (brace[j] == '(')
		{
			bracer.push(j);	//���ÿ� ������ġ �Է�
		}
		else if (brace[j] == ')')
		{
			bracer.pop();
			if (bracer.empty() != true) {
				answer = answer > j - bracer.top() ? answer : j - bracer.top();
				//������ ������� �ʴٸ�, ��ȿ�� ��ȣ���ڿ����� �ǹ��Ѵ�
				//������� �˾Ƴ� answer�� ������ġ���� ������ top()���� �� ���� ���Ͽ� �� ū ���� answer�� �����Ѵ�
			}
			else {
				bracer.push(j);	//������ ����ִٸ�, ���� ��ġ�� �Է����ش�
			}
		}
	}



	cout << answer << endl;

	return 0;
}