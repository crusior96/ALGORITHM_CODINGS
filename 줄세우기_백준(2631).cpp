#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//N명의 아이들은 각각 1부터 N까지의 번호를 가지고 있다
//이 아이들이 지금 줄을 서있긴 한데 서로 순서가 섞인 채 서있다면
//이 아이들을 A와 B의 위치를 바꾸는 식으로 오름차순 정렬을 할 때
//위치를 바꾸는 횟수를 최소로 할 때의 그 횟수를 구하여라

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int num;
	int answer = 0;

	//여기에선 이전에 사용했던 LIS 알고리즘을 사용하였다
	//해당 알고리즘은 중복되는 숫자가 없다면 그 효과가 100% 보장된다
	//LIS알고리즘을 사용한 이유는, 증가하는 오름차순 상태를 최대한 보존하고 해당하지 않는 숫자만 옮기기 위해서이다
	//결국 이 문제의 답은 LIS 알고리즘으로 얻은 최장 증가 부분수열의 길이를 N에서 빼는 것이다
	vector<int>LIS;
	LIS.push_back(-1000000001);
	cin >> num;
	for (int i = 0;i < num;i++) {
		int temp;
		cin >> temp;
		if (temp > LIS.back()) {
			answer++;
			LIS.push_back(temp);
		}
		else {
			vector<int>::iterator low_num = lower_bound(LIS.begin(), LIS.end(), temp);
			*low_num = temp;
		}
	}
	cout << num - answer << endl;
	return 0;
}