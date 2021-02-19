#include<iostream>
#include<algorithm>
using namespace std;
int money[10002] = {};

//������ ��å�� �ʿ��� ������ N����ŭ �ִٰ� ��������
//�̶� ���� �����ϰ� �ִ� ������ target�̸� ��� ������ ������ �� ������쿣 Ư���� ���Ѿ׸�ŭ�� �����Ѵ�
//�� ��쿡 ���ҵ� �� �ִ� �ִ��� ���Ѿ��� ���ΰ� ���Ͽ���

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	long long target, answer;
	//mini�� maxi�� ���� ���ҵ� �� �ִ� �ּ� ~ �ִ� ���� ���Ѿ��� �ǹ��Ѵ�
	//����Ǯ�̽� �������� ��Ǯ�� ������ �ּ� ���� ���Ѿ��� 0�� �ƴ϶� �������� money�� �� �ּڰ����� ���߱� ����
	int mini = 0;
	int maxi = 0;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> money[i];
		if (money[i] > maxi) {
			maxi = money[i];
		}
	}
	cin >> target;

	//�̺�Ž���� �����Ͽ� �ִ���Ѿ��� ���Ѵ�
	//���⼭ sum�� ���Ѿ��� mid�� ������ �� ���̰� �Ǵ� �����
	while (mini <= maxi) {
		int mid = (mini + maxi) / 2;
		long long sum = 0;
		for (int i = 0;i < N;i++) {
			sum += min(money[i], mid);
		}

		//��ǥ ����Ⱥ��� �۰ų� ���� �ݾ��� ��� answer�� �ӽ������ϰ� mini���� ������Ų��
		//�׷��� �ʴٸ� maxi���� ������Ų��
		//���� ��� �̺�Ž���� �����ؼ� mini�� maxi���� ��Ұ��谡 �ٲ𶧱��� ����Ѵ�
		if (sum <= target) {
			answer = mid;
			mini = mid + 1;
		}
		else if (sum > target) {
			maxi = mid - 1;
		}
	}	

	cout << answer << '\n';
	return 0;
}