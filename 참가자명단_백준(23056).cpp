#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int M, N;

int hak_stack[11] = {};		//hak_stack[i] : i��° �н��� �ִ� ����� ��. �ִ� N�� ���� ��������?

//�������� ������ �����ϱ� ���� ���� ����ü
struct human_info {
	int hak;
	string name;
};

vector<human_info> blue;	
vector<human_info> white;	//���� û��, ������ ���� �������� ������ ���ִ�

//����ü�� ���Ǵ޸� �񱳸� ���� ���� �Լ�
//�ַ� �б޹�ȣ�� �̸��� ����, ���������� �̸��� �������� ���ϰ� �ȴ�
bool comp(human_info h1, human_info h2){
	if (h1.hak > h2.hak) {
		return false;
	}
	else if (h1.hak == h2.hak) {
		if (h1.name.length() > h2.name.length()) {
			return false;
		}
		else if (h1.name.length() == h2.name.length()) {
			if (h1.name > h2.name) {
				return false;
			}
			else if (h1.name <= h2.name) {
				return true;
			}
		}
		else {
			return true;
		}
	}
	else {
		return true;
	}
}


//�ִ� 500������� �л����� ������ �Էµȴٰ� ��������
//�� �������� �ȸ�� ��û�ϰ��� �ϴ� �л����� ������ �ð�������� �Է��� ���̴�
//�л����� ���� �б��� ���� M���̸�, ������ ��ȣ�� 1 ~ M�� ��, Ȧ�� �� �б��� û��, ¦�� �� �б��� ������ �ȴ�
//���� ������ �б޿��� �ִ� N���� ���� �� ������ �̴� ���������� ���� �߸��� �ȴ�
//�ȸ ������ ��� ��� �� û���� �������� ���� ����ϰ�, �б��� �������� ����ؾ��ϸ�, �л� �̸��� ª�� �ͺ��� ����ϰ�, ���̰� ������ ���������� ����ؾ� �Ѵ�
//�ȸ ������ ����� ����϶�
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N;
	bool done = true;

	//�̷����� ������ ���� ����
	//�б޺��� �ִ� N���̱� ������ �ش� ������ hak_stack�� �����ؼ� �����Ѵ�
	//���� ���ǿ� �°� bool comp �Լ��� �̿��Ͽ� û���� �������� �������� sort�Ѵ�
	while (done) {
		int hk;
		string nam;
		cin >> hk >> nam;
		if (hk == 0 && nam == "0") {
			done = false;
			break;
		}
		else {
			if (hak_stack[hk] < N) {
				if (hk % 2 == 1) {
					human_info temp;
					temp.hak = hk;
					temp.name = nam;
					blue.push_back(temp);
					hak_stack[hk]++;
				}
				else if (hk % 2 == 0) {
					human_info temp;
					temp.hak = hk;
					temp.name = nam;
					white.push_back(temp);
					hak_stack[hk]++;
				}
			}
		}
	}

	sort(blue.begin(), blue.end(), comp);
	sort(white.begin(), white.end(), comp);

	for (int i = 0;i < blue.size();i++) {	
		{
			cout << blue[i].hak << " " << blue[i].name << '\n';
		}	
	}
	
	for (int i = 0;i < white.size();i++) {
		{
			cout << white[i].hak << " " << white[i].name << '\n';
		}
	}

	return 0;
}