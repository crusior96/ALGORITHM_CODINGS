#include<iostream>
#include<string>
using namespace std;

struct knight_pair {
	int x;
	int y;
};

//knight_pair arr[i] : ����Ʈ�� �̵���θ� ������ ���� �����ص� �迭
knight_pair arr[37] = {};
int checker[7][7] = {};

//dx, dy : ����Ʈ�� �̵��� �� �ִ� ��ε鿡 ���� ������ �����ص� �迭
int dx[8][2] = { {0,1} ,{1,1},{1,1},{0,1},{0,-1},{-1,-1},{-1,-1},{0,-1} };
int dy[8][2] = { {-1,-1},{0,-1},{0,1},{1,1},{1,1},{0,1},{0,-1},{-1,-1} };

//ü������ Ư�� ��ġ�� �ִ� ����Ʈ�� ü������ ��ȸ�ϸ鼭 36���� �̵��� �����Ѵ�
//ü������ �� 6*6�� ũ�⸦ ������ �ִ�
//�� �� ������ �̵� �� ���������� �� ���� ��ġ�� �ȵǸ�, ���� �������� �ڽ��� ����� ��ġ���� �Ѵ�
//�̵� ��ΰ� 36���� ���ڿ��� �־����ٸ� �ش� �̵��� ������ �� ���� ��Ģ��� ������ �Ǵ��� ��������

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string knight_run;
	knight_pair k_tmp;
	//���ڿ��� �־����µ� A1�̳� F5�� ���� ü������ ��ġ�� �־����� �ȴ�
	//�̿� ���� ������ ��ȯ�� �ʿ��ϴ�
	for (int i = 0;i < 36;i++) {
		cin >> knight_run;
		k_tmp.x = knight_run[0] - 'A';
		k_tmp.y = 5 - (knight_run[1] - '1');
		arr[i] = k_tmp;
	}

	//���������� �̵��� ������ ���� �������� ���� �� ó�� �־��� ������ �����Ѵ�
	arr[36].x = arr[0].x;
	arr[36].y = arr[0].y;
 
	//36���� �̵����� ��Ģ�� ����Ǵ� ��찡 ����ٸ� done�� false�� �ȴ�
	bool done = true;
	int idx = 0;
	while (done) {
		int chk = 0;
		for (int i = 0;i < 8;i++) {
			//���� ��ġ�� �������� �̵��� �� �ִ� 8�� ���⿡ ���ؼ� ��� Ž���� �����Ѵ�
			//������ �ٱ����� �Ѿ�����ų� �̹� �湮�� ��ġ�� �� �湮�ϴ� ��찡 �ƴ϶�� ��� �����Ѵ�
			if (arr[idx].x + dx[i][0] + dx[i][1] == arr[idx + 1].x && arr[idx].y + dy[i][0] + dy[i][1] == arr[idx + 1].y) {
				if (checker[arr[idx + 1].x][arr[idx + 1].y] == 0) {
					checker[arr[idx + 1].x][arr[idx + 1].y] = 1;
					idx++;
					chk = 1;
					break;
				}
			}
		}

		if (chk == 0) {
			done = false;
			break;
		}

		if (idx == 36) {
			break;
		}
	}


	if (done == false) {
		cout << "Invalid" << '\n';
	}
	else if(done == true){
		cout << "Valid" << '\n';
	}
	return 0;
}