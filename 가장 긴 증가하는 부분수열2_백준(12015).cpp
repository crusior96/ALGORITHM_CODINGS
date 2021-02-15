#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//LIS 알고리즘을 사용하고 싶었지만 주어진 범위가 너무 길어서 O(N^2)의 시간복잡도일경우 시간초과가 난다
//따라서 이번엔 lower_bound를 활용한 이분탐색을 곁들여서 시간복잡도를 줄여야했다

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num;
	int answer = 0;
	vector<int>LIS; //증가하는 최장 부분수열이 저자오디어지는 벡터
	LIS.push_back(0);	//최솟값을 우선적으로 넣어준다
	cin >> num;
	for (int i = 0;i < num;i++) {
		int temp;
		cin >> temp;
		//입력받은 숫자가 LIS내의 최댓값보다 크다면 LIS의 최댓값으로 지정해주고 길이++
		//그렇지 않다면 입력받은 값이 LIS위치내에 어디에 해당하는지 확인 후, 그 값이랑 교체해준다
		//교체함을 통해서 LIS의 연속하는 숫자들의 차이를 줄임과 동시에 최장길이의 LIS를 구할 수 있게된다.
		if (temp>LIS.back()) {
			answer++;
			LIS.push_back(temp);
		}
		else {
			vector<int>::iterator low_num = lower_bound(LIS.begin(), LIS.end(), temp);
			*low_num = temp;
		}
	}
	cout << answer << endl;
	return 0;
}