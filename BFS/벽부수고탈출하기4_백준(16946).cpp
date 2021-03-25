#include<iostream>
#include<cstring>
#include<utility>
#include<set>
using namespace std;
int N, M;

//N*M�� ũ�⸦ ���� ����� �ִٰ� ��������
//���� �κ��� 1, �ƴ� �κ��� 0�̶�� ������ ��
//N*M�� �� �󿡼� ���� �κ��� �ν��� ��� �ش� ��ġ���� Ž���� �� �ִ� ���� ũ�⸦ ���Ͽ���
//�翬�ϰԵ� ���� �ƴ� �κ��� �μ� ���� ������ 0�� ����Ѵ�

struct land_info {
	int land_num = 0;
	int land_size = 0;
};

char arr[1002][1002] = {};			//N*M�� ũ�⿡ ����� ��������. 0�̸� �ո�����, 1�̸� ���̴�.
land_info lands[1002][1002] = {};	//�ش� ���� ���� �� ���� �ο����� ����ȣ�� �����Ѵ�
int checker[1002][1002] = {};
int land_infos[1000002] = {};		//0���� ������ ������ ���̿� ���� ������ ����ȴ�. ���ʷ� ã�� �� ���� ���������� �����Ѵ�.
									//land_infos[i] : i��° ���� ����� ���� ����
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int cnt;

void flood_fill(int y, int x, int nu) {
	checker[y][x] = 1;
	cnt++;
	for (int k = 0;k < 4;k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if ((0 < ny && ny <= N) && (0 <= nx && nx <= M)) {
			if (!checker[ny][nx] && arr[ny][nx] == '0') {
				lands[ny][nx].land_num = nu;
				flood_fill(ny, nx, nu);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int cnt2 = 1;
	cin >> N >> M;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			cin >> arr[i][j];
		}
	}

	//flood_fill �Լ��� ����ؼ� 0���θ� �̷���� ������ ���̸� ���Ѵ�
	//����ȣ�� �ο����� ���� ���� ������ ����ȣ�� �ο��ް� �� ����ȣ�� ���� ���̸� �ش� ��ġ�� �����Ѵ�
	//����ȣ�� �ο��޾����� �ش� ��ġ�� ���̿� ���� ������ ���ٸ�, �ش� ����ȣ�� ���� ���̸� �ش� ��ġ�� �����Ѵ�
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			if (arr[i][j] == '0' && lands[i][j].land_num == 0) {
				cnt = 0;
				flood_fill(i, j, cnt2);
				lands[i][j].land_size = cnt;
				lands[i][j].land_num = cnt2;
				land_infos[cnt2] = cnt;
				cnt2++;
			}
			else if (arr[i][j] == '0'&&lands[i][j].land_num != 0) {
				lands[i][j].land_size = land_infos[lands[i][j].land_num];
			}
		}
	}


	//���� �����󿡼� '1'�� ����� �κ��� �μ��� Ž���� �� �ִ� ���� ���̸� ���Ѵ�
	//��, ��� ���ǻ� 10���� ���� �������̱� ������ 1�� ������ ����(������ġ) 10���� �������� ��������
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			if (arr[i][j] == '1') {
				int tmp = 0;
				set<int> land_cnt;	//�ϵ� �ڵ� �������� set �����̳ʸ� ���. �ߺ��Ǵ� �� ��ȣ�� ���� �κ��� �������� �ȵǱ� ����.
				//land_tmp : '1'�� ���� �������� �����¿쿡 �ִ� ������ ����ȣ�� ����
				//land_tmp2 : '1'�� ���� �������� �����¿쿡 �ִ� ������ ��ũ�Ⱚ ����
				int land_tmp[4] = { lands[i - 1][j].land_num, lands[i][j + 1].land_num, lands[i + 1][j].land_num,lands[i][j - 1].land_num };
				int land_tmp2[4] = { lands[i - 1][j].land_size, lands[i][j + 1].land_size, lands[i + 1][j].land_size, lands[i][j - 1].land_size };
				int tmp2 = 0;
				for (int k = 0;k < 4;k++) {
					if (k == 0) {
						tmp += land_tmp2[k];
						land_cnt.insert(land_tmp[k]);
					}
					else {
						if (land_cnt.count(land_tmp[k]) == 0) {
							tmp += land_tmp2[k];
							land_cnt.insert(land_tmp[k]);
						}
					}
				}
				
				cout << (tmp + 1) % 10;
			}
			else if (arr[i][j] == '0') {
				cout << 0;
			}
		}
		cout << '\n';
	}


	return 0;
}