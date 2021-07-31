#include<iostream>
#include<vector>
using namespace std;
int M, N;
int arr[502][502] = {};
int checker[502][502] = {};
int answer = -1;
int temp = 0;
int block1[4][2] = {{0,0},{0,1},{1,0},{1,1}};									//�׸� 
int block2[2][4][2] = { {{0,0},{0,1},{0,2},{0,3}},{{0,0},{1,0},{2,0},{3,0}} };	//�丷���
int block3[8][4][2] = { {{0,0},{0,1},{1,1},{2,1}},{{0,2},{1,0},{1,1},{1,2}},{{0,0},{1,0},{2,0},{2,1}},{{0,0},{0,1},{0,2},{1,0}},{{0,0},{0,1},{1,0},{2,0}},{{0,0},{0,1},{0,2},{1,2}},{{0,1},{1,1},{2,0},{2,1}},{{0,0},{1,0},{1,1},{1,2}} };
int block4[4][4][2] = { {{0,0},{1,0},{1,1},{2,0}},{{0,0},{0,1},{0,2},{1,1}},{{0,1},{1,0},{1,1},{1,2}},{{0,1},{1,0},{1,1},{2,1}} };
int block5[4][4][2] = { {{0,0},{0,1},{1,1},{1,2}},{{0,1},{1,0},{1,1},{2,0}},{{0,1},{0,2},{1,0},{1,1}},{{0,0},{1,0},{1,1},{2,1}} };

//4���� ����� �̾��� �ִ� ������ ��Ʈ�ι̳��� �Ѵ�
//�̶�, N*M�� ũ�⸦ ���� ������ ���ڵ��� �ִٰ� ��������
//��Ʈ�ι̳� �ϳ��� ���� ���� �÷����� �� ���� �� �ִ� ���� ū ���ڵ��� ���� ���Ͽ���
//�̶� ��Ʈ�ι̳�� ȸ�� �� ��Ī�����⸦ �ص� �������

//block1~5 : �»�� ��ǥ�� �������� ����� ��ġ�� ����Ѵ�. ���� (a, b)��� �Ѵٸ� �»�� ��ǥ�κ��� a, b��ŭ �������ٴ� ���̴�
//calc1~5 : ����ص� ��ǥ�� �������� �ش� ��Ʈ�ι̳븦 ������ ��ġ���� ��, �� ��Ʈ�ι̳�� ���� �� �ִ� ������ ���� ���Ѵ�
//			�״���, �ش� ���� answer�� ���ؼ� �ִ밪�� ��� �����س�����

//������ DFS�� ����ص� �Ǳ� �ϴ�. ���� ����� ��Ʈ�ι̳븸 ���� �������ְ� ������ ��Ʈ�ι̳���� DFS �� ��Ʈ��ŷ�� ����ϸ� �ȴ�.
//������ �ð� ��ü�� ���غ��� �̸� ��ǥ���� ��������� �� ������ ����, ���Ʈ������ ����ϴ� ���� �� ���� ����� ���Դ�.

void calc1(int x, int y) {
	int tmp = 0;
	for (int i = 0;i < 4;i++) {
		int idx = x + block1[i][1];
		int idy = y + block1[i][0];
		if (idx<0 || idx > N || idy<0 || idy>M) {
			tmp = 0;
			break;
		}
		else {
			tmp += arr[idy][idx];
		}
	}

	if (answer < tmp) {
		answer = tmp;
	}
}

void calc2(int x, int y) {
	int tmp = 0;
	for (int i = 0;i < 2;i++) {
		tmp = 0;
		for (int j = 0;j < 4;j++) {
			int idx = x + block2[i][j][1];
			int idy = y + block2[i][j][0];
			if (idx<0 || idx > N || idy<0 || idy>M) {
				tmp = 0;
				break;
			}
			else {
				tmp += arr[idy][idx];
			}
		}

		if (answer < tmp) {
			answer = tmp;
		}
	}
}

void calc3(int x, int y) {
	int tmp = 0;
	for (int i = 0;i < 8;i++) {
		tmp = 0;
		for (int j = 0;j < 4;j++) {
			int idx = x + block3[i][j][1];
			int idy = y + block3[i][j][0];
			if (idx<0 || idx > N || idy<0 || idy>M) {
				tmp = 0;
				break;
			}
			else {
				tmp += arr[idy][idx];
			}
		}

		if (answer < tmp) {
			answer = tmp;
		}
	}
}

void calc4(int x, int y) {
	int tmp = 0;
	for (int i = 0;i < 4;i++) {
		tmp = 0;
		for (int j = 0;j < 4;j++) {
			int idx = x + block4[i][j][1];
			int idy = y + block4[i][j][0];
			if (idx<0 || idx > N || idy<0 || idy>M) {
				tmp = 0;
				break;
			}
			else {
				tmp += arr[idy][idx];
			}
		}

		if (answer < tmp) {
			answer = tmp;
		}
	}
}

void calc5(int x, int y) {
	int tmp = 0;
	for (int i = 0;i < 4;i++) {
		tmp = 0;
		for (int j = 0;j < 4;j++) {
			int idx = x + block5[i][j][1];
			int idy = y + block5[i][j][0];
			if (idx<0 || idx > N || idy<0 || idy>M) {
				tmp = 0;
				break;
			}
			else {
				tmp += arr[idy][idx];
			}
		}

		if (answer < tmp) {
			answer = tmp;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N;
	for (int i = 0;i < M;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
		}
	}
	

	for (int i = 0;i < M;i++) {
		for (int j = 0;j < N;j++) {
			calc1(j, i);
			calc2(j, i);
			calc3(j, i);
			calc4(j, i);
			calc5(j, i);
		}
	}


	cout << answer << '\n';
	return 0;
}