#include<iostream>
#include<algorithm>
using namespace std;
int num[100003] = {};	//���ڵ� ����Ǵ� �迭

//N���� ���ڷ� �̷���� ���ڵ��� �ִ� ��������
//������ ���ڵ��� �̷� �� �ִ� ���ڽֵ��� ���� �� �ִ� ���̵� ��
//M �̻��̸鼭 ���� ���� ������ ���� ���Ͽ���
//�� ������ �˰����� �̿��� ����Ǯ��
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		cin >> num[i];
	}
	//������ ��� ���ڽ��� ���̰��� �˾Ƴ����ϱ� ����
	sort(num, num + N);
	int s = 0;
	int e = 0;				//���� �����̵� �������� ���۰� ������ ��Ÿ����
	int temp_answer = 0;	//�ӽ������� ��Ÿ���� num[e]�� num[s]�� ���̰�
	int answer = 0;			//���������� �����ϴ� ��

	while (e < N && s < N) {
		//�����̵� ������ �������� ���ǵ�
		//1. M �̸��� ���̸� �����ִ� ���ڽ��̶��
		//1.1. �Ϲ������δ� e�� ���� 1 �ø��� temp_answer���� �ٲ۴�
		//1.2. ������ e�� 1 �þ�� �ε����� �ʰ��Ѵٸ� s�� �ø��� temp_answer���� �ٲ۴�
		if (temp_answer < M) {
			if (e > N) {
				s++;
				temp_answer = num[e] - num[s];
			}
			else {
				e++;
				temp_answer = num[e] - num[s];
			}			
			continue;
		}

		//2. M �̻��� ���̸� �����ִ� ���ڽ��̶��
		//answer�������� �����Է� �̷��� �����ٸ� �ٷ� �Է��ϰ�
		//�����Է� �̷��� �ִٸ� answer �̸��� ������ ��쿡 answer�� �����Ѵ�.
		if (temp_answer >= M) {
			if (answer == 0) {
				answer = temp_answer;
			}
			else if (answer != 0) {
				if (answer > temp_answer) {
					answer = temp_answer;
				}
			}
			
		}
		//������ �����Ͽ� temp_answer�� ���� ���ϰ� ������쿡 s���� �ø��� temp_answer���� �ٲ۴�
		s++;
		temp_answer = num[e] - num[s];
	}
	cout << answer << '\n';
	return 0;
}