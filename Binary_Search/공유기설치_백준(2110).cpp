#include<iostream>
#include<algorithm>
using namespace std;
int N, M;
int house[200001];

//N개의 집이 있다고 가정하자
//각각의 집에 공유기를 1개씩 설치해서 총 M개를 설치해야하는데 
//공유기를 설치한 집의 사이를 최대한 넓게해서 설치하고 싶다
//이때, 위의 조건에 맞게 공유기를 설치하게 된다면 그 때 적용된 최소한의 거리를 구하여라


//이진 탐색이 진행되는 함수, 집과 집 사이의 최소한 떨어져야 하는 거리를 idx라고 지정한다
//맨 앞의 집에 우선적으로 공유기를 설치한 상황이기 때문에 현재까지 설치된 공유기 값인 temp를 1로 지정한다
//이전에 설치된 지점을 기준으로 idx 이상만큼 떨어진 집의 좌표가 나온다면 해당 부분에 공유기를 설치한다
//이러한 방식으로 temp값이 M 이상이면 true, 아니면 false를 return한다
bool binary_search(int idx) {
	int temp = 1;
	int prev = house[0];
	for (int i = 1;i < N;i++) {
		if (house[i] - prev >= idx) {
			prev = house[i];
			temp++;
		}
	}

	if (temp >= M) {
		return true;
	}
	
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	for (int i = 0;i < N;i++) {
		cin >> house[i];
	}

	//이진 탐색을 사용하기 위해 집의 좌표들을 정렬한다
	sort(house, house + N);

	//이진 탐색을 위해 지정하는 초기 값들. 집과 집 사이에 나타날 수 있는 최대 & 최소 거리를 지정해준다
	int mini = 1;
	int maxi = house[N - 1] - house[0];
	int answer = 0;

	//이분탐색을 위한 변수를 제공하는 부분
	//최대한 넓은 구간을 지키기 위해 answer값을 max(answer, mid)로 지정하며 풀이를 진행한다
	while (mini <= maxi) {
		int mid = (mini + maxi) / 2;
		if (binary_search(mid)) {
			answer = max(answer, mid);
			mini = mid + 1;
		}
		else {
			maxi = mid - 1;
		}
	}
	cout << answer << '\n';
	return 0;
}