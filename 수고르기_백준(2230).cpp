#include<iostream>
#include<algorithm>
using namespace std;
int num[100003] = {};	//숫자들 저장되는 배열

//N개의 숫자로 이루어진 숫자들이 있다 가정하자
//각각의 숫자들이 이룰 수 있는 숫자쌍들이 만들 수 있는 차이들 중
//M 이상이면서 제일 작은 차이의 값을 구하여라
//투 포인터 알고리즘을 이용한 문제풀이
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, M;
	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		cin >> num[i];
	}
	//어차피 모든 숫자쌍의 차이값을 알아낼꺼니까 정렬
	sort(num, num + N);
	int s = 0;
	int e = 0;				//각각 슬라이드 윈도우의 시작과 끝점을 나타낸다
	int temp_answer = 0;	//임시적으로 나타내는 num[e]와 num[s]의 차이값
	int answer = 0;			//문제조건을 만족하는 답

	while (e < N && s < N) {
		//슬라이드 윈도우 가동시의 조건들
		//1. M 미만의 차이를 보여주는 숫자쌍이라면
		//1.1. 일반적으로는 e의 값을 1 늘리고 temp_answer값을 바꾼다
		//1.2. 하지만 e가 1 늘어나서 인덱스를 초과한다면 s를 늘리고 temp_answer값을 바꾼다
		if (temp_answer < M) {
			if (e > N) {
				s++;
				temp_answer = num[e] - num[s];
			}
			else {
				e++;
				temp_answer = num[e] - num[s];
			}			
			continue;
		}

		//2. M 이상의 차이를 보여주는 숫자쌍이라면
		//answer변수내에 숫자입력 이력이 없었다면 바로 입력하고
		//숫자입력 이력이 있다면 answer 미만의 숫자인 경우에 answer에 삽입한다.
		if (temp_answer >= M) {
			if (answer == 0) {
				answer = temp_answer;
			}
			else if (answer != 0) {
				if (answer > temp_answer) {
					answer = temp_answer;
				}
			}
			
		}
		//조건을 만족하여 temp_answer의 값이 변하게 됐을경우에 s값을 늘리고 temp_answer값을 바꾼다
		s++;
		temp_answer = num[e] - num[s];
	}
	cout << answer << '\n';
	return 0;
}