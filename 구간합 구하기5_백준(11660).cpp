#include<iostream>
#pragma warning(disable: 4996)
using namespace std;
unsigned long long int arr[1026][1026] = {};	//�ڿ������� ����Ǿ��ִ� ��ǥ
unsigned long long int add_on[1026][1026] = {};	//(x,y)������ ��� ������ ��ǥ���� ���� add_on[x][y]�� �����صд�

//N*N�� �迭 �ȿ� ���� 1000���� �۰ų� ���� �ڿ������� ����Ǿ��ִ�
//�迭�� �� ���ʻ�� ��ǥ�� (1,1)�̶� �����Ͽ�����, Tc���� ���̽����� (x1,y1)���� (x2,y2)������ ��ǥ������ ������ ���Ͽ���
//�̶� Tc�� 100000 ������ �ڿ����̴�


int main() {
	int N, Tc;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d %d", &N, &Tc);

	//���� ��ġ�� ��ǥ�� add_on�� ������ ��, ���ʿ� �ִ� ��ǥ���� �ٷ� ���������� �����ִ� ������ ���ش�
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			scanf("%d", &arr[i][j]);
			add_on[i][j] += arr[i][j];
			add_on[i][j + 1] += add_on[i][j];
		}
	}

	//���ʿ� �ִ� ��ǥ���� �ٷ� �Ʒ������� �����ִ� ������ ���ش�
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			add_on[i + 1][j] += add_on[i][j];
		}
	}


	for (int i = 0;i < Tc;i++) {
		unsigned long long int answer = 0;
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		//(x2,y2)������ ���ڵ��� ��� ���� ��, (x1 - 1)(y2)�� (x2)(y1 - 1)������ ���ڵ��� ���� �� �ߺ��Ǿ� ������ �� (x1 - 1)(y1 - 1)������ ���ڵ��� �����ش�
		answer += add_on[x2][y2] - add_on[x1 - 1][y2] - add_on[x2][y1 - 1] + add_on[x1 - 1][y1 - 1];
		printf("%lld \n", answer);
	}
	return 0;
}