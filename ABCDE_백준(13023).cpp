#include<iostream>
#include<vector>
using namespace std;
vector<int> friends[2002];
int possible = 0;

//A�� B�� �˰�, B�� C�� �˰�, C�� D�� �˰�, D�� E�� �ƴ� ��Ȳ�� ã���� �Ѵ�
//N���� ����� M���� �ι����谡 �־����� �� ���
//�ش� ���谡 �ִٸ� 1, �ƴϸ� 0�� ����϶�


//dfs�� ����Ǵ� �Լ�. �� ������� ���谡 �ִ� ������� ã�� �����Ѵ�
//������ ���� ���谡 ���۵Ǵ� ��ȣ, ���� ���� Ž������ ��ȣ, ������ ���� ��, ���� üũ ���ΰ� ����� �迭�̴�
//tmp : ������� ����� ������ ���� �ǹ��Ѵ�. 4�� ���谡 �Ǹ� �۾��� �ߴ��ϰ� 1�� ����ϰ� �Ѵ�
void dfs(int start_idx, int now_idx, int stacks, int check[]) {
	for (int i = 0;i < friends[now_idx].size();i++) {
		if (check[friends[now_idx][i]] == 0) {
			check[friends[now_idx][i]] = 1;
			int tmp = stacks + 1;
			if (tmp == 4) {
				possible = 1;
				break;
			}
			dfs(start_idx, friends[now_idx][i], tmp, check);
			//dfs���� ���� check[friends[now_idx][i]]�� 0���� ������ start_idx������ Ž���� �� ��
			//�̹� start_idx���� �ٸ� ��Ʈ�� ����Ǵ� Ž������ ������ �ߺ�Ž���� �ϰ� �Ǵ� ��츦 ���� �� �ִ�
			check[friends[now_idx][i]] = 0;
			if (possible == 1) {
				return;
			}
		}
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0;i < M;i++) {
		int s, e;
		cin >> s >> e;
		friends[s].push_back(e);
		friends[e].push_back(s);
	}

	int idx = 0;
	while (possible == 0) {
		int checker[2002] = {};
		if (possible == 1) {
			break;
		}

		if (friends[idx].size() != 0) {
			checker[idx] = 1;
			dfs(idx, idx, 0, checker);
		}

		idx++;
		if (idx == N) {
			break;
		}
	}

	cout << possible << '\n';
	return 0;
}
