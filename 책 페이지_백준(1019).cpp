#include<iostream>
using namespace std;
long long int checker[10];

//� å�� N��������ŭ �ִٰ� ����. ������ �� �������� 10����� �� ���� �ִ�
//�̶�, 1������������ N���������� ������ �������� �´� ���ڵ��� ��ϵ��ִµ�
//0���� 9���� ���ڵ��� �� ��� �������� ����϶�

//���ڵ��� �� �� �ִ��� checker�� �����ϴ� �Լ�
void num_analyzer(long long n, long long n2) {
	while (n > 0) {
		checker[n % 10] += n2;
		n = n / 10;
	}
}


//�ð� ������ ���� ������ �Լ�
void counter(long long int A, long long int B, long long int n2) {
	while (A % 10 != 0 && A <= B) {
		num_analyzer(A, n2);
		A++;
	}
	if (A > B) {
		return;
	}

	while (B % 10 != 9 && B >= A) {
		num_analyzer(B, n2);
		B--;
	}

	//counter �Լ��� ���� ���ڰ��� �ø��� ���� �� ���������� ���� ī������ �ϱ� ���� �κ�
	//�������� �ణ ���� �κ�����, ���ڰ� �̸�ŭ�� �ߺ��Ǽ� ���԰ڱ����� ī�����ؼ� �ش� ���� checker�� ���س����� ��
	//������ ���ذ� ������ �� �Ȱ���. �ܼ� ���� ��Ʈ + ��͸� ���� �Ǵ� �κ��̱�������
	//����� ������ ������. �ٵ� �̷��� �� �ϸ� �ð��ʰ��� ���� �� �ð�������
	long long cnt = (B / 10 - A / 10 + 1);
	for (int i = 0;i < 10;i++) {
		checker[i] += cnt * n2;
	}

	counter(A / 10, B / 10, n2 * 10);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long int num;
	cin >> num;
	counter(1, num, 1);
	for (int i = 0;i < 10;i++) {
		cout << checker[i] << " ";
	}
	return 0;
}