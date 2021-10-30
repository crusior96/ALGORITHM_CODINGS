#include<iostream>
#include<algorithm>
using namespace std;

int N;
int arr[500001] = {};		//정렬되지 않은 초기 상태의 숫자들
int arr2[500001] = {};		//입력된 숫자들을 오름차순으로 정렬함


//원래대로의 버블소트의 개념은, 인접한 수들을 비교해서 서로 위치를 바꾸는 방식으로 정렬이 진행된다
//이때의 버블소트는 숫자의 갯수만큼 무조건 loop하면서 이루어지게 된다
//그래서 보다 효율적인 버블소트 개념을 만들어서 더 이상 loop할 필요가 없는 상태면 강제종료하는 개선된 버블소트를만들었다
//N개의 숫자가 입력됐을 때, 몇번의 loop 이후에 개선된 버블소트가 종료되는지 구하여라


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int answer = -1;
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
		arr2[i] = arr[i];
	}

	sort(arr2, arr2 + N);


	//버블소트의 개념은 인접한 숫자들끼리 바꿔서 서로의 위치를 바꾸는 것
	//다만 버블소트의 진행방식을 보면 앞에 있는 큰 숫자는 1번의 루프만으로 꽤 이동하지만
	//작은 숫자인데 뒤에 있는 경우엔 현재 있는 위치와 정렬시 배치돼야 하는 위치의 차이만큼 loop해야 이동할 수 있다
	//이 부분에 착안하여 정렬됐을 때의 경우와 정렬되지 않은 초기 상태를 비교해서 loop를 제일 많이해야 하는 숫자를 기준삼으면 된다
	for (int i = 0;i < N;i++) {
		if (i - (lower_bound(arr2, arr2 + N, arr[i]) - arr2) > answer) {
			answer = i - (lower_bound(arr2, arr2 + N, arr[i]) - arr2);
		}
	}

	cout << answer << '\n';

	return 0;
}