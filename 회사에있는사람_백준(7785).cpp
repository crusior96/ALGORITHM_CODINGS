#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;

//ȸ���� N���� ���Ա���� �ִٰ� ��������
//N���� ���Ա�� ������ ȸ�翡 ������ ����� �̸� �� ���Ի��°� ����ɶ�
//�������� ȸ�翡 �����ִ� ����� �̸����� ���������� ����϶�

//map �ڷᱸ���� ������ �̿��� ����Ǯ��
//map�� ���� : <key��, value��>
//map�� Ư¡ : key���� �������� �ڵ� ���ĵǸ� key���� �ߺ����� �ʴ´�
//map �ڷᱸ���� pair�� ����Ǹ� ���ó�� ���� ���԰� ���ÿ� �����ϰų� �������� ���԰� ������ ������ ����Ѵ�


map<string, bool>company;		//ȸ�翡 �� ������� ���� ���¸� �����Ѵ�
vector<string> names;			//���� ȸ�翡 �ִ� ������� �̸��� �����Ѵ�
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		string s1, s2;
		cin >> s1 >> s2;
		//���� company���� ������� ����� �����ִٸ�
		//s2���� ���ο����� ȸ�系�� ���Ҵ��� �ƴ����� �����Ѵ�
		if (company.count(s1)) {
			if (s2 == "enter") {
				company[s1] = true;
			}
			else if (s2 == "leave") {
				company[s1] = false;
			}
			continue;
		}
		names.push_back(s1);
		company[s1] = true;
	}

	//ȸ�翡 �־��� ������� �̸��� ������������ �����Ѵ�
	sort(names.begin(), names.end(), greater<string>());

	//ȸ�系�� �����ִ� ����鿡 ���ؼ� �̸� ���
	for (int i = 0;i < company.size();i++) {
		if (company[names[i]]==true) {
			cout << names[i] << "\n";
		}
	}

	return 0;
}