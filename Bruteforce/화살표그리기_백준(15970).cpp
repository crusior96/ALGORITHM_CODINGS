#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
vector<int> mapdot[5005];			//mapdot[i] : i�� ������ ���� ������ ��ǥ ��ġ�� ����Ǵ� ��
vector<pair<int, int>> dot_idx;		//������ ������ ����Ǵ� ��

//N���� ���� ���� ��ǥ���� ���´ٰ� ��������
//���� �ش� ���� ��ġ�� ���� ������ �������ְ� �ǰ� �������� �ְԵȴ�
//������ �ڽ� �αٿ� ���� ����� ���� ȭ��ǥ�� �̷�� �ȴ� ������ ��
//�׷��� ��������� ȭ��ǥ���� ������ ���� ���Ͽ���

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	int answer = 0;
	cin >> N;
	for (int i = 1;i <= N;i++) {
		int idx, color;
		cin >> idx >> color;
		dot_idx.push_back({ idx,color });
	}

	//���� �������� ���� ��ġ�� �������� �����Ѵ�
	sort(dot_idx.begin(), dot_idx.end());

	//���� ������� �������� �ش� ������ ���� ������ ��ġ�� �����Ѵ�
	//�̶� ������ ���� ��ġ�� ���ĵƱ� ������ mapdot[�������ȣ]�� ����Ǵ� ��ǥ���� ���������� �ȴ�
	for (int i = 0;i < N;i++) {
		mapdot[dot_idx[i].second].push_back(dot_idx[i].first);
	}

	//ȭ��ǥ�� ���̸� ���ϱ� ���� �κ�
	//Ư�� ������ ���� ������ ������ 2�� �̻��̾�߸� ȭ��ǥ�� ������ �� �ִٴ� ����
	//���� ��ġ�� �ش� �� �׷��� �� ������ �� �������� ���󼭵� �ٸ� ������ ����Ѵ�
	for (int i = 1;i <= N;i++) {
		if (mapdot[i].size() > 1) {
			for (int j = 0;j < mapdot[i].size();j++) {
				if (j == mapdot[i].size() - 1) {
					answer += mapdot[i][j] - mapdot[i][j - 1];
				}
				else if (j == 0) {
					answer += mapdot[i][j + 1] - mapdot[i][j];
				}
				else {
					answer += min(mapdot[i][j + 1] - mapdot[i][j], mapdot[i][j] - mapdot[i][j - 1]);
				}
			}
		}
	}

	cout << answer << '\n';
	
	return 0;
}