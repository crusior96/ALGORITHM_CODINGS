#include<iostream>
#include<algorithm>
#include<cstring>
#include<iomanip>
using namespace std;
int costs[3][1002] = {};		//costs[i][j] : j��° ������ i�� ĥ���� ��, ���ݱ��� ���� �ּ� ���
int paints[3][1002] = {};		//paints[i][j] : j��° ������ i�� ĥ���� �� ���̴� ���

//3���� ���ڵ��� ���ؼ� �ּڰ��� ���� �� �� �Լ�
//���� min�Լ� ���� ���� �Ⱦ �������
int get_min(int a, int b, int c)
{
	if (a <= b)
	{
		if (a <= c)
			return a;
		else
			return c;
	}
	else
	{
		if (b <= c)
			return b;
		else
			return c;
	}
}

//1000���� ������ ���� ĥ�Ѵٰ� ��������
//�̶�, n��° ������ ���� ĥ�� ��, n+1��° ������ n-1��° �������� ���� ���� ���̸� �ȵȴ�
//����, ������ ������ ���� ĥ�� �� �Ҹ�Ǵ� ����� �������̴�
//�� ���ǵ��� ��� ������ ä ���� ĥ���� ��쿡 ���̴� �ּ� ����� ���Ͽ���
//������ Ǯ���� RGB������ ���������, �� ��쿣 �յ� 1ĭ �Ÿ��ε� �̿��̱� ������ ������ �ɾ� �����ߴ�
//�� 3���� DP�� �����µ� ������ ���, �� ������ ������ ���� �������� ĥ���� ���� �� ����
//�� ù���� ������ ĥ�ϰ� �� ���� ����ϰ� DP ������ �� �� �ְ� �ȴ�


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	int answer = 1000005;
	cin >> N;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < 3;j++) {
			cin >> paints[j][i];
		}
	}



	//N�� 2 ������ ��쿣 �� 6���� �� ��츦 ã�Ƽ� �ּڰ��� ���Ѵ�
	if (N <= 2) {
		int temp1 = get_min(paints[0][0] + paints[1][1], paints[0][0] + paints[1][2], paints[0][1] + paints[1][0]);
		int temp2 = get_min(paints[0][1] + paints[1][2], paints[0][2] + paints[1][0], paints[0][2] + paints[1][1]);
		answer = min(temp1, temp2);
	}
	else {
		for (int k = 0;k < 3;k++) {
			int case_1;
			int case_2;
			int cost_test[3][1002] = {};

			//k���� ���� �̹��� �� ������ ������ ĥ�ϰ� �� ����, �� �������� ĥ�ϰ� �� ���� �ּ� ����� ���ϰ� �ȴ�
			if (k == 0) {
				cost_test[0][N - 2] = 1000005;
				cost_test[1][N - 2] = paints[1][N - 2] + paints[0][N - 1];
				cost_test[2][N - 2] = paints[2][N - 2] + paints[0][N - 1];
			}
			else if (k == 1) {
				cost_test[0][N - 2] = paints[0][N - 2] + paints[1][N - 1];
				cost_test[1][N - 2] = 1000005;
				cost_test[2][N - 2] = paints[2][N - 2] + paints[1][N - 1];
			}
			else if (k == 2) {
				cost_test[0][N - 2] = paints[0][N - 2] + paints[2][N - 1];
				cost_test[1][N - 2] = paints[1][N - 2] + paints[2][N - 1];
				cost_test[2][N - 2] = 1000005;
			}

			//���� N�� ���� ���� ������ �ϰ� ������ ���� 3 �ʰ��� ��쿣
			//�������� DP�� �����ϰ� �ȴ�
			//�� ����(i - 1 ����)�� cost_test���� j�� ĥ�Ѵٸ�, ���� ����(i)�� �ִ�
			//j�� �ƴ� �ٸ� ���� cost_test������ ���ؼ� paints[j][i-1]�� ���Ѵ�
			if (N > 3) {
				for (int i = N - 2;i > 1;i--)
				{
					for (int j = 0;j < 3;j++)
					{
						cost_test[j][i - 1] = paints[j][i - 1] + min(cost_test[(j + 1) % 3][i], cost_test[(j + 2) % 3][i]);
					}
				}
			}

			//���� k�� ���� ���� �� ù �������� ���ϰ� �Ǵ� ���� �������� �ȴ�
			//k�� 0�� ���, �� ù �������� paints[1][0], paints[2][0]�� ������ ����ؾ߸� �ϱ� ������
			//�� ��Ģ�� �°� �� ��° ������������ ���� �����ͼ� �����Ѵ�
			//���� �ּڰ��� answer�͵� ���Ͽ� answer�� �����Ѵ�
			if (k == 0) {
				case_1 = min(paints[1][0] + cost_test[0][1], paints[1][0] + cost_test[2][1]);
				case_2 = min(paints[2][0] + cost_test[0][1], paints[2][0] + cost_test[1][1]);
				answer = get_min(answer, case_1, case_2);
			}
			else if (k == 1) {
				case_1 = min(paints[0][0] + cost_test[1][1], paints[0][0] + cost_test[2][1]);
				case_2 = min(paints[2][0] + cost_test[0][1], paints[2][0] + cost_test[1][1]);
				answer = get_min(answer, case_1, case_2);
			}
			else if (k == 2) {
				case_1 = min(paints[1][0] + cost_test[0][1], paints[1][0] + cost_test[2][1]);
				case_2 = min(paints[0][0] + cost_test[1][1], paints[0][0] + cost_test[2][1]);
				answer = get_min(answer, case_1, case_2);
			}
		}
	}

	cout << answer << '\n';
	return 0;
}