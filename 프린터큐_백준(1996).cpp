#include<iostream>
#include<queue>
#include<utility>
using namespace std;

//N���� �������� �ִٰ� ��������. �ش� �������� FIFO�� ��Ģ�� ���� ������ִ�.
//������ �������� ��ȣ�� �ο��޴µ� 0 ~ N-1�� ��ȣ�� ���������� �޴´�
//���� ������ �������� �߿䵵�� �ο��ް� �Ǵµ� �߿䵵�� ������ 1 ~ 9�̸� �߿䵵�� �������� �� ������ ���� ��µȴ�
//���� ��¹���� ���� ť ó�� �߿䵵�� �� ���� ������ ���� �ִٸ� ��´���� �� ���� ������ �� �ڷ� ���������� �ȴ�
//�̶� M��°�� ��µǴ� ������ �������� �� ��° �������� ���Ͽ���

int main() {
	ios::sync_with_stdio(false);
	int Tc;
	cin >> Tc;
	for (int i = 0;i < Tc;i++) {
		int M, N, cnt;
		cnt = 0;
		//pair<int, int>�� �ڷ������� ���� ť�� q���ٰ� ���� ������ ��ȣ �� �߿䵵�� �����Ѵ�
		//�켱���� ť�� �̿��ؼ� q ���� �ִ� ������ �� ���� ����� �����鿡 ���� ������ �߿䵵�� �������� �����Ѵ�
		queue<pair<int, int>>q;
		priority_queue<int> pq;
		cin >> N >> M;
		for (int j = 0;j < N;j++) {
			int temp;
			cin >> temp;
			q.push({ j,temp });
			pq.push(temp);
		}

		//���� ���� �ִ� q�� �������� �տ������� ���ϴµ� pq.top()�� �߿䵵�� ���� �͵��� ���� ����Ѵ�
		//���ٸ� �ش� ������ ���� ������ q�� pq���� pop�ϰ�, �׷��� �ʴٸ� �񱳸� ���� �̾Ƴ��Ҵ� �ڷḦ
		//�ٽ� q �� �ڷ� �Է½��ѵд�
		while (!q.empty()) {
			int pt = q.front().first;
			int value = q.front().second;
			q.pop();

			if (pq.top() == value) {
				pq.pop();
				cnt++;
				if (pt == M) {
					cout << cnt << endl;
					break;
				}	
			}
			else {
				q.push({ pt,value });
			}
		}
		
	}
	return 0;
}