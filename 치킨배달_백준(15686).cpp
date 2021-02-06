#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
int maps[52][52] = {};
int M, N;
int answer;
bool selected_chicken[14];		//ġŲ�Ÿ��� �� ��, ���õ� ġŲ������ �ƴ����� ���� ������ ���ִ�

//N * N���� ������ M�� �̻��� ġŲ���� �ִٰ� ��������
//������ ���������� 0 = ����� / 1 = �� / 2 = ġŲ���� �ǹ��Ѵ�
//�̶� 'ġŲ�Ÿ�'��, ������ ������ �ִܰŸ��� ������ �� �ִ� ġŲ�������� �Ÿ��� �ǹ��ϸ�
//�� �Ÿ��� ġŲ���� �� ������ ����ư �Ÿ��� �ǹ��Ѵ�
//M���� ġŲ������ ��� �� �ִٰ� ������ ��, ���� �� �ִ� �ִ� ġŲ�Ÿ��� ���Ͽ���

struct house {
	int h_idx;
	int h_idy;
};

struct chicken{
	int c_idx;
	int c_idy;
};

//���� ���� ġŲ���� ��ġ�� ���� �������� ������ ����
vector<house>houselist;
vector<chicken>chickenlist;

//DFS�� ����Ͽ� ġŲ�Ÿ��� ���� ����. idx�� ���õ� or �������� �ʰ� �ѱ� ġŲ�� �迭�� ��ġ, sel�� ������� ���õ� ġŲ���� �����̴�
//chickenlist[idx]�� ġŲ���� ������� �ʴ´ٸ� selected_chicken���� false, �ƴϸ� true�� �����ص� ä �����Ѵ�
void dfs(int idx, int sel) {
	//sel ���� M�� ����������, ���õ� ġŲ������ ������� ġŲ�Ÿ��� ���
	//���� ������ ��ġ�� ���õ� ġŲ�� ������ ����ư �Ÿ��� �����Ͽ� ġŲ�Ÿ��� ������
	if (sel == M) {
		int temp_answer = 0;
		for (int i = 0;i < houselist.size();i++) {
			int len = 100000002;
			for (int j = 0;j < chickenlist.size();j++) {
				if (selected_chicken[j]) {
					int tmp_len = abs(houselist[i].h_idx - chickenlist[j].c_idx) + abs(houselist[i].h_idy - chickenlist[j].c_idy);
					len = min(len, tmp_len);
				}
			}
			temp_answer += len;
		}
		answer = min(answer, temp_answer);
		return;
	}

	//���� idx���� ġŲ�� ������ ���� ��Ȳ�̶�� �����Ѵ�
	if (idx == chickenlist.size()) {
		return;
	}

	selected_chicken[idx] = true;
	dfs(idx + 1, sel + 1);
	selected_chicken[idx] = false;
	dfs(idx + 1, sel);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < N;j++) {
			cin >> maps[i][j];
			if (maps[i][j] == 1) {
				house temp_house;
				temp_house.h_idx = i;
				temp_house.h_idy = j;
				houselist.push_back(temp_house);
			}
			else if (maps[i][j] == 2) {
				chicken temp_chick;
				temp_chick.c_idx = i;
				temp_chick.c_idy = j;
				chickenlist.push_back(temp_chick);
			}
		}
	}
	answer = 1000001;
	dfs(0, 0);

	cout << answer << '\n';
	return 0;
}