#include<iostream>
#include<stack>
#include<string>
using namespace std;

//����� �����ϴ� ����İ� ��ǻ�Ͱ� �����ϴ� ������� ����� �ٸ��� -> �̸� ����ǥ����̶� �Ѵ�
//�̶� ����� �����ϴ� ������� �ԷµǾ�����, ��ǻ�Ͱ� ������� �۵��ϴ� ������ ����϶�
//�����ڴ� (, ), +, -, /, *�̸� �ǿ����ڴ� A ~ Z�� ���ĺ����� �̷�����ִ�

int main() {
	stack<char> answer; //����ǥ����� ����ϱ� ���� ���� ������ ����

	string S;
	cin >> S;
	for (int i = 0;i < S.length();i++) {
		//���ÿ� ������ �� �ǿ����ڰ� push�Ǵ� ���ǵ�
		//1. �ǿ����ڴ� ������ push���ش�
		//2. ������ ������ ��������� ������ push���ش�
		//3. �������� �켱������ ���� answer�� top�� �ִ� �����ں��� ������� push���ش�
		//4. �������� �켱������ ���� answer�� top�� �ִ� �����ں��� ���ų� ������� ���� ���ó��� ��� ���� pop���ְ�, �Է��Ϸ��ߴ� �����ڸ� push���ش�
		//4-1. (�����ڴ� ������ push���ش�
		//4-2. )�������� ���, (�����ڰ� ���ö����� ���ó��� ��� ������ pop���ش�
		//4-3. ���� 4.��° ��Ģ������ ��� ���� pop�Ҷ� (�� ���ο� �ִٸ� �� �ձ����� pop���ش�
		if (S[i] >= 'A'&&S[i] <= 'Z') {
			cout << S[i];
		}
		else if (S[i] == '*' || S[i] == '/') {
			while (!answer.empty() && (answer.top() == '/' || answer.top() == '*')) {
				cout << answer.top();
				answer.pop();
			}
			answer.push(S[i]);
		}
		else if (S[i] == '+' || S[i] == '-') {
			while (!answer.empty() && answer.top() != '(') {
				cout << answer.top();
				answer.pop();
			}
			answer.push(S[i]);
		}
		else if (S[i] == '(') {
			answer.push(S[i]);
		}
		else if (S[i] == ')') {
			while (!answer.empty() && answer.top() != '(') {
				cout << answer.top();
				answer.pop();
			}
			answer.pop();
		}
		
	}

	//���� ���ó��� �����ִ� ������ �� �ǿ����ڰ� �ִٸ� ������ pop���ش�
	while (answer.empty() != true) {
		cout << answer.top();
		answer.pop();
	}

	return 0;
}