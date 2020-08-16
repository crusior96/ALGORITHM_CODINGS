#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int arr[100001] = {};		//용액들의 성분이 저장된 배열

//N개의 용액들이 있다고 가정하자. 각각의 용액들은 음수와 양수들의 산성 알칼리성 용액으로 이루어져있다
//용액들중 2개의 용액을 합쳐서 0에 제일 가까운, 혹은 0을 만들 수 있는 한 쌍의 용액을 구하고자한다
//입력이 오름차순으로 주어졌을때, 조건에 해당하는 한 쌍의 용액을 구하여라

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, s_liquid, e_liquid;
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> arr[i];
	}


	//처음 입력받은 용액이 0 이상이면 바로앞의 두 용액을
	//마지막에 입력받은 용액이 0 이하이면 맨 뒤의 두 용액을 지정한다
	if (arr[0] >= 0) {
		cout << arr[0] << " " << arr[1] << '\n';
	}
	else if (arr[N - 1] <= 0) {
		cout << arr[N - 2] << " " << arr[N - 1] << '\n';
	}
	//그렇지 않다면 슬라이딩윈도우 기법을 사용한다
	//시작점과 끝점은 각각 배열의 시작부분과 끝부분이다
	//처음엔 s와 e를 둘 다 왼쪽에서 시작하게 만들었는데 그러다보니 놓치는게 많아졌다
	else {
		int s = 0;
		int e = N - 1;
		int mini = 2000000001;	//액체쌍이 가질 수 있는 최소의 용액성분값

		//s와 e가 같은 값이 되기전까지 진행한다
		while (s < e) {
			//tmp : s와 e번쨰 용액을 합쳐만든 용액의 성분상태
			int tmp = arr[e] + arr[s];
			tmp = abs(tmp);
			//0이면 바로 break하고 최솟값이면 mini를 tmp로 대체한다
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
			
			//오름차순으로 정렬돼있다는 성질을 이용하여
			//용액값의 합이 0보다 작으면 작은 값의 용액을 한단계 높은 값으로 올리고
			//0보다 크면 큰 값의 용액을 한단계 낮은 값으로 내린다
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