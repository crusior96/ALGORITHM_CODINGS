#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

int N;
int alphabets[27] = {};	//alphabets[i] : ������ �ڸ����� ������� ��, �ش� ���ĺ��� ǥ���� �� �ִ� �ڸ����� ���� ������ �����صд�

//N���� ���ڰ� �־����µ� ���� ���ĺ����� �̷���� ���ڿ��θ� �־����ٰ� ��������
//������ ���ĺ��� ������ ���ڸ� �־ ��� ���ڵ��� ���� �� �ִٸ�
//�̷��� �������� ����� �ִ� ���ڵ��� �ִ����� ���Ͽ���

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int answer = 0;

	for (int i = 0;i < N;i++) {
		string tmp;
		cin >> tmp;
		//���� ���ĺ� ���ڿ��� ��ġ�� ���� alphabets�� �������� ���� �޶�����
		//�̸� ���� alphabets[i]�� �� �� ��޵Ǵ��� �� �� �ְ�, ���� ������ �����ؼ� 9 ~ 0�� ���� �����ϸ� �ȴ�
		for (int j = tmp.length() - 1;j >= 0;j--) {
			alphabets[tmp[tmp.length() - 1 - j] - 'A'] += pow(10, j);
		}
	}

	sort(alphabets, alphabets + 27);

	//���� ���� ���� ���� ��޵� ���ĺ����� ���ڰ��� �ο��Ѵ�
	for (int i = 9;i >= 0;i--) {
		answer += alphabets[26 - (9 - i)] * i;
	}

	cout << answer << '\n';
	return 0;
}