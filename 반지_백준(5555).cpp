#include<iostream>
#include<string>
using namespace std;

//num���� �������� 10���� �빮�� ����� �̷���� ���ڿ��� �����Ѵ�.
//���ڿ��� ���� Ư���� ȯ������ �̷�����ְ�, �д� ������ ������ �� -> �������̴�.
//�̶�, ������ �ִ� ���ڿ� �� code�� ������ ������ ������ �� ��ΰ�?

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int answer = 0;
	string code;
	string rings[101] = {};
	int num;
	cin >> code;
	int code_len = code.length();
	cin >> num;

	for (int i = 0;i < num;i++) {
		cin >> rings[i];
		rings[i] = rings[i] + rings[i];
	}


	//string ��� ���� �ִ� find �Լ��� npos�� �˸� ���� ����(�𸣸� �¾ƾ����� ����)
	//string_A.find(string_B) : A ���ڿ��� B ���ڿ��� ������ B ���ڿ��� ���Ե� ���� A ���ڿ����� ��ġ�� ����Ѵ�. ������ npos�� ��µȴ�
	//�𸣸� modular ������ ���� ���� ���ڿ��� ����Ǿ��ִ� ���ڵ��� �迭�� ȯ�� �迭�� �ٲ� �����ؼ� ã�� ����� �ִ�

	for (int i = 0;i < num;i++) {
		if (rings[i].find(code) != string::npos) {
			answer++;
		}
	}
	cout << answer << endl;

	return 0;
}