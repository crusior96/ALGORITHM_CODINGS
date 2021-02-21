#include<iostream>
#include<set>
using namespace std;
int primary[1000002] = {};

//��� ������ �ڸ������� ���� ��� �����ؼ�
//������ ���ڵ��� ���� �� �� ������ ���ϱ⸦ �ݺ��ؼ� 1�� ������ ��ټ���� �Ѵ�
//�̶�, ���ϱ⸦ �ݺ��ϴٰ� ������ ���� ���� ������ �Ǹ� ��ټ��� �ƴϴ�
//�̶� N������ ���ڰ� �־����ٸ� �Ҽ��̸鼭 ��ټ��� ���� ���Ͽ���


//������ 100�������̹Ƿ� �ش� �������� �Ҽ��� �Ǻ��صд�
//�Ҽ��� primary[i]�� 0, �ƴϸ� 1�� ����ȴ�
void sosu_time() {
	primary[1] = 1;
	for (int i = 2;i <= 1000;i++) {
		if (primary[i] == 1) {
			continue;
		}
		for (int j = i + i;j <= 1000000;j += i) {
			primary[j] = 1;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	sosu_time();

	int N;
	cin >> N;
	for (int i = 1;i <= N;i++) {
		//�Ҽ��� ��쿣 ��ټ� �Ǻ��� ����Ǹ� �̶� set �����̳ʰ� ���ȴ�
		//set�����̳ʴ� Ư������ ���� ���忩�θ� ���� �� ������ �����̳��̸� Ʈ�� �������� ����ȴ�
		if (primary[i] == 0) {
			set<int> sosu;
			bool done = true;
			int tmp = i;
			while (done) {
				int sang_tmp = 0;	//�� �ڸ������� ������ ������ ��
				int tmp2;
				while (tmp > 0) {
					tmp2 = tmp % 10;
					sang_tmp += (tmp2*tmp2);
					tmp = tmp / 10;
				}

				//���������� ��ټ��� �Ǻ��ȴٸ� �ش� i���� ����Ѵ�.
				if (sang_tmp == 1) {
					cout << i << '\n';
					done = false;
					break;
				}

				//sosu set�� �Էµ� ���� �ִٸ� while���� break, ���ٸ� sosu set�� �Է��Ѵ�
				if (sosu.count(sang_tmp) == 0) {
					sosu.insert(sang_tmp);
				}
				else if(sosu.count(sang_tmp) == 1) {
					done = false;
					break;
				}
				tmp = sang_tmp;

			}
		}
	}
	return 0;
}