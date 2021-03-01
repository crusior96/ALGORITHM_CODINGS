#include<iostream>
#include<algorithm>
using namespace std;

int days[16];
int money[16];
int total[16];
int N;

//N���Ŀ� �����ϴ� ����� �ִٰ� ��������
//������ N�ϵ��ȿ��� �ش� days��ŭ�� �ð��� �ҿ��Ͽ� money��ŭ�� ���� �� �� �ִ�
//�̶� ���������� �� �� �ִ� ���� �ִ��� ���Ͽ���

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int budget = 0;
	cin >> N;
	for (int i = 1;i <= N;i++) {
		cin >> days[i] >> money[i];
	}

	for (int i = 1;i <= N;i++) {
		//����� �� �� ������ŭ �ٹ��ϼ��� �������
		if (i + days[i] <= N + 1) {
			//�ٹ��� �Ͽ� ���� ������ ���� ������� ����� total[i]�� ���̶� ���ؼ� �ִ� ����
			total[i + days[i]] = max(total[i] + money[i], total[i + days[i]]);
			budget = max(budget, total[i + days[i]]);
		}

		//�ٹ��� ���� �ʾ��� ���, �������� total[i + 1]�� �ٹ��� ���� �ʾƼ� �̾����� total[i]�� ���̶� ���ؼ� �ִ� ����
		total[i + 1] = max(total[i], total[i + 1]);
		budget = max(budget, total[i + 1]);
	}

	cout << budget << '\n';
	return 0;
}