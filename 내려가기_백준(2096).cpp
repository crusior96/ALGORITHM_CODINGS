#include<iostream>
#include<algorithm>
using namespace std;

int real_max[3] = {};
int real_min[3] = {};
int temp_max[3] = {};
int temp_min[3] = {};

//슬라이딩 윈도우를 이용한 문제풀이
//메모리 제한이 C랑 C++은 4MB였기 때문에 DP로 풀면 메모리부족에 걸릴 확률이 높다
//따라서 입력을 받아 저장하는곳을 현재까지 누적된 최대 & 최소값, 지금 입력된 값을 저장하는 곳으로 해둔다

int main() {
	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		for (int j = 0;j < 3;j++) {
			cin >> temp_max[j];
			temp_min[j] = temp_max[j];
		}

		if (i == 0) {
			for (int j = 0;j < 3;j++) {
				real_max[j] = temp_max[j];
				real_min[j] = temp_min[j];
			}
		}
		else {
			temp_max[0] += max(real_max[0], real_max[1]);
			temp_max[1] += max(real_max[0], max(real_max[1], real_max[2]));
			temp_max[2] += max(real_max[1], real_max[2]);
			temp_min[0] += min(real_min[0], real_min[1]);
			temp_min[1] += min(real_min[0], min(real_min[1], real_min[2]));
			temp_min[2] += min(real_min[1], real_min[2]);
		}

		for (int j = 0;j < 3;j++) {
			real_max[j] = temp_max[j];
			real_min[j] = temp_min[j];
		}
		
	}

	cout << max(real_max[0], max(real_max[1], real_max[2])) << " " << min(real_min[0], min(real_min[1], real_min[2])) << '\n';
	return 0;
}