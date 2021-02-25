#include<iostream>
#include<algorithm>
using namespace std;
int memo[101];				//���õ��� �޸� �뷮�� ����Ǵ� �迭
int candi[101];				//���õ��� On Off ����� ����Ǵ� �迭
int total[101][10001];		//total[i][j] : i��° �� �� j��ŭ�� �޸𸮸� Ȯ�������� ��� �ִ���

//N���� ������ ����Ǵ� ��� M �̻��� �޸𸮸� Ȯ���ϰ��� �Ѵ�
//�̶�, i��° ������ memo[i]�� �޸𸮸� ������ �ְ� ������ Ű�ų� ������ ����� candi[i]�̴�
//�׷��ٸ� �ּ����� ������� M �̻��� �޸𸮸� Ȯ���ϴ¹��� ���Ͽ���

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		cin >> memo[i];
	}
	for (int i = 0;i < N;i++) {
		cin >> candi[i];
	}

	int answer = 100000001;
	total[0][candi[0]] = memo[0];

	for (int i = 1;i < N;i++) {
		for (int j = 0;j <= 10000;j++) {	
			//������ ���õ鿡 ���� i��° ������ ��Ȱ��ȭ ��ų���� Ȱ��ȭ ��ų���� ���¸� ���Ͽ�
			//max���� total[i][j]�� �����Ѵ�
			if (j - candi[i] >= 0) {
				total[i][j] = max(total[i][j], total[i - 1][j - candi[i]] + memo[i]);
			}	
			total[i][j] = max(total[i][j], total[i - 1][j]);

			//M �̻��� �޸𸮸� Ȯ���� ��Ȳ�ΰ��
			//���� ���±��� �Ҹ��� ��밪�� answer ������ min���� answer�� �����Ѵ�
			if (total[i][j] >= M) {
				answer = min(answer, j);
			}
		}
	}

	cout << answer << '\n';

	return 0;
}