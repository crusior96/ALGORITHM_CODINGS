#include<iostream>
#include<string>
#include<stack>
using namespace std;

//A�� B�θ� �̷�����ִ� ���ڿ��� N�� �ִ�.
//A�� B�� ������ ����, ���� �ܾ�� ���� ���� �̷�� ���� �׾���� ���� �������� �ʾƾ� ���� �ܾ�� �� �� �ִ�
//�̶� ������ N���� �ܾ�� �� ���� �ܾ��� ������ ���϶�

int main() {
	int N;
	int goods = 0;
	stack<char>words; //���� �ܾ �׽�Ʈ�ϱ����� ���̴� stack
	cin >> N;
	for (int i = 0;i < N;i++) {
		string S;
		cin >> S;
		for (int j = 0;j < S.length();j++) {
			//stack�� ����ְų� stack�� top�� �ٸ� �ܾ��̸� stack�� push���ش�
			//stack�� top�� ���� �ܾ�� top�� pop���ش�
			if (words.empty() == true)
			{
				words.push(S[j]);
			}
			else if (words.top() != S[j]) {
				words.push(S[j]);
			}
			else if (words.top() == S[j]) {
				words.pop();
			}
		}

		//�� ��Ģ��� stack�� ������ ��������� �����ܾ��̴�
		if (words.empty() == true) {
			goods++;
		}
		else {
			//��Ģ�� �������� ���Ͽ� stack���ο� �ܾ �����ִٸ� stack���θ� ������ ���� �ֵ��� pop���ش�
			while (words.empty() != true) {
				words.pop();
			}
		}
	}

	cout << goods << endl;

	return 0;
}