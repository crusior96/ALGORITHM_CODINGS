#include<iostream>
#include<vector>
#include<stack>
#include<utility>
using namespace std;

int num[1000001] = {};			//오큰수 값이 최종적으로 저장되는 배열
stack<pair<int, int>> obigsu;	//오큰수 값들을 찾기위해 일부 정보들이 저장되는 스택.
								//<입력한 숫자, 숫자의 위치>가 저장된다

//N개의 번호들이 있다고 가정하자
//오큰수라는 숫자가 있는데 이 숫자는 자신을 기준으로 해서 오른쪽에 있는 숫자들 중
//큰 숫자들 중에 제일 왼쪽에 있는 숫자들을 의미한다
//이때, 나열된 N개의 번호들에 대해서 각각의 오큰수들을 구하여라
//단, 오큰수를 찾을 수 없는 경우에는 -1을 출력한다

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		num[i] = -1;
	}

	//사용한 알고리즘 및 자료구조는 모노톤 스택(Monotone Stack)이다
	//항상 스택의 상태를 오름차순으로 유지시켜주는 알고리즘이다
	for (int i = 0;i < N;i++) {
		int temp;
		cin >> temp;
		//오큰수 스택이 비어있지 않는경우
		while (obigsu.empty() == false) {
			//지금 입력한 값이 현재 오큰수 top()에 위치한 숫자값보다 큰 경우
			//현재 오큰수의 top()에 위치한 위치 정보를 토대로 num[위치]에 temp를 저장한다
			if (temp > obigsu.top().first) {
				num[obigsu.top().second] = temp;
				obigsu.pop();
			}
			else {
				break;
			}
		}
		obigsu.push(pair<int, int>(temp, i));
	}

	for (int i = 0;i < N;i++) {
		cout << num[i] << " ";
	}

	return 0;
}
