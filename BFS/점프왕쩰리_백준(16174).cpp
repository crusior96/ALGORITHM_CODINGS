#include<iostream>
#include<queue>
using namespace std;

int arr[66][66] = {};			//�迭�� ����� ���ڵ��� ��
int checked[66][66] = {};		//bfs�� ���� ������ �� �ִ� ������ 1�� �����Ѵ�

//N*N ũ���� �迭�� �ִٰ� ��������
//������ �迭���� 0 �̻��� ���ڵ��� ����������, ���ϴ��� ������ �������� -1�� �����ִ�
//���� �迭�� �ִ� ���ڸ� �������� ������ Ȥ�� �Ʒ��θ� ������ �� ������ �迭�� �ִ� ������ �Ѿ ���, Ż���Ѵ�
//�̶�, ���ϴ��� ������ �������� ������ �� �ִ����� ���� ���θ� �Ǵ��϶�

struct now {
	int x;
	int y;
};

//����Ǯ�� 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> arr[i][j];
		}
	}

	queue<now> q;	//bfs�� ����ϱ� ���� ť
					//�����̱� ��, ���� ��ġ�� ��ǥ���� �����صд�
	now temp;
	temp.x = 0;
	temp.y = 0;
	q.push(temp);
	bool done = true;
	int answer = -1;
	while (done) {
		if (q.empty()) {
			done = false;
			break;
		}

		now tmp = q.front();
		int tmp_x = tmp.x;
		int tmp_y = tmp.y;
		checked[tmp_x][tmp_y] = 1;
		q.pop();

		//BFS ����
		//1. ���� ��ġ�� �츮�� ���ϴ� �������ΰ�?
		//2. �ƴ϶��, ���� ��ġ�� ���� 0�� �ƴѰ�?
		//3. �ƴ϶��, ���� ��ġ�� �������� üũ �� �κ��ΰ�?
		//4. �ƴ϶��, ���� ��ġ�� �迭 ���� �����ΰ�?
		//5. �׷��ٸ� ��ǥ�� �̵��� ���� q�� push�� ���� bfs�� �����Ѵ�

		//2���� 3�� ������ ���� �޸𸮰� �ʰ��ϴ� ������ ���� �� �ִ�
		if (tmp_x == N - 1 && tmp_y == N - 1) {
			answer = 1;
			done = false;
			break;
		}

		if (arr[tmp_x][tmp_y] != 0) {
			if (tmp_x + arr[tmp_x][tmp_y] < N) {
				if (checked[tmp_x + arr[tmp_x][tmp_y]][tmp_y] == 0) {
					checked[tmp_x + arr[tmp_x][tmp_y]][tmp_y] = 1;
					now tmp2;
					tmp2.x = tmp_x + arr[tmp_x][tmp_y];
					tmp2.y = tmp_y;
					q.push(tmp2);
				}
			}

			if (tmp_y + arr[tmp_x][tmp_y] < N) {
				if (checked[tmp_x][tmp_y + arr[tmp_x][tmp_y]] == 0) {
					checked[tmp_x][tmp_y + arr[tmp_x][tmp_y]] = 1;
					now tmp2;
					tmp2.x = tmp_x;
					tmp2.y = tmp_y + arr[tmp_x][tmp_y];
					q.push(tmp2);
				}
			}
		}
	}

	if (answer == 1) {
		cout << "HaruHaru" << '\n';
	}
	else {
		cout << "Hing" << '\n';
	}
	return 0;
}