#include<iostream>
#include<vector>
#include<utility>
using namespace std;
int N;

//���� �� ������ ���� ���¸� ������ vector
vector<int> island[123460];

//DFS�� �����ϴ� �Լ� �κ�
//���������� ���� ���� �� & ������� �������� �� ������, ���� ���� ��ġ�� ������ �ȴ�
//return ������ �� ��ġ���� ������ �� �ִ� ���� �������̴�
long long int DFS_SW(vector<pair<char, int>> &lands, int curr) {
	//curr�� ��ġ���� ���ư� �� �ִ� �ٸ� ������ ����
	int siz = island[curr].size();

	//curr�� ��ġ�� �ܸ� ����� ���
	//�ش� ��ġ�� ���������� �� ��ŭ�� ���ڸ�, ������ 0�� return�Ѵ�
	if (siz == 0) {
		if (lands[curr].first == 'S') {
			return lands[curr].second;
		}
		else {
			return 0;
		}
	}

	//�ܸ������� �̾����� ��, ���� �� �ִ� �ִ� ���� ������
	long long int now = 0;

	//Ž���� �̷���� ���� ��ġ�� ���� next�� ������ ��, �ش� ������ �Բ� DFS_SW�� ��� �����Ѵ�
	for (int i = 0;i < siz;++i) {
		int next = island[curr][i];
		now += DFS_SW(lands, next);
	}

	//Ž���� ������ ��, ����� �ؼ� ������ �ȴٸ�, 0���� �������ѹ�����
	//���̶� �Ѵٸ� ����� �ٲ㼭 ���� ���۽�Ų��
	if (lands[curr].first == 'W') {
		now -= lands[curr].second;
		if (now < 0) {
			now = 0;
		}
	}
	else {
		now += lands[curr].second;
	}
	return now;
	
}

//N���� ���� �ִٰ� ��������. ���� 1 ~ N�� ��ȣ�� ������ �ִ�
//��� ������ ��Ե� 1�� ������ ���ϴ� ���� �ְ�, 1�� ������ �����ϴ� ���� �������� ���ϰ����Ѵ�
//������ ������ ��� ���밡 �ְ�, ����� ���� ���� ���� �ﰢ������ �԰� �ȴ�
//������, ����� ������ ��ġ��ŭ ���� ������ �� ���ķ� �ȸԴ´�
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	//���� ��ġ�� ���� ������ ��������, �� ��ü���� ������ ������ vector
	vector<pair<char, int>> islands(N + 1);
	islands[1] = make_pair('S', 0);

	for (int i = 2;i <= N;i++) {
		char species;
		int num;
		int parent;
		cin >> species >> num >> parent;
		islands[i] = make_pair(species, num);
		island[parent].push_back(i);
	}

	
	cout << DFS_SW(islands, 1) << '\n';
	return 0;
}