#include<iostream>
#include<list>
#include<cmath>
#include<queue>
using namespace std;

//K���� �Ҽ����� �������ִٰ� ��������
//�ش��ϴ� �Ҽ��鳢�� ���ؼ� ���� �� �ִ� ���ڵ��� ���� ���ڵ���� �տ� ���°ɷ� �����Ѵٸ�
//������ ���ڵ� �� N��° ���ڴ� �������� ���Ͽ���
//��, �ԷµǴ� ���ڴ� 541���� ���� �����̸�, ������ ���� �� �ִ� ���ڴ� 2^31���� �۴�
int main() {
	int K, N;
	int primes[101] = {};

	//�ڵ������� �������� ������ �����ϱ� ���� �Ҽ��� ������ �����ϴ� �켱���� ť
	//������ ���� N * (K-1)����ŭ �����ϸ� �ż� ũ�� �δ��� ����.
	priority_queue<long> PQ;	
	cin >> K >> N;
	for (int i = 0;i < K;i++) {
		int temp;
		cin >> temp;
		primes[i] = temp;
		PQ.push(-temp);
	}

	long answer;
	
	//Ǯ�̹��
	//1. �켱 �Ҽ����� PQ�� �����Ѵ�
	//2. PQ���� ���� ���� ���ڸ� ����Ͽ� �Ҽ����� ����� �迭�� primes�� ��� ���� ���غ���
	//3. answer%primes[j] == 0 ��, �ߺ��Ǵ� ������ ����� ���,
	//	 �ش� �κб����� PQ���� ������ �� primes �迭���� �Ҽ��鳢�� ���ϴ� ���� �����
	//	 �̴� �ߺ��� ���� PQ�� ����Ǵ°��� ���� ���ؼ��̴�
	//4. �׷��� PQ���� �ڷᰪ�� �̴� ������ N�� �ݺ��� ���� answer���� ����ϸ� �ȴ�.
	for (int i = 0;i < N;i++) {
		answer = PQ.top();
		PQ.pop();
		answer = answer * -1;
		for (int j = 0;j < K;j++) {
			long temp = answer * primes[j];
			PQ.push(temp * -1);
			if (answer%primes[j] == 0) {
				break;
			}
		}
	}


	cout << answer << '\n';
	return 0;
}