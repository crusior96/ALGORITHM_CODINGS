#include<iostream>
#include<cmath>
using namespace std;
int N;
int answer = 0;
int cols[16] = {};	//cols[i] = temp -> i��° ���� �ǿ� �������� ��, temp��° �ǿ� ������������ �ǹ��ϴ� ���

//N*Nĭ�� �ǿ� N���� ���� �������� �Ѵ�
//�̶� ������ ���� �̵���λ� ���� ������������ �ȵȴ�
//N���� ���� ���� ��, �ǿ� ������ ���� �� �ִ� ����� ������ ��� ���Ͽ���
//�ϸ� ���Ʈ������ ������ ���� �� �ϳ�


//������ ���� �̵���ΰ� ��ġ���� �ƴ��� �׽�Ʈ�ϴ� �Լ�
//tmp��° ���� ���� cols[]���� ������ ���Ҵ� ������ cols[]���� ������
//�ƴϸ� tmp��° ���� ���� ������ ���Ҵ� ������ �밢���� �ִ��� �׽�Ʈ�ؼ�
//���� ��ģ�ٸ� false��, �Ȱ�ģ�ٸ� true�� ����Ѵ�
bool rule_check(int tmp) {
	for (int i = 0;i < tmp;i++) {
		if (cols[i] == cols[tmp] || abs(cols[tmp] - cols[i]) == tmp - i) {
			return false;
		}
	}
	return true;
}

//���� x�� �����鼭 answer���� ���ϴ� ����Լ�
//x�� N�� �� ������ answer�� �÷��ش�
void queen_check(int x) {
	if (x == N) {
		answer++;
	}
	else {
		for (int i = 0;i < N;i++) {
			cols[x] = i;
			if (rule_check(x)) {
				queen_check(x + 1);
			}
		}
	}
}

int main() {
	cin >> N;
	queen_check(0);
	cout << answer << '\n';
	return 0;
}