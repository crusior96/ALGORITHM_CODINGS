#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int arr[100001] = {};

//용액(2467번) 문제와 유사한 상황이지만 주어지는 용액값은 오름차순으로 주어지지 않는다
//따라서 최대 10만개의 숫자들을 정렬하기 위해 퀵소트를 사용했다
//퀵소트는 (NlogN)의 시간복잡도를 가지고 있는 반면 일반적인 소트는 (N^2)의 시간복잡도를 가지고있다


//퀵소트를 사용하기 위해 만든 정렬함수
//이를 통해 오름차순으로 정렬할 수 있으며, return 1과 -1의 값만 바꿔두면 내림차순 정렬이 가능하다
int cmp(const void *a, const void *b){
	int num1 = *(int *)a;
	int num2 = *(int *)b;

	if (num1 > num2) {
		return 1;
	}
	else if (num1 < num2) {
		return -1;
	}
	else if (num1 == num2) {
		return 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, s_liquid, e_liquid;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}

	//입력받은 배열 arr에 대해 퀵소트 진행
	qsort(arr, N, sizeof(int), cmp);

	//최솟값 자체가 0 이상인경우엔 최솟값과 그 다음으로 작은 값 출력
	if (arr[0] >= 0) {
		cout << arr[0] << " " << arr[1] << '\n';
	}
	//최댓값 자체가 0 이하인 경우엔 최댓값과 그 다음으로 큰 값 출력
	else if (arr[N - 1] <= 0) {
		cout << arr[N - 2] << " " << arr[N - 1] << '\n';
	}
	//두 경우에 해당사항이 없는 경우 슬라이딩 기법 사용
	else {
		int s = 0;
		int e = N - 1;
		int mini = 2000000001;
		while (s < e) {
			int tmp = arr[e] + arr[s];
			tmp = abs(tmp);
			//두 용액 사이의 차이값이 정확히 0인경우엔 작업을 중단하며 두 용액을 바로 지정해버린다
			if (tmp == 0) {
				s_liquid = arr[s];
				e_liquid = arr[e];
				break;
			}
			else if (tmp < mini) {
				mini = tmp;
				s_liquid = arr[s];
				e_liquid = arr[e];
			}

			if (arr[s] + arr[e] < 0) {
				s++;
			}
			else if (arr[s] + arr[e] > 0) {
				e--;
			}
		}
		cout << s_liquid << " " << e_liquid << '\n';
	}

	return 0;
}