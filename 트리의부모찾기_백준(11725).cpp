#include<iostream>
#include<vector>
using namespace std;

int parent[100002] = {};		//������ ��忡 ���� parent���� ����Ǵ� ��
bool visited[100002] = {};		//Ž���� ����� ��
vector<int> tree[100002];		//�������� ����Ǵ� ��

//1�� ��尡 Ʈ���� ��Ʈ��� ��������
//N���� ��尡 �����ϰ� N-1���� ��Ʈ�� �Էµɶ� ������ ����� �θ� ����϶�


//���� parentfinder ���� ���� ��尪���� parent�� ���� ��, parentfinder �Լ��� ����ϴ� �������� �̷������
//��, �̹� parent���� ������ ��尪�� ��쿡�� ��������
void parentfinder(int currNode) {
	visited[currNode] = true;

	for (int i = 0;i < tree[currNode].size();i++) {
		int nextNode = tree[currNode][i];

		if (visited[nextNode] == false) {
			parent[nextNode] = currNode;
			parentfinder(nextNode);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0;i < N - 1;i++) {
		int start, end;
		cin >> start >> end;
		//���� ������ parent�̰� ������ child���� �𸣴� ��Ȳ�̱� ������
		//��������� �Է����ش�
		tree[start].push_back(end);
		tree[end].push_back(start);
	}

	parentfinder(1);

	for (int i = 2;i <= N;i++) {
		cout << parent[i] << '\n';
	}

	return 0;

}