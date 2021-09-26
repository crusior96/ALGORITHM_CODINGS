#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int answer = 1000001;	//������ ���ٸ� �ش� ���ڷδ� ���� ���ǿ� �´� ���� ���� �� ���ٴ� ��
int idx = 0;
int cmpnum;
int place_num[6] = {};
bool check[6] = {};

//100�����ٴ� ���� �ڿ����� �ִٰ� ��������
//�ش� �ڿ��� ���� �ִ� ���ڵ��� ���Ƿ� ���ġ�ؼ� ���纸�� ū �� �� �ּڰ��� ������
//��, �� ���ڸ��� 0�� �� ���� ����


//��� �� ���Ʈ������ ����Ǵ� �Լ�
//���� ���ġ�� ��� �Ǵ� ���� number, ���ġ�� ���۵� �ڸ����� status�� �����Ѵ�
void bruteforc(int number, int status) {
	//status�� 0�̶�� ������ 1�ڸ��� �۾��� �����ϰ�
	//���� ���� �������� ���� ���ǿ� �°� ����� ���Ѵ�
	if (status == 0) {
		int tot = number;
		for (int i = 0;i < idx;i++) {
			if (check[i] == false) {
				check[i] = true;
				tot += place_num[i];
				check[i] = false;
				break;
			}
		}

		if (answer > tot && cmpnum < tot) {
			answer = tot;
		}
	}
	//status�� 0�� �ƴ϶�� ���� �ڸ����� �������� �۾��� �����Ѵ�
	//����Լ� ������ ���� �켱������ �ش� ��ġ�� check�� true�� ����, tmp�� ���� �Լ��� ���� ���� ����� ���� bruteforc�� ��͸� �����ϰ�
	//���Ŀ� ������ �ٸ� ����Լ��� ���� �ش� ��ġ�� chekc�� false�� �����Ѵ�
	else {
		for (int i = 0;i < idx;i++) {
			if (check[i] == false) {
				check[i] = true;
				int tmp = pow(10, status) * place_num[i];
				bruteforc(number + tmp, status - 1);
				check[i] = false;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	cmpnum = N;

	while (N > 0) {
		int tmp = N % 10;
		place_num[idx] = tmp;
		idx++;
		N /= 10;
	}


	//bruteforc�Լ��� ó�� ����Ǵ� �κ�
	//�� ���ڸ��� �������� �ִ� 6������ bruteforc�� ����ȴ�
	for (int i = 0;i < idx;i++) {
		if (place_num[i] != 0) {
			check[i] = true;
			int tmp = pow(10, idx - 1) * place_num[i];
			bruteforc(tmp, idx - 2);
			check[i] = false;
		}
	}

	if (answer == 1000001) {
		cout << 0 << '\n';
	}
	else {
		cout << answer << '\n';
	}
	return 0;
}