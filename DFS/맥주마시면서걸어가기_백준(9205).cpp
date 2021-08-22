#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#include<iomanip>
#include<string>
using namespace std;

//����ư �Ÿ��� ���ϰ� ������ ��ǥ���� �����ϱ� ���� ����� ����ü
struct location {	
	int x;
	int y;
};
int checker[102] = {};				//�ش� ������ �����ߴ����� ���� üũ. 0�̸� ����X, 1�̸� ����O
vector<location> location_list;		//�������� ��ǥ������ �����صд�
vector<int> ways[102] = {};			//������ �̵��� �� �ִ� ��ε鸸�� �����ص� vector

//������ ��� �� �� ���ָ� 20�� ��� ����� �� �ְ�, 50���͸� �̵��� �� ���� ���� 1���� �Ҹ��ؾ� �Ѵ�
//���������� ���ָ� ������ �� �ְ� �ִ� 20�������� �����ϸ� �������� �� N�� �����Ѵ�
//�� ��ǥ ������ �Ÿ��� ����ư �Ÿ��� ����Ѵ�
//�̶� ������ ���������� ������� ���ָ� ���ø鼭 ������ �� �ִ��� ���Ͽ���
//���� �̵��ϸ鼭 ���ָ� �� ���ð� �ȴٸ� �� ���� �����ϰ� �ȴ�
//��ǥ�� �Է��� ������ �� - �������� - ���� ���� ���̴�


//���� ������ �������� ������ �� �ִ� �ٸ� ������ Ž���Ѵ�
//�⺻������ dfs�� �����
void dfs(int now) {
	checker[now] = 1;
	for (int i = 0;i < ways[now].size();i++) {
		if (checker[ways[now][i]] == 0) {
			dfs(ways[now][i]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int Tc;
	cin >> Tc;
	for (int i = 0;i < Tc;i++) {
		memset(checker, 0, sizeof(checker));
		memset(ways, 0, sizeof(ways));
		int N;
		cin >> N;
		int tmp1, tmp2;
		location loc1, loc2;
		cin >> tmp1 >> tmp2;
		loc1.x = tmp1;
		loc1.y = tmp2;
		location_list.push_back(loc1);

		for (int j = 0;j < N;j++) {
			cin >> tmp1 >> tmp2;
			location loc;
			loc.x = tmp1;
			loc.y = tmp2;
			location_list.push_back(loc);
		}

		cin >> tmp1 >> tmp2;
		loc2.x = tmp1;
		loc2.y = tmp2;
		location_list.push_back(loc2);

		//���� ���ǿ� �°� ������ ��ǥ�� ������ ����ư�Ÿ��� ����, 1000 ������ �͵鸸 ��ην� �ν��ϰ� �����Ѵ�
		for (int j = 0;j < N + 1;j++) {
			for (int k = j + 1;k < N + 2;k++) {
				if (abs(location_list[j].x - location_list[k].x) + abs(location_list[j].y - location_list[k].y) <= 1000) {
					ways[j].push_back(k);
					ways[k].push_back(j);
				}
			}
		}

		dfs(0);
		string answer = "happy";

		//�������� ������ �� ������ happy, �ƴϸ� sad ���
		if (checker[N + 1] == 0) {
			answer = "sad";
		}

		cout << answer << '\n';

		while (location_list.empty() == false) {
			location_list.pop_back();
		}
	}
}