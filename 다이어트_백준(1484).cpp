#include<iostream>
#include<cmath>
using namespace std;

//���� ������ �������� ���� ������ ������ ���� ������ ���ڸ� G��� ��������
//�̶�, ���� ���ڷ� ������ ���ڵ��� ��� ����ϰ� ����� ���ڰ� ���ٸ� -1�� ����϶�
//��, ������ ���ڰ��� ������ ���ڰ����� ������ �۰ų� ����

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long int G;
	cin >> G;
	long long int s = 1;		//������ ����
	long long int e = 1;		//���� ����
	long long int dif = 0;		//G�� �񱳵Ǵ� ���������� �����
	bool done = true;
	int answered = 0;

	//�����̵� �����Ͱ� ���Ǵ� �˰���
	//������ ���ڵ� ������ ���ڵ� �𸣴� ��Ȳ�̹Ƿ� �� �� 1�� ������ �� �˰����� �����Ѵ�
	//������ ���� ���� ���� G���� �۴ٸ� ������ ���ڰ���, G���� ũ�ٸ� ������ ���ڰ��� 1�� �ø���.
	//���ſ� ������ ���� ���̰� 1�����ۿ� �ȳ���  dif���� G���� ũ�ٸ� �˰����� �����Ѵ�
	while (done) {
		dif = pow(e, 2) - pow(s, 2);

		if ((e - s == 1) && (dif > G)) {
			if (answered == 0) {
				cout << -1 << '\n';
			}
			done = false;
			break;
		}

		if (dif == G) {
			cout << e << '\n';
			answered = 1;
			s++;
		}
		else if (dif < G) {
			e++;
		}
		else if (dif >= G) {
			s++;
		}


	}
	return 0;

}