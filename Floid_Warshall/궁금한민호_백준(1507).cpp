#include<iostream>
using namespace std;


int N;
int arr[21][21] = {};	//arr[i][j] : i���� j�� ���µ� �ɸ��� �ִܽð�
int floid[21][21] = {};	//floid[i][j] : i���� j�� ���µ� �ɸ��� �ִܽð��� arr[i][j]�� ���� �ִܽð������� ���� üũ�ϴ� ������ �迭

//N���� ���õ��� �ִٰ� ��������. ������ ���õ��� ���� �̾��� �ִ�.
//N*N�� ��ǥ�� ������ ���õ鰣 �ִ� �Ÿ��� ���س��ٰ� ��������. �ش� ������ ���ÿ� ���� ���ε��� �����ؼ� ���� �����̴�.
//�̶�, ���� �����ִ� ���õ� ������ ���ε��� �Ÿ� ���� ���� �� �ּڰ��� ���Ͽ���.

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
		}
	}

	int res = 0;
	int answer = 0;

	//�÷��̵� �ͼ��� ������ ������ ����Ǯ��
	//���� ���� i -> j�� �̵��ϴ� �Ÿ��� i -> k -> j�� ���� �ٸ� ���ø� ���İ��� �Ÿ����� ũ�ų� ���ٸ� �ִܰŸ��� �ƴ϶�� ���̸�
	//�࿩�� ũ�ٸ� ���� �� ���� ���̱� ������ answer�� -1�Է��ϰ�, ���ٸ� ���� ���ǿ� ���� �ʱ� ������ �ִܰŸ� ���η� ������� �ʴ´�
	for (int k = 0;k < N;k++) {
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				if (i == j || j == k || k == i) {
					continue;
				}
				else if (arr[i][j] > arr[j][k] + arr[k][i]) {
					floid[i][j] = -1;
					res = -1;
					break;
				}
				else if (arr[i][j] == arr[j][k] + arr[k][i]) {
					floid[i][j] = 1;
				}
			}
		}
	}

	if (res == -1) {
		cout << -1 << '\n';
	}
	else if (res != -1) {
		for (int i = 0;i < N;i++) {
			for (int j = 0;j < N;j++) {
				if (floid[i][j] == 0) {
					answer += arr[i][j];
				}
			}
		}
		//���� answer������ arr���� 2�� ��������Ƿ� 2�� ������� �Ѵ�
		cout << answer / 2 << '\n';
	}


	return 0;
}