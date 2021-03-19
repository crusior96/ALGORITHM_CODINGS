#include<iostream>
#include<string>
using namespace std;
int arr[5][9];

//4���� ��Ϲ����� �ִٰ� ��������
//������ ��Ϲ����� 8���� ��Ϸ� �̷����������, ������ ��Ͽ��� N������ S�������� ���� ������ ����ִ�
//������ ��ϵ��� ���� ���(9�ù���)�� ������ ���(3�ù���)�� ���� ��Բ� ��ġ���ִ�
//�� ��Ϲ������� K���� ȸ�� �Է��� �ο��޴µ�, ȸ�� �Է��� ȸ�� ����� ȸ���� ���� �� ��Ϲ����� �̷�����ִ�
//� ��Ϲ����� ȸ���� ��, �ش� ��Ϲ����� ���� �κ��� �ٸ� ��Ϲ����� ��ϰ� ���� �ٸ� ���̸�
//�� ��Ϲ����� ȸ���ϴ� ��Ϲ������� �ٸ� �������� ȸ���ϰ� �ȴ�
//K���� ȸ�� �Է��� ���� ������ ��Ϲ��� ���¸� ����϶�


//��� ���� ��ȣ�� ȸ�������� �־����� �� ��� ������� ���õ� �Լ�
//��Ϲ��� ȸ�� üũ�� �ʿ��Ѱ� a[i][2]�� a[i][6]���� �������
void turnit(int num, int turn_w) {
	int turn_1 = 0;
	int turn_2 = 0;
	int turn_3 = 0;
	int turn_4 = 0;		//���� 1 ~ 4�� ����� ȸ�������� �Ͻ��Ѵ�

	//num���� ���� ��Ϲ����� ȭ������ �� ȸ������ üũ ������ �޶�����
	//num�� 1�̸� �׿� ����� 2, 3, 4�� ������� üũ�ǰ�
	//2�̸� �׿� ����� 4�� ���� üũ�ϰ� 3�� 2 ������� üũ�ϰ� �ȴ�
	//��, �����ϴ� ��Ϲ������� ȸ�����¸� ���� üũ�Ѵٴ� ��
	//�̶�, ȸ�������� üũ���� ���� �κ��� �׿� ����� ��Ϲ����� ȸ�������� üũ �� �ʿ䰡 ���ٴ� ���� �˾Ƶ���
	if (num == 1) {
		turn_1 = turn_w;
		if (arr[1][2] != arr[2][6]) {
			if (turn_1 == -1) {
				turn_2 = 1;
			}
			else if (turn_1 == 1) {
				turn_2 = -1;
			}
		}

		if (turn_2 != 0) {
			if (arr[2][2] != arr[3][6]) {
				if (turn_2 == -1) {
					turn_3 = 1;
				}
				else if (turn_2 == 1) {
					turn_3 = -1;
				}
			}
		}

		if (turn_3 != 0) {
			if (arr[3][2] != arr[4][6]) {
				if (turn_3 == -1) {
					turn_4 = 1;
				}
				else if (turn_3 == 1) {
					turn_4 = -1;
				}
			}
		}
	}
	else if (num == 2) {
		turn_2 = turn_w;
		if (arr[1][2] != arr[2][6]) {
			if (turn_2 == -1) {
				turn_1 = 1;
			}
			else if (turn_2 == 1) {
				turn_1 = -1;
			}
		}

		if (arr[2][2] != arr[3][6]) {
			if (turn_2 == -1) {
				turn_3 = 1;
			}
			else if (turn_2 == 1) {
				turn_3 = -1;
			}
		}

		if (turn_3 != 0) {
			if (arr[3][2] != arr[4][6]) {
				if (turn_3 == -1) {
					turn_4 = 1;
				}
				else if (turn_3 == 1) {
					turn_4 = -1;
				}
			}
		}
	}
	else if (num == 3) {
		turn_3 = turn_w;
		if (arr[3][2] != arr[4][6]) {
			if (turn_3 == -1) {
				turn_4 = 1;
			}
			else if (turn_3 == 1) {
				turn_4 = -1;
			}
		}

		if (arr[3][6] != arr[2][2]) {
			if (turn_3 == -1) {
				turn_2 = 1;
			}
			else if (turn_3 == 1) {
				turn_2 = -1;
			}
		}

		if (turn_2 != 0) {
			if (arr[2][6] != arr[1][2]) {
				if (turn_2 == -1) {
					turn_1 = 1;
				}
				else if (turn_2 == 1) {
					turn_1 = -1;
				}
			}
		}
	}
	else if (num == 4) {
		turn_4 = turn_w;
		if (arr[4][6] != arr[3][2]) {
			if (turn_4 == -1) {
				turn_3 = 1;
			}
			else if (turn_4 == 1) {
				turn_3 = -1;
			}
		}

		if (turn_3 != 0) {
			if (arr[3][6] != arr[2][2]) {
				if (turn_3 == -1) {
					turn_2 = 1;
				}
				else if (turn_3 == 1) {
					turn_2 = -1;
				}
			}
		}

		if (turn_2 != 0) {
			if (arr[2][6] != arr[1][2]) {
				if (turn_2 == -1) {
					turn_1 = 1;
				}
				else if (turn_2 == 1) {
					turn_1 = -1;
				}
			}
		}
	}

	//1 ~ 4�� ��Ϲ������� ȸ�� ���� ���ڰ� �� �Էµ� ����
	//�Է¹��� ȸ�� ���ڰ� 1�̸� �ð��������, -1�̸� �ð� �ݴ�������� ���ư��� �Ѵ�
	if (turn_1 == 1) {
		int tmp[8] = {};
		for (int i = 0;i < 8;i++) {
			tmp[i] = arr[1][i];
		}

		for (int i = 1;i < 8;i++) {
			arr[1][i] = tmp[i - 1];
		}
		arr[1][0] = tmp[7];
	}
	else if (turn_1 == -1) {
		int tmp[8] = {};
		for (int i = 0;i < 8;i++) {
			tmp[i] = arr[1][i];
		}

		for (int i = 0;i < 7;i++) {
			arr[1][i] = tmp[i + 1];
		}
		arr[1][7] = tmp[0];
	}

	if (turn_2 == 1) {
		int tmp[8] = {};
		for (int i = 0;i < 8;i++) {
			tmp[i] = arr[2][i];
		}

		for (int i = 1;i < 8;i++) {
			arr[2][i] = tmp[i - 1];
		}
		arr[2][0] = tmp[7];
	}
	else if (turn_2 == -1) {
		int tmp[8] = {};
		for (int i = 0;i < 8;i++) {
			tmp[i] = arr[2][i];
		}

		for (int i = 0;i < 7;i++) {
			arr[2][i] = tmp[i + 1];
		}
		arr[2][7] = tmp[0];
	}

	if (turn_3 == 1) {
		int tmp[8] = {};
		for (int i = 0;i < 8;i++) {
			tmp[i] = arr[3][i];
		}

		for (int i = 1;i < 8;i++) {
			arr[3][i] = tmp[i - 1];
		}
		arr[3][0] = tmp[7];
	}
	else if (turn_3 == -1) {
		int tmp[8] = {};
		for (int i = 0;i < 8;i++) {
			tmp[i] = arr[3][i];
		}

		for (int i = 0;i < 7;i++) {
			arr[3][i] = tmp[i + 1];
		}
		arr[3][7] = tmp[0];
	}

	if (turn_4 == 1) {
		int tmp[8] = {};
		for (int i = 0;i < 8;i++) {
			tmp[i] = arr[4][i];
		}

		for (int i = 1;i < 8;i++) {
			arr[4][i] = tmp[i - 1];
		}
		arr[4][0] = tmp[7];
	}
	else if (turn_4 == -1) {
		int tmp[8] = {};
		for (int i = 0;i < 8;i++) {
			tmp[i] = arr[4][i];
		}

		for (int i = 0;i < 7;i++) {
			arr[4][i] = tmp[i + 1];
		}
		arr[4][7] = tmp[0];
	}
}

int pointchecker() {
	int multiplier = 1;
	int tmp = 0;
	for (int i = 1;i <= 4;i++) {
		if (arr[i][0] == 1) {
			tmp += multiplier;
		}

		multiplier = multiplier * 2;
	}
	return tmp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int K, answer;
	for (int i = 1;i <= 4;i++) {
		string temp;
		cin >> temp;
		for (int j = 0;j < 8;j++) {
			arr[i][j] = temp[j] - '0';
		}
	}
	cin >> K;
	for (int i = 0;i < K;i++) {
		int target, turnway;
		cin >> target >> turnway;
		turnit(target, turnway);
	}
	answer = pointchecker();
	cout << answer << '\n';
	return 0;
}