#include<iostream>
#include<algorithm>
using namespace std;
int len[102][102] = {};

//city���� ���ð� �ְ� bus���� ���ð� �̵���ΰ� �ִ�
//�̶�, �� ���ÿ��� ����ؼ� ������ ���÷� �����Ϸ� �� ��, �� ���� �ִ� �̵������ ���Ͽ���
//�̵���δ� s, e, cost�� ǥ���ϸ� s���� ����Ͽ� e�� �����ϰ� cost��ŭ�� �̵������ �߻��Ѵ�
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int city, bus;
	cin >> city;
	cin >> bus;
	//�ʱ�ȭ�۾�
	//���������� �����ϴ� ���� 0, ������ �� ���� ����� ��쿣 Ư������ ����ȴ�
	for (int i = 1;i <= city;i++) {
		for (int j = 1;j <= city;j++) {
			if (i == j) {
				len[i][j] = 0;
			}
			else {
				len[i][j] = 1000000000;
			}
		}
	}

	//�̵���� ���� �� �ּ� �̵���� ���ʰ���
	//��, ������ �ش� �̵���θ� 1���� ������� ���
	for (int i = 0;i < bus;i++) {
		int s, e, cost;
		cin >> s >> e >> cost;
		len[s][e] = min(len[s][e], cost);
	}

	//3�� for���� ����Ͽ� �÷��̵� �ͼ� �˰����� �����Ѵ�
	//�ش� ���÷� ���� ���� ����� �ش� ���ø� ���ϴ� �濡 ������ �� �ִ�
	//�ٸ� ���ø� �̿��� ��Ʈ�� ���Ͽ� �ּ� ����� �����Ѵ�
	for (int k = 1;k <= city;k++) {
		for (int i = 1;i <= city;i++) {
			for (int j = 1;j <= city;j++) {
				len[i][j] = min(len[i][j], len[i][k] + len[k][j]);
			}
		}
	}

	//����� �� �ش� �迭�� Ư������ ����������� 0��, �ƴϸ� �迭���� ����Ѵ�
	for (int i = 1;i <= city;i++) {
		for (int j = 1;j <= city;j++) {
			if (len[i][j] == 1000000000) {
				cout << 0 << " ";
			}
			else {
				cout << len[i][j] << " ";
			}
		}
		cout << '\n';
	}

	return 0;
}