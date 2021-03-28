#include<iostream>
#include<algorithm>
using namespace std;
int chu[1002] = {};

//N개의 저울추가 있다고 가정하자. 각각의 저울추에는 각자의 무게가 부여돼있으며 중복도 가능하다
//이때, 이 저울추들을 골고루 사용해도 만들 수 없는 무게들 중 최솟값을 구하여라

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> chu[i];
	}

	//완전 탐색을 사용하려했으나 생각한 대로 했다면 시간초과 아니면 메모리 초과가 날 것 같았다
	//그래서 약간 구글링해보니 수학적인 요소(귀납법)가 있었으며 이부분 알아두면 다른곳에서 잘 쓸것같다
	
	sort(chu, chu + N);
	int sum = 0;		//해당 값 까지는 무게추로 어떻게든 만들 수 있다는 뜻. 
	//이번에 입력 할 무게추의 값이 sum + 1보다 큰 경우, sum + 1이 답안이 된다
	//ex) sum = 5인데 이번에 추가되는 무게추가 6이면 6, 6 + 1, 6 + 2 ... , 6 + 5까진 구현가능하지만
	//7이 추가가 된다면 6을 못 만들기 때문에 6이 정답이 되는 것.
	for (int i = 0;i < N;i++) {
		if (chu[i] <= sum + 1) {
			sum += chu[i];
		}
		else {
			break;
		}
	}

	cout << sum + 1 << '\n';
	return 0;
}