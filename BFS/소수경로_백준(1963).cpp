#include<iostream>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
int primary[10001] = {};		//primary[i] = 0�̾�� i�� �Ҽ����� ������ �� �ִ�
int checker[10001] = {};		//checker[i] = i���� ���ڸ� �ٲٴ� �� �Ҹ�� ��ȸ�� Ƚ��
								//-1�� �ʱ�ȭ �� �ʿ䰡 �ִ�

//4�ڸ� �ڿ����� Ư���� ��ȣ�� �ִٰ� ��������
//���� 1�� �ڸ��� �� �� �ٲٴ� ������� �ٸ� ��ȣ�� ������� �ϴµ�, ��ǥ�ϴ� ��ȣ���� �ִٰ� ��������
//�̶�, �ּ����� Ƚ���� ��ȯ�Ͽ� ��ǥ�ϴ� ��ȣ���� �����ϴ� ����� ���Ͽ���
//���ڸ��� 0�� ���� �Ҽ� ��η� �������� �ʴ´�


//���� ��ġ���� �ڸ����� �ٲ㰡�鼭 �Ҽ� ������� üũ�ϰ�, ��ǥ�� �Ҽ����� ������ �� �ִ���,
//��ȯ�� Ƚ���� �ּ������� Ȯ���ϴ� �Լ�
//queue�� ����ؼ� �ּ����� Ž��Ƚ���� �������� Ž�� ������ ����������
void bfs(int idx, int target, int cost) {
	queue<int> q;
	q.push(idx);
	checker[idx] = 0;
	int answer = 0;
	while (q.empty() == false) {
		int tmp = q.front();
		q.pop();

		//��ǥ ��ġ�� �����ߴٸ� ����� �����Ѵ�
		if (tmp == target) {
			answer = checker[tmp];
			break;
		}

		//���� ��ġ�� �Ҽ��� �������� �Ҽ��� �� �ڸ��� 0���� 9���� �ٲ㰡�鼭 �����Ѵ�
		//�� ����, �ٲﰪ�� �Ҽ��Ӱ� ���ÿ� checker[�ٲ�Ҽ�]�� ���� -1�̶��
		//���� ȸ���� bfsŽ�� �Ҽ��� ����� �Ѵ�
		for (int i = 0;i < 4;i++) {
			string tmp_s = to_string(tmp);
			for (int j = 0;j < 10;j++) {
				tmp_s[i] = '0' + j;
				int tmp_i = stoi(tmp_s);
				if (tmp_i >= 1000 && primary[tmp_i] == 0 && checker[tmp_i] == -1) {
					checker[tmp_i] = checker[tmp] + 1;
					q.push(tmp_i);
				}
			}
		}
	}
	cout << answer << '\n';
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	primary[1] = 1;
	for (int i = 2;i <= 100;i++) {
		if (primary[i] == 1) {
			continue;
		}
		for (int j = i + i;j <= 10000;j += i) {
			primary[j] = 1;
		}
	}

	int Tc;
	cin >> Tc;
	for (int i = 0;i < Tc;i++) {
		memset(checker, -1, sizeof(checker));
		int s, e;
		cin >> s >> e;
		bfs(s, e, 0);
	}

	return 0;
}