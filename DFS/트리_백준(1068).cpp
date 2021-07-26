#include<iostream>
#include<vector>
using namespace std;
int parents[52] = {};	//parents[i] : i��° ����� parent�� ����Ǵ� �κ�
int N;

//N���� ������ �־����� ��������. ������ ������ 0�������� (N - 1)�� �������� ��ȣ�� �ο��޴´�
//�� ���� ������ ������ parent�� ��� �� ��� ��ȣ�� �Է��� �ȴ�
//parent�� ���� ��� �� root ����� -1�� �Է��Ѵ�
//�̶�, � �� ��带 ���شٰ� �����ϸ� �� �ؿ� �ִ� ���鵵 ��� ������� �Ǵµ�
//�� �۾��� �� ������ ���� ������ ��� ���Ͽ���

//��带 �����ϴ� DFS �Լ�
//�ο����� now_node���� parent�� ������ ��尡 �ִٸ� erase_dfs�� �ش� ��� ��ȣ�� now_node�� �ο��Ѵ�
//�� ���� ��͸� �̷��鼭 ��尡 ���ŵƴٴ� �ǹ̷� parent�� -100���� �����Ѵ�
void erase_dfs(int now_node) {
	for (int i = 0;i < N;i++) {
		if (parents[i] == now_node) {
			erase_dfs(i);
			parents[i] = -100;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0;i < N;i++) {
		int tmp;
		cin >> tmp;
		parents[i] = tmp;
	}
	int eraser;
	cin >> eraser;

	//�ʱⰪ���� parents[eraser]�� -100���� �����Ѵ�
	erase_dfs(eraser);
	parents[eraser] = -100;

	int answer = 0;

	//N���� ���� �� ���� ����� �͵��� �Ǵ��ϴ� �ݺ���
	//�θ� ��尡 �ƹ�ư���� �ְų� ������ ���ʿ� root ����� ���
	//�ڱ� �ڽ��� parent�� ������ �ٸ� ��尡 �ִٸ� �ش� ���� ���� ��尡 �ƴϰ� �ȴ�
	//�� �ݴ��� ��쿡�� ���� ������� Ȯ������ �� �ְԵȴ�
	for (int i = 0;i < N;i++) {
		bool isit = true;
		if (parents[i] >= -1)
		{
			for (int j = 0;j < N;j++) {
				if (parents[j] == i) {
					isit = false;
					break;
				}
			}
		}
		else if (parents[i] < 0) {
			isit = false;
		}

		if (isit == true) {
			answer++;
		}
	}
	cout << answer << '\n';
	return 0;
}