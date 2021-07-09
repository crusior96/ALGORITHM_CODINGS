#include<iostream>
#include<algorithm>
using namespace std;

//N개의 숫자들이 있다고 가정하자
//N개의 숫자들 중 특정 숫자 1과 숫자 2를 더했을 때, 해당 값이 N개의 숫자들 중 다른 수라면 좋은 숫자다
//수의 위치가 다르다면 다른 수라고 판정한다
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int answer = 0;
	int N;
	int arr[2001] = {};
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}

	//투 포인터와 슬라이드 윈도우를 사용하기 위해 배열 내 숫자들 정렬
	sort(arr, arr + N);
	for (int i = 0;i < N;i++) {
		//N개의 숫자들이 과연 조건에 맞는 숫자인지 테스트해본다. 각각의 숫자들은 value에 저장된다.
		int value = arr[i];
		int l = 0;
		int r = N - 1;
		while (l < r) {
			int tmp = arr[l] + arr[r];
			//문제가 제시한 조건은 2가지이다
			//1. 서로 다른 수를 더한 결과값이 N개의 숫자들 중 하나인가
			//2. 결과값을 만들 때 쓰인 숫자들은 결과값이 배치된 위치와는 다른 곳인가
			//2개 조건을 모두 만족하면 정답 중 하나이지만, 투 포인터 중 작은 값이나 큰 값이 결과값이 배치된 위치와 같다면 
			//포인터 위치를 변경해준다.
			if (tmp == value) {
				if (l != i && r != i) {
					answer++;
					break;
				}
				else if (l == i) {
					l++;
				}
				else if (r == i) {
					r--;
				}
			}
			//그외에도 합한 값이 value보다 작거나 크면 그때에 따라 포인터들의 값을 조정한다.
			else if (tmp < value) {
				l++;
			}
			else {
				r--;
			}
		}
	}
	cout << answer << '\n';
	return 0;
}