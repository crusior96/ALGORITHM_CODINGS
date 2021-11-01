#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

int R, C;
int answer = -1;
char name_str[1002][1002] = {};			//���ڿ� �迭�� 90�� ������ ���� ���� �ӽ� �迭
string name_list_real[1002] = {};		//���ڿ��� C * R�� ���·� �����ص� �迭


//������ ���ڿ����� 0��° ���ڿ��� e��° ���ڱ��� substr�� ������ ����
//�ش� ������ set �ڷᱸ���� �Է��ؼ� set �ڷᱸ���� size�� return �Ѵ�
//���� �ߺ��Ǵ� ���ڿ��� �־��ٸ� C���� ���� ���� return�� ���̴�
int string_search(int s, int e) {
	set<string> name_sets;

	for (int i = 0;i < C;i++) {
		string tmp = name_list_real[i].substr(0, e);
		name_sets.insert(tmp);
	}

	return name_sets.size();
}

//R * C�� ũ�⿡ ���ڿ��� ��ġ���ִٰ� ��������
//���ڿ����� ������ �Ʒ��� �о���ٰ� ��������. �׷��� �Ѵٸ� �� C���� ���ڿ��� ������� ���̴�
//�̶�, �� ������ ���ڿ��� ����� ���� �� ������� C���� ���ڿ� �� �ߺ��Ǵ� ���� ���ٸ� �� ������ ���ڿ��� ����������
//���� ���� ���ǿ��� �ߺ��Ǵ� ���ڿ��� �߰ߵȴٸ�, ������� ���� ���ڿ��� �� ������ ���Ͽ� ����Ѵ�

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> R >> C;
	for (int i = 0;i < R;i++) {
		for (int j = 0;j < C;j++) {
			cin >> name_str[R - i - 1][j];
		}
	}

	//R * C ������ ���ڿ��� ��ġ�� C * R�� ��ġ�� �ٲٴ� ����
	for (int i = 0;i < C;i++) {
		string tmp = "";
		for (int j = 0;j < R;j++) {
			tmp += name_str[j][i];
		}
		name_list_real[i] = tmp;
	}


	//C���� ���ڿ��鿡 ���� substr(0, R - i - 1)�� ������ ���ڿ��� �� �ߺ��Ǵ� ���ڿ��� �ִ��� ������ üũ ����
	//���� �ߺ��Ǵ� ���� �ִٸ� return���� tmp�� C���� ���� ���̴�
	for (int i = 0;i < R - 1;i++) {
		int tmp = string_search(0, R - i - 1);

		if (tmp < C) {
			answer = i;
			break;
		}
	}

	if (answer < 0) {
		cout << R - 1 << '\n';
	}
	else {
		cout << answer << '\n';
	}

	return 0;
}

