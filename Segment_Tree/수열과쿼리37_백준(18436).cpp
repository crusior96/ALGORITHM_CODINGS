#include <iostream>
#include <cmath>
#include<algorithm>
using namespace std;
long long int arr[100002];
long long int seg_jjak[400008];
long long int seg_hol[400008];

//어떠한 숫자들의 배열과 쿼리문이 있다고 가정하자
//쿼리문에는 3개의 종류가 있으며 각각 a와 b의 숫자를 입력하게 된다.
//1번 쿼리는 a번째 숫자를 b로 바꾸게 되고, 2번 쿼리는 a번째 숫자에서 b번째 숫자 사이의 짝수 갯수들을 출력하고
//3번 쿼리는 2번 쿼리와 비슷하지만 홀수 갯수들을 출력하게 된다
//해당 쿼리문들을 다 실행 가능하게끔 만들어라

//문제풀이에는 세그트리를 사용하게 됐는데, 짝수와 홀수 갯수를 각자 판단하기 위해 2개의 함수를 만들게 됐다
//로직을 조금만 더 잘 짤 수 있었다면 하나의 세그트리 배열을 사용해서 메모리 및 코드 길이를 줄일 수 있었을 것 같다

//짝수 체크용 세그트리에 대한 생성 함수
//짝수라면 seg_jjak에 1을, 아니라면 0을 저장한다
long long int init_jjak(int left, int right, int node) {
	if (left == right) {
		return seg_jjak[node] = (arr[left] + 1) % 2;
	}

	int mid = (left + right) / 2;
	
	return seg_jjak[node] = init_jjak(left, mid, node * 2) + init_jjak(mid + 1, right, node * 2 + 1);
}

//홀수 체크용 세그트리에 대한 생성 함수
//홀수라면 seg_hol에 1을, 아니라면 0을 저장한다
long long int init_hol(int left, int right, int node) {
	if (left == right) {
		return seg_hol[node] = arr[left] % 2;
	}

	int mid = (left + right) / 2;
	return seg_hol[node] = init_hol(left, mid, node * 2) + init_hol(mid + 1, right, node * 2 + 1);
}

//짝수의 갯수를 판단하는 함수
//세그트리를 탐색하면서 범위에 오류가 나지 않는 선에서의 seg_jjak 값들을 찾아내어 더해간다
long long int search_jjak(int left, int right, int node, int node_left, int node_right) {
	if (node_left > right || node_right < left) {
		return 0;
	}

	if (node_left >= left && right >= node_right) {
		return seg_jjak[node];
	}

	int mid = (node_left + node_right) / 2;

	return search_jjak(left, right, node * 2, node_left, mid) + search_jjak(left, right, node * 2 + 1, mid + 1, node_right);
}

//홀수의 갯수를 판단하는 함수
//세그트리를 탐색하면서 범위에 오류가 나지 않는 선에서의 seg_hol 값들을 찾아내어 더해간다
long long int search_hol(int left, int right, int node, int node_left, int node_right) {
	if (node_left > right || node_right < left) {
		return 0;
	}

	if (node_left >= left && right >= node_right) {
		return seg_hol[node];
	}

	int mid = (node_left + node_right) / 2;

	return search_hol(left, right, node * 2, node_left, mid) + search_hol(left, right, node * 2 + 1, mid + 1, node_right);
}

//숫자 갱신으로 인한 짝수의 갯수를 갱신하는 함수
//해당 부분에서 고생했었는데, 갱신을 한 다음 해당 부분을 중복적으로 처리하는 바람에 문제가 있었다
void update_jjak(int left, int right, int node, int idx, long long int dif) {
	if (idx<left || idx>right) {
		return;
	}

	if ((dif + 1) % 2 == 1) {
		seg_jjak[node]++;
	}
	else {
		seg_jjak[node]--;
	}

	if (left == right) {
		return;
	}
	int mid = (left + right) / 2;
	update_jjak(left, mid, node * 2, idx, dif);
	update_jjak(mid + 1, right, node * 2 + 1, idx, dif);
}

//숫자 갱신으로 인한 홀수의 갯수를 갱신하는 함수
void update_hol(int left, int right, int node, int idx, long long int dif) {
	if (idx<left || idx>right) {
		return;
	}
	
	if (dif % 2 == 1) {
		seg_hol[node]++;
	}
	else {
		seg_hol[node]--;
	}

	if (left == right) {
		return;
	}
	int mid = (left + right) / 2;
	update_hol(left, mid, node * 2, idx, dif);
	update_hol(mid + 1, right, node * 2 + 1, idx, dif);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N;

	for (int i = 1;i <= N;i++) {
		cin >> arr[i];
	}

	init_jjak(1, N, 1);
	init_hol(1, N, 1);


	cin >> M;

	for (int j = 0;j < M;j++) {
		int order;
		cin >> order;
		if (order == 1) {
			int index;
			long long int before, target;
			cin >> index >> target;
			before = arr[index];
			arr[index] = target;
			if (before % 2 == 0 && target % 2 == 0) {
				continue;
			}
			else if (before % 2 == 1 && target % 2 == 1) {
				continue;
				
			}
			else {
				update_jjak(1, N, 1, index, target);
				update_hol(1, N, 1, index, target);
			}
		}
		else if (order == 2) {
			int s, e;
			cin >> s >> e;
			cout << search_jjak(s, e, 1, 1, N) << '\n';
		}
		else if (order == 3) {
			int s, e;
			cin >> s >> e;
			cout << search_hol(s, e, 1, 1, N) << '\n';
		}
	}

	return 0;
}