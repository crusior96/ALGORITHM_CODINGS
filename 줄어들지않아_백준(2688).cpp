#include<iostream>
using namespace std;
long long int DP[66][10] = {};			//DP[i][j]�� �ǹ� : i��° �ڸ��� j�� ���� �� �ִ� ����� ��
long long int answer[101] = {};			//�ڸ������� ��Ģ�� �´� ������ �������� ����ȴ�

//temp�ڸ��� ������ �ִٰ� ��������. �� ������ 0���� �����ص� �ȴ�
//���ʿ������� ������ �ڸ��� �� ��, ���ʿ� �ִ� �ڸ������� �����ʿ� �ִ� �ڸ����� ũ�ų� ���ƾ��Ѵ�
//�̶�, temp�ڸ��� ������ ���� ������ ������ �� �ִ� ������ ������ �� ��ΰ�?

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;

	for (int i = 0;i < 10;i++) {
		DP[1][i] = 1;
	}

	answer[1] = 10;
	
	//DFS ������ �����Ͽ� DP�� ���� ä��� answer�� �� ���� ä��������
	//��ȭ���� ���, DP[i][j](i��° �ڸ��� j�� �� ����� ��) = DP[i - 1][j] + sum(i-1��° �ڸ��� j�� �� ����� �� + DP[i-1][j-1]�� ��)
	//sum�� DP[i][j] �ٷ� �� �����ڸ��� ���Ե� ���� ���� ��Ģ�� �����ϴ� ����� ���� �ǹ��Ѵ�
	//�׷��� ä���� DP������ DP[i]���� �ִ� ��� ������ answer[i]�� �ջ��صд�
	for (int i = 2;i < 65;i++) {
		long long int sum = 0;
		for (int j = 0;j < 10;j++) {
			DP[i][j] = DP[i - 1][j] + sum;
			sum += DP[i - 1][j];
		}

		for (int j = 0;j < 10;j++) {
			answer[i] += DP[i][j];
		}
	}


	for (int i = 0;i < N;i++) {
		int temp;
		cin >> temp;
		cout << answer[temp] << '\n';
	}
	return 0;
}