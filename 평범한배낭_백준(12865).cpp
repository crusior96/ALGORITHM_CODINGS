#include<iostream>
#include<algorithm>
using namespace std;
int items[101][100001] = {};	//물건의 현재까지 담은 갯수 및 총무게	
int value[101] = {};			//물건 가치
int weight[101] = {};			//물건 무게
int num, max_weight;

//num개의 물건이 존재한다고 가정하자. 각각의 물건에는 가치와 무게가 부여되어진다.
//어떤 가방에 들고갈 수 있는 물건의 최대 무게값이 max_weight일때, 최대한 들고갈 수 있는 물건의 가치는 얼마인가?

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);


		cin >> num >> max_weight;
		for (int j = 1;j <= num;j++) {
			cin >> weight[j] >> value[j];
		}

		//DP를 사용하여 문제를 푸었다.
		//시간복잡도는 O(MN)
		for (int j = 1;j <= num;j++) {
			for (int k = 1;k <= max_weight;k++) {
				//물건을 가져가지 않았을 경우의 총가치상태를 미리 저장해둔다
				items[j][k] = items[j - 1][k];

				//가방이 물건을 가지고 갈 수 있는 상황인경우
				if (k - weight[j] >= 0) {
					//물건을 안 가져갔을때와 물건을 가져갔을 때의 상태를 비교하여 최대값을 저장해준다
					items[j][k] = max(items[j][k], items[j - 1][k - weight[j]] + value[j]);
				}
			}
		}

		cout << items[num][max_weight] << '\n';
	
	return 0;
}
