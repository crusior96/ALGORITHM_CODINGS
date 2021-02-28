#include<iostream>
#include<string>
#include<set>
using namespace std;
set <int> numbers;
int temp_answer[6];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int num[5][5];

//���� ������ ������ DFS�������� set �ڷᱸ���� ó�� ����غ� ����
//set�� �ߺ��Ǵ� �ڷḦ �ڵ������� �ɷ��� �����Ѵ�
//������ �ڷᱸ���δ� map�� �ִ�
//5 * 5�� �������� �ְ� ������ ������ 6ĭ�� �����¿� �ƹ����Գ� �������� ����� �ִ� �ߺ����� �ʴ� ������ ������ ���Ͽ���


//������� �Էµ� �ӽü����� �ڸ����� ������ ���� ��ǥ
void DFS(int index, int x, int y) {
	if (index == 6) {
		//�� 6�ڸ��� �ԷµǸ� ������� ���ڸ� numbers �¿� �ִ´�
		int real_answer = temp_answer[0] * 100000 + temp_answer[1] * 10000 + temp_answer[2] * 1000 + temp_answer[3] * 100 + temp_answer[4] * 10 + temp_answer[5];
		numbers.insert(real_answer);
	}
	else if(index != 6){
		//6�ڸ��� ���� �ϼ����� �ʾҴٸ� �������� �����ʴ� ������ ��ǥ�� �̵��Ѵ�
		temp_answer[index] = num[x][y];
		if (x >= 1) {
			DFS(index + 1, x - 1, y);
		}
		if (x < 4) {
			DFS(index + 1, x + 1, y);
		}
		if (y >= 1) {
			DFS(index + 1, x, y - 1);
		}
		if (y < 4) {
			DFS(index + 1, x, y + 1);
		}
	}
}


int main() {

	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			cin >> num[i][j];
		}
	}

	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			DFS(0, i, j);
		}
	}

	cout << numbers.size();

	return 0;
}