#include<iostream>
#include<queue>
using namespace std;

int mov_x[4] = {0,0,1,-1};
int mov_y[4] = {-1,1,0,0};
int clockway[4] = {2,1,3,0 };	//�ð� ���� ȸ���� ������ �� mov_x, y�� ��� ���� ����� �� �����ص� �迭
int declockway[4] = {2,0,3,1};	//�ݽð� ���� ȸ���� ������ �� mov_x, y�� ��� ���� ����� �� �����ص� �迭
int maps[53][53] = {};			//���� ������ ����� �̼����� �� ����û������ ��ġ ��Ȳ
int tmp_maps[53][53] = {};		//��ȯ �۾��� ������ �� maps���� �ӽ������� �����صδ� ������ �迭
int R, C, T;

//����û������ ���κп� ���� ��ǥ ����ü
struct upside {
	int x;
	int y;
};

//����û������ �Ʒ��κп� ���� ��ǥ ����ü
struct downside {
	int x;
	int y;
};

//�̼��������� ������ ť�� �����ϱ� ���� ����� �� ����ü
//�̼������� �����ϴ� ��ġ�� �̼������� ���� ����ȴ�
struct dusts {
	int x;
	int y;
	int amount;
};

upside u;
downside d;


//�̼������� Ȯ���ϸ� ���Ǵ� �Լ�
void spread() {
	queue<dusts> dust_q;
	//dust_q�� �̼������� �����ϴ� ������ ��� �����صд�
	//�ٸ�, �ش� ��ġ�� �̼����� ���� 4���� Ŀ�߸� �Ѵ�. 4���� ������ Ȯ�� �� 0�� �ȴ�.
	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			if (maps[i][j] > 4) {
				dusts dmp;
				dmp.x = j;
				dmp.y = i;
				dmp.amount = maps[i][j];
				dust_q.push(dmp);
			}
		}
	}

	//dust_q�� ������� �� ���� Ȯ���� �����Ѵ�
	while (dust_q.empty() == false) {
		dusts dust_temp = dust_q.front();
		dust_q.pop();

		
		int tmp_amount = dust_temp.amount;
		int now_spread = tmp_amount / 5;	//Ȯ��� ������ �̼������� ��
		int ways = 4;						//Ȯ���� �� �ִ� ������ ��

		for (int i = 0;i < 4;i++) {
			int idx = dust_temp.x + mov_x[i];
			int idy = dust_temp.y + mov_y[i];

			//Ȯ���ϰ��� �ϴ� ��ġ�� ���� ���̶�� ways�� ���δ�
			if (idx >= 0 && idx < C && idy >= 0 && idy < R) {
				//Ȯ���ϰ��� �ϴ� ��ġ�� ����û���Ⱑ �ִٸ� ways�� ���δ�
				if (maps[idy][idx] == -1) {
					ways--;
				}
				else {
					maps[idy][idx] += now_spread;
				}
			}
			else {
				ways--;
			}
		}

		//Ȯ���� ����� ���� ���� �̼������� ���� �����صд�
		maps[dust_temp.y][dust_temp.x] -= now_spread * ways;
	}
}

//��ȯ�� ����� �� ���Ǵ� �Լ�
//����û������ ��ġ�� ����ϰ� �� ��ȯ����� ����ȴ�
//����û������ ���κп��� ��ȯ�� �ݽð����, �Ʒ��κп��� ��ȯ�� �ð�������� �̷������� �Ѵ�
void circulate(int idx, int idy, int ways[4]) {
	int y = idy;
	int x = idx + 1;	//����û������ ���� �κк��� ��ȯ�� ����ȴ�

	maps[y][x] = 0;

	for (int i = 0;i < 4;i++) {
		//��ȯ�� Ư�� ������ �������� �����ϴ� 2���� ������ �߻��ϸ� ���߰� ���� �������� �����Ѵ�
		//1. �ش� ��ġ�� ���� ���� ���
		//2. �ش� ��ġ�� ����û������ ��ġ �� ��ȯ�� �� ���� �� ���� ���
		while (true) {
			int tmp_x = x + mov_x[ways[i]];
			int tmp_y = y + mov_y[ways[i]];

			if (!(0 <= tmp_y && tmp_y < R && 0 <= tmp_x && tmp_x < C)) {
				break;
			}

			if (idy == tmp_y && idx == tmp_x) {
				break;
			}

			//��ȯ�� ���۵Ǳ� �� �̸� �����ص� tmp_maps�� ������ maps�� �ٽ� �ű��
			//���� ��ǥ�� ���� ���� ��ȯ�� ���� x�� y�� ���� tmp_x, tmp_y�� ���� �̾�޴´�
			maps[tmp_y][tmp_x] = tmp_maps[y][x];
			y = tmp_y;
			x = tmp_x;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> R >> C >> T;
	int chk = 0;
	int answer = 0;
	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			cin >> maps[i][j];

			//����û������ ���κа� �Ʒ��κ��� ��ǥ�� ���������� �����صд�
			if (maps[i][j] == -1 && chk == 0) {
				u.x = j;
				u.y = i;
				chk = 1;
			}
			else if (maps[i][j] == -1 && chk != 0) {
				d.x = j;
				d.y = i;
			}
		}
	}

	for (int i = 0;i < T;i++) {
		spread();

		//Ȯ���� ����� ������ ���¸� tmp_maps�� �����صд�
		//maps�� �ٷ� �ű�⺸�� �޸𸮵� ����ϴ� tmp_maps�� ������ ���� maps�� ���Ž�Ű�°� ���ϴ�
		//������ �����ϴ� 3�ܺ���� ����ϴٰ� �����ϸ�ɵ�?
		for (int j = 0;j < R;j++) {
			for (int k = 0;k < C;k++) {
				tmp_maps[j][k] = maps[j][k];
			}
		}

		//���� ���� �ݽð�, �ð���������� ��ȯ�� �̷�����µ�
		//��ȯ�� �̷���� ���� ������ maps�� �ٽñ� ����ȴ�
		circulate(u.x, u.y, declockway);
		circulate(d.x, d.y, clockway);
	}

	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			if (maps[i][j] > 0) {
				answer += maps[i][j];
			}
		}
	}

	cout << answer << '\n';
	return 0;
}