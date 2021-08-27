#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

//��� �迭�� �־����ٰ� ��������
//�迭�� ������ ����� R�� �迭�� �� �� ���� �����ϴ� D�� ���ڿ� ���·� �����ȴ�
//���� �迭�� ����ִµ� D ����� �����Ϸ� �Ѵٸ� error ���ڿ��� ����ϰ� �ȴ�
//�ʱ� �迭 ���µ� ���ڿ��� �־�����, [����,����,����,����]�� ���� ������� �־�����
//����� �� �����ϰ� �ȴٸ� �� ������� ����ϵ�, �ʱ⿡ ����� ��Ŀ� ���缭 ����ؾ� �Ѵ�
//�迭�� ũ��� ��ɾ��� ���̴� �� �� 1 �̻� 100000�����϶� �ش� ����� ������ ������� ����϶�

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int Tc;
	cin >> Tc;
	for (int i = 0;i < Tc;i++) {
		string numbers, orders;		//���� �߰�ȣ�� ���Ե� �迭�� ��ɾ� ���ڿ��� �ǹ��Ѵ�
		cin >> orders;
		int num;
		cin >> num;

		//�ʱ� �迭 ���¸� �Է��� ����, �迭 ���� �ִ� ���ڵ��� �����س��� ���
		//�� �������� �Ľ̿� ���� ������ char* �� string���� ��ȯ ������ �� �� �־���
		cin >> numbers;
		numbers = numbers.substr(1,numbers.length() - 2);				//�� �հ� �� �� ���ȣ ���� �۾�
		vector<char> numbers_before(numbers.begin(), numbers.end());	//strtok �Լ��� ����ϱ� ���� �ڷ� ����
		numbers_before.push_back('\0');									//���ڿ��� ���̶�� �ǹ̷� '\0' �Է�
		char* temp1 = &*numbers_before.begin();							//����� ������ ���������� temp1�� �����Ѵ�
		char* ptr = strtok(temp1, ",");									//���� ','�� �������� ���ڿ����� �и��س���

		//preorder�� �������� ����, postorder�� �ݴ������ �����̴�
		//���� ���� �ϳ� ������ reverse �Լ��� �����ϴ��� �ʱ⿡ ���Ͱ��� 2�� �����δ°� ���ϴ�
		//postorder�� �켱 ������ ����, preorder�� postorder�� �ִ� ���� reverse�Ͽ� �����صд�
		vector<int> numbers_preorder;
		vector<int> numbers_postorder;
		while (ptr != NULL) {
			int num_temp = stoi(ptr);
			numbers_postorder.push_back(num_temp);
			ptr = strtok(NULL, ",");
		}
		numbers_preorder = numbers_postorder;
		reverse(numbers_postorder.begin(), numbers_postorder.end());

		int pre_cnt = 0;		//������ ���Ϳ��� �տ������� ���ŵ� ����
		int post_cnt = 0;		//�ݴ���� ���Ϳ��� �տ������� ���ŵ� ����
		int status = 0;			//���� ���� ���°� ���������� �ݴ�������� �˷��ִ� ��
								//0�̸� ������, 1�̸� �ݴ������ ��Ȳ�̴�
		int bad_status = 1;		//���� �迭�� �� ��Ȳ���� D ����� ��������� bad_status�� 0���� �����Ѵ�
		for (int j = 0;j < orders.length();j++) {
			//R ��ɾ� : ����ȸ��
			if (orders[j] == 'R') {
				status++;
				status %= 2;
			}
			else if (orders[j] == 'D') {
				//�迭 ũ�Ⱑ ��ǻ� 0�� ��Ȳ�ε� D ����� ����Ǵ� ���
				if (pre_cnt + post_cnt == numbers_preorder.size()) {
					cout << "error" << '\n';
					bad_status = 0;
					break;
				}
				//�׷��� �ʴٸ�, ���� ������ �������� cnt���� �÷��ش�
				else if (pre_cnt + post_cnt < numbers_preorder.size()) {
					if (status == 0) {
						pre_cnt++;
					}
					else if (status == 1) {
						post_cnt++;
					}
				}
			}
		}

		//�ش� ����� bad_status���� 1�� ��쿡�� �����
		if (bad_status == 1) {
			//��ɸ����� �����ϰ� �� �迭�� ������� ���
			if (pre_cnt + post_cnt == numbers_preorder.size()) {
				cout << "[]" << '\n';
			}
			else {
				//�迭�� ���� �����ִ� ���, ��Ŀ� �°� ���� ����س���
				//status ���¿� ���� ��¿� ������ ���� �迭�� ������ ����
				//������ ���� �޸��� �Բ� ������� �ʰ� ���ȣ�� ����Ѵ�
				if (pre_cnt + post_cnt < numbers_preorder.size()) {
					cout << "[";
					if (status == 0) {
						for (int j = pre_cnt;j < numbers_preorder.size() - post_cnt - 1;j++) {
							cout << numbers_preorder[j] << ",";
						}
						cout << numbers_preorder[numbers_preorder.size() - post_cnt - 1];
					}
					else if (status == 1) {
						for (int j = post_cnt;j < numbers_postorder.size() - pre_cnt - 1;j++) {
							cout << numbers_postorder[j] << ",";
						}
						cout << numbers_postorder[numbers_postorder.size() - pre_cnt - 1];
					}

					cout << "]";
				}
				cout << '\n';
			}
		}


	}
	return 0;
}