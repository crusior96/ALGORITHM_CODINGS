#include<iostream>
using namespace std;

//��� �޷��� �ִٰ� ��������
//�ش� �޷��� �� �������� 1���� ���� ����ϰ�, 1���� ������ �κ��� �� ���ķ� �̾ ����
//������ ���� �ٷ� �Ѿ�� ���ٰ� ��������
//�ش� �޷¿� ���� 1�⿡ �ִ� ���� ������, ������ �޿� �ִ� ���� ��, �޷¿� ǥ��Ǵ� 1���� ��¥ ������ �Է��Ѵٸ�
//�޷��� ��µǴ� �� ���� ������ ���Ͽ���

long long int gcd(long long int a, long long int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

long long int lcm(long long int a, long long int b, long long int gc) {
	return (a*b) / gc;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int Tc;
	cin >> Tc;
	for (int i = 0;i < Tc;i++) {
		long long int M, D, W;
		cin >> M >> D >> W;
		//�����а� ����� ������ ���� ���� �ϸ� �ɵ��ϴ�
		//1. �⺻������ ��ü �ϼ��� ���� ����, �ش� ������ �� �������� �̷�������� ���Ѵ�
		//2. �� ���� ������ ������ ���� �ٷ� �Ѿ�� ������ ������ ��쿡 ���� ���� ������ ĭ�� ���� ������ ���� �������� �ִ�
		//3. ���� �ش� ��츦 ã�� ���� ��ü ���� ���� - �Ⱑ������ ������ ���� ��¥�� ���� ������ĭ�� ����� ���� ����Ѵ�
		//4. �ش� �޷��� �̷���� �⺻���� ������ �� + ��¿ �� ���� �����ٷ� �Ѿ���ϴ� 3���� ��츦 ����ϸ� �ȴ�

		long long int answer_1 = (M * D) / W;
		long long int gcd_temp = gcd(W, D);
		long long int lcm_temp = lcm(W, D, gcd_temp);
		long long int tmp1 = lcm_temp / D;
		long long int answer_2 = M - (M / tmp1);
		long long int answer = answer_1 + answer_2;
		cout << "Case #" << i + 1 << ": " << answer << '\n';
	}
	return 0;
}