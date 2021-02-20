#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, answer;
int discuss[52] = {};

void max_disc(int num, int total) {
	if (num > N - 1) {
		answer = max(total, answer);
		return;
	}

	//�����س� DP
	//1. �̹� ȸ�Ǹ� �ǳʶٰ� ���� �� ȸ�Ƿ� �Ѿ��
	//2. �̹� ȸ�Ǹ� �����ϰ� 2�� �ڿ� �ִ� ȸ�Ƿ� �Ѿ��
	max_disc(num + 1, total);
	max_disc(num + 2, total + discuss[num]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;

	for (int i = 0;i < N;i++) {
		//������ ���ӵ� ȸ�Ǹ� �� �� ���� ��Ȳ�̰� ������ ������������ �־������Ƿ�
		//ȸ�ǿ� �����ϴ� ��� ���� �����صδ� ������ �Ѵ�
		cin >> discuss[i] >> discuss[i] >> discuss[i];
	}

	max_disc(0, 0);

	cout << answer << '\n';
	return 0;
}