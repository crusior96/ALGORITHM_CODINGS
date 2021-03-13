#include<iostream>
#include<vector>
#include<stack>
#include<utility>
using namespace std;

int num[1000001] = {};		//숫자들이 입력되는 배열
int arr[1000001] = {};		//각각의 위치에 대한 오등큰수 값을 저장한다
int cnt[1000001] = {};		//숫자들이 언급된 빈도를 저장한다
stack<int> obiksu;

//N개의 숫자들이 있다고 가정하자
//오등큰수라는 숫자란, 현재 위치를 기준으로 오른쪽에 있는 숫자들 중
//현재 위치의 숫자보다 언급이 더 많이 된 숫자들 중 제일 왼쪽에 있는 숫자들을 뜻한다
//이때 N개의 숫자들에 대한 오등큰수들을 각각 출력하라
//단, 오등큰수 값을 판단할 수 없는 상황이라면 -1을 출력한다


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> num[i];
		cnt[num[i]]++;
	}

	//초기값 지정
	cnt[0] = 10000007;
	obiksu.push(0);

	//사용한 알고리즘 및 자료구조는 모노톤 스택이다
	//항상 스택의 정렬 상태를 오름차순으로 유지시켜 주는 알고리즘이며 시간복잡도는 O(N)으로 생각보다 효율적이다
	for (int i = N - 1;i >= 0;i--) {
		//현재 스택내에 있는 top()값의 출연빈도가 현재 위치의 출연빈도보다 낮다면 pop()
		while (cnt[obiksu.top()] <= cnt[num[i]]) {
			obiksu.pop();
		}

		//그렇게 최종적으로 스택내에 있는 top()값의 출연빈도가 현재 위치의 출연빈도보다 높은 경우
		//만약 해당 출연빈도가 앞에서 지정한 초기값이라면 arr에 -1을 저장한다
		//그렇지 않다면 현재 스택내에 있는 top()값을 arr에 저장한다
		if (cnt[obiksu.top()] >= 10000007) {
			arr[i] = -1;
		}
		else {
			arr[i] = obiksu.top();
		}

		obiksu.push(num[i]);
	}

	for (int i = 0;i < N;i++) {
		if (arr[i] == 0) {
			cout << -1 << " ";
		}
		else {
			cout << arr[i] << " ";
		}
	}

	return 0;
}