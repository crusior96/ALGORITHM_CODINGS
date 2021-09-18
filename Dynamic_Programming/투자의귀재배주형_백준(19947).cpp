#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

//���� ��ǰ�� �� 3���� �ִµ� ���� 1��, 3��, 5��¥�� ��ǰ�̴�
//������ ������ 5%, 20%, 35%�̸� ���ݵ��� �ٸ� ��ǰ���� ����Ż �� ������ �ߵ����� ������ ����
//�ʱ� �ں��� �Ⱓ�� �־����ٸ�, �ش�Ⱓ ���� ���� �� �ִ� �ִ� �ݾ��� ���Ͽ���

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int money, days;
	cin >> money >> days;
	int banks[12] = {};
	int answer;	
	banks[0] = money;
	if (days == 0) {
		answer = money;
	}
	else {
		//������ ���׿� �ô޷� Ǯ�� �� ���� DP����
		//�������� ���׿� ������ ������ DP������ ���� ���Ա⿡ �̷������� '������' Ǫ�� �� �߿��ϴ�

		//1��, 3��, 5���� ������ ������ ���� �������� ��츦 ���������� ���Ͽ�
		//���� ���������� �ݾ� ���¸� ��, �ִ��� �����ϴ� ������� �����Ѵ�
		for (int i = 1;i <= days;i++) {
			int tmp1 = banks[i - 1] * 1.05;
			banks[i] = tmp1;

			if (i >= 3) {
				int tmp2 = banks[i - 3] * 1.2;
				banks[i] = max(banks[i], tmp2);
			}

			if (i >= 5) {
				int tmp3 = banks[i - 5] * 1.35;
				banks[i] = max(banks[i], tmp3);
			}
		}
		answer = banks[days];
	}
	cout << answer << '\n';
	return 0;
}