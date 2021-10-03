#include<iostream>
#include<algorithm>
using namespace std;
int N, M;
int house[200001];

//N���� ���� �ִٰ� ��������
//������ ���� �����⸦ 1���� ��ġ�ؼ� �� M���� ��ġ�ؾ��ϴµ� 
//�����⸦ ��ġ�� ���� ���̸� �ִ��� �а��ؼ� ��ġ�ϰ� �ʹ�
//�̶�, ���� ���ǿ� �°� �����⸦ ��ġ�ϰ� �ȴٸ� �� �� ����� �ּ����� �Ÿ��� ���Ͽ���


//���� Ž���� ����Ǵ� �Լ�, ���� �� ������ �ּ��� �������� �ϴ� �Ÿ��� idx��� �����Ѵ�
//�� ���� ���� �켱������ �����⸦ ��ġ�� ��Ȳ�̱� ������ ������� ��ġ�� ������ ���� temp�� 1�� �����Ѵ�
//������ ��ġ�� ������ �������� idx �̻�ŭ ������ ���� ��ǥ�� ���´ٸ� �ش� �κп� �����⸦ ��ġ�Ѵ�
//�̷��� ������� temp���� M �̻��̸� true, �ƴϸ� false�� return�Ѵ�
bool binary_search(int idx) {
	int temp = 1;
	int prev = house[0];
	for (int i = 1;i < N;i++) {
		if (house[i] - prev >= idx) {
			prev = house[i];
			temp++;
		}
	}

	if (temp >= M) {
		return true;
	}
	
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		cin >> house[i];
	}

	//���� Ž���� ����ϱ� ���� ���� ��ǥ���� �����Ѵ�
	sort(house, house + N);

	//���� Ž���� ���� �����ϴ� �ʱ� ����. ���� �� ���̿� ��Ÿ�� �� �ִ� �ִ� & �ּ� �Ÿ��� �������ش�
	int mini = 1;
	int maxi = house[N - 1] - house[0];
	int answer = 0;

	//�̺�Ž���� ���� ������ �����ϴ� �κ�
	//�ִ��� ���� ������ ��Ű�� ���� answer���� max(answer, mid)�� �����ϸ� Ǯ�̸� �����Ѵ�
	while (mini <= maxi) {
		int mid = (mini + maxi) / 2;
		if (binary_search(mid)) {
			answer = max(answer, mid);
			mini = mid + 1;
		}
		else {
			maxi = mid - 1;
		}
	}
	cout << answer << '\n';
	return 0;
}