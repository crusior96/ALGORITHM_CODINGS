#include<iostream>
using namespace std;
int N;
long long int time_checker[2002][2] = { 1 };	//time_checker[i][0] : �⼮, time_checker[i][1] : �Ἦ
long long int time_checker_non[2002] = { 0 };	//time_checker_non[i] : i��° ���� ������
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long int answer;
	cin >> N;
	time_checker[1][0] = 1;
	time_checker[1][1] = 1;
	time_checker[2][0] = 2;
	time_checker[2][1] = 2;
	//������ �� �ѹ��� ���� ���� ���� ����� ������ ���ϴ� �۾�. 
	//�̶� �Ἦ�� 3������ �ϸ� �� �ǹǷ� ������ �� ¥���Ѵ�
	for (int i = 3;i <= N;i++) {
		time_checker[i][0] = time_checker[i - 1][0] + time_checker[i - 1][1];
		time_checker[i][1] = time_checker[i - 1][0] + time_checker[i - 2][0];
		if (time_checker[i][0] >= 1000000) {
			time_checker[i][0] %= 1000000;
		}

		if (time_checker[i][1] >= 1000000) {
			time_checker[i][1] %= 1000000;
		}
	}

	answer = time_checker[N][0] + time_checker[N][1];	//������ �� �ѹ��� ���� ���� ��찡 ���ʷ� ����ȴ�

	if (answer >= 1000000) {
		answer %= 1000000;
	}
	//���� ������ 1ȸ�� �ϴ� ��츦 ����ؼ� �����Ѵ�
	//����� ���� ���� i�� �������� (0~i) , (i~N)������ ����� ������ ���� �����ִ� ���� i��° ���� ���� ���� �������� ��´�.
	//�ش� ����� ������ ��� answer�� ������ �� ���ǿ� �°� �ٲ��ش�
	for (int i = 1;i <= N;i++) {
		time_checker_non[i] = (time_checker[i - 1][0] + time_checker[i - 1][1]) * (time_checker[N - i][0] + time_checker[N - i][1]);
		if (time_checker_non[i] >= 1000000) {
			time_checker_non[i] %= 1000000;
		}
		answer += time_checker_non[i];
		if (answer >= 1000000) {
			answer %= 1000000;
		}
	}

	cout << answer << '\n';
	return 0;
}