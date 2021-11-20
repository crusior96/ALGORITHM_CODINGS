#include<iostream>
#include<cmath>
using namespace std;

bool primary[1301890] = {};

//N���� ���ڵ��� �־����ٰ� ��������
//�Ҽ� ���� �����̶�, �����ϴ� �� ���� �Ҽ� ���̿� �ռ�����θ� �̾��� �ִ� ������ ���Ѵ�
//�̶� �Էµ� ���ڸ� �����Ͽ� ���� �� �ִ� �Ҽ� ���� ������ ���̸� ���ϰ� ���� �� ���ٸ� 0�� ����϶�
//������ ������ ���� 1���� 100000��° �Ҽ��� 1299709�����̴�

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N;
	cin >> N;

	//�Ҽ������� ���� �����佺�׳׽��� ü ���
	//������ �����θ�ŭ int���� �ƴ϶� bool���� ����ϴ� �迭�� �����Ͽ� �޸𸮸� �Ƴ���
	//primary[i]�� 1�̶�� i�� �Ҽ��� �ƴ϶�� ���̴�
	primary[1] = 1;
	for (int i = 2;i <= 1141;i++) {
		if (primary[i] == 1) {
			continue;
		}
		for (int j = i + i;j <= 1301811;j += i) {
			primary[j] = 1;
		}
	}

	//�Ҽ� ���� �Ÿ��� ���ϱ� ���� �ܼ� while��
	//�����ϰ� �������� �ʰ� �� ��ġ�� �������� �Ҽ����� �ƴ��� �켱 �Ǵ��� ����
	//�Ҽ��� �ƴ϶�� ���������� 1�� �ø��ų� ���̴� ����� ����Ͽ� �Ҽ��� ���� ���� �����Ѵ�
	//���� �Ҽ� ���� �Ÿ��� ���ʰ��� mini�� �������� maxi ������ ���̰��� ������ָ� �ȴ�
	for (int i = 0;i < N;i++) {
		int num, maxi, mini;
		cin >> num;
		maxi = num;
		mini = num;
		bool done = true;

		if (primary[num] == 0) {
			cout << 0 << '\n';
		}
		else {
			while (done) {
				maxi++;
				if (primary[maxi] == 0) {
					break;
				}
				else if (maxi == 1299709) {
					break;
				}
			}

			while (done) {
				mini--;
				if (primary[mini] == 0) {
					break;
				}
				else if (mini == 0) {
					break;
				}
			}
			cout << maxi - mini << '\n';
		}
		
	}

	return 0;
}