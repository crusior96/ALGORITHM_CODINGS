#include<iostream>
#include<string>
using namespace std;
int primary[100001] = {};

//255���� ���ڵ�� �̷���� ���ڿ��� �־����ٰ� ��������
//�� ���ڿ��� �Ϻκ����� �������� ��, �ش� �κ��� ���� �Ҽ������� �����϶�
//������ ���ڿ��� ���� 0�� ���ö����� ����ǰ�, 0�� ������ �ȴٸ� �״�� �����Ѵ�
//��, �Ҽ��� ������ 2 �̻� 100000 ������ ������ �����Ѵ�


//���� Ǯ�̸� �ʹ� ��ư� �����ߴٴ� ����
//������ ����� ���� ���ߴٴ� ���� �¹����� ���� �ɷȴ�

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	bool done = true;

	//�����佺�׳׽��� ü ����
	primary[1] = 1;
	for (int i = 2;i <= 318;i++) {
		if (primary[i] == 1) {
			continue;
		}
		for (int j = i + i;j <= 100000;j += i) {
			primary[j] = 1;
		}
	}

	while (done) {
		int answer = 0;
		string S;
		cin >> S;

		//���ڿ� ���� 0�̸� ����
		if (S == "0") {
			break;
		}
		else {
			int curr_num;
			curr_num = 0;
			//���ڿ� ���̰� 1�� ��쿣 �ش� ���� �������� �Ҽ��� �����Ѵ�
			if (S.length() == 1) {
				int num_i = S[0] - '0';
				if (primary[num_i] == 0) {
					answer = num_i;
				}
			}
			else {
				//���ڿ��� ��� ������ �������� 1 ~ 5���� ���ڿ����� �κ������� �߷��� ����
				//�ش� �κ��� ���ڿ��� ���ڷ� �ٲپ��� ��, �켱������ 10�� ���������� �����Ѵ�
				//�� ���� �ش簪�� �Ҽ�����, �Ҽ��� �´ٸ� ���� �˰� �ִ� �Ҽ����� ū ������ �����ϰ� �����Ѵ�
				for (int i = 0;i < S.length();i++) {
					for (int j = 1;j <= 5;j++) {
						if (i + j == S.length() + 1) {
							break;
						}
						string tmp_s = S.substr(i, j);
						int num_i = stoi(tmp_s);
						if (num_i <= 100000) {
							if (primary[num_i] == 0) {
								if (answer == 0) {
									answer = num_i;
								}
								else if (answer < num_i) {
									answer = num_i;
								}
							}
						}
					}
				}
			}
			cout << answer << '\n';
		}
	}

	return 0;
}