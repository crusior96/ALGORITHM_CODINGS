#include<iostream>
#pragma warning(disable: 4996)
using namespace std;
unsigned long long int arr[1026][1026] = {};	//자연수들이 저장되어있는 좌표
unsigned long long int add_on[1026][1026] = {};	//(x,y)까지의 모든 범위내 좌표들의 합을 add_on[x][y]에 저장해둔다

//N*N의 배열 안에 각각 1000보다 작거나 같은 자연수들이 저장되어있다
//배열의 맨 왼쪽상단 좌표를 (1,1)이라 가정하였을때, Tc번의 케이스동안 (x1,y1)에서 (x2,y2)까지의 좌표값들의 총합을 구하여라
//이때 Tc는 100000 이하의 자연수이다


int main() {
	int N, Tc;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	scanf("%d %d", &N, &Tc);

	//현재 위치의 좌표를 add_on에 저장한 후, 왼쪽에 있는 좌표값을 바로 오른쪽으로 더해주는 연산을 해준다
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			scanf("%d", &arr[i][j]);
			add_on[i][j] += arr[i][j];
			add_on[i][j + 1] += add_on[i][j];
		}
	}

	//윗쪽에 있는 좌표값을 바로 아랫쪽으로 더해주는 연산을 해준다
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= N;j++) {
			add_on[i + 1][j] += add_on[i][j];
		}
	}


	for (int i = 0;i < Tc;i++) {
		unsigned long long int answer = 0;
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		//(x2,y2)까지의 숫자들을 모두 더한 후, (x1 - 1)(y2)와 (x2)(y1 - 1)까지의 숫자들을 빼준 후 중복되어 감산이 된 (x1 - 1)(y1 - 1)까지의 숫자들을 더해준다
		answer += add_on[x2][y2] - add_on[x1 - 1][y2] - add_on[x2][y1 - 1] + add_on[x1 - 1][y1 - 1];
		printf("%lld \n", answer);
	}
	return 0;
}