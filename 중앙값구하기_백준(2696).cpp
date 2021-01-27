#include<iostream>
#include<queue>
using namespace std;

//N개의 숫자를 입력하는 과정중에서 홀수 번 째 숫자를 입력했을때
//현재까지 입력한 숫자들을 기준으로 중앙값을 구해서 제출하는 것이 이번 문제의 목적

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int Tc;
	cin >> Tc;
	for (int i = 0;i < Tc;i++) {
		//우선순위 큐를 사용하여 만든 최소 힙 그리고 최대 힙
		//최대 힙의 경우엔 vector를 어떻게 이용했는지 알아둘 필요가 있다
		//힙을 이렇게 2개 만들어 둔 이유 : 하나는 오름차순, 하나는 내림차순으로 둬서 중앙에 있는 값을 찾기 위해서
		priority_queue<int>min_num;
		priority_queue<int, vector<int>, greater<int>>max_num;
		int cout_stk = 0;
		int N;
		cin >> N;
		cout << (N / 2) + 1 << '\n';
		for (int i = 1;i <= N;i++) {

			int tmp;
			cin >> tmp;
			//숫자들을 번갈아서 집어넣는다. 순서는 최대 힙, 그다음 최소 힙에 넣는 순서대로 진행한다.
			if (max_num.size() == min_num.size()) {
				min_num.push(tmp);
			}
			else {
				max_num.push(tmp);
			}

			//max_num값의 최댓값과 min_num값의 최솟값들 중 max_num쪽이 작다면 서로 바꿔준다 
			if (!max_num.empty() && !min_num.empty() && max_num.top() < min_num.top()) {
				int tmp1 = max_num.top();
				int tmp2 = min_num.top();
				max_num.pop();
				min_num.pop();
				max_num.push(tmp2);
				min_num.push(tmp1);
			}

			//매 홀수번째 마다 min_num값의 최솟값 즉 top()값을 출력한다. 정확히 지급된 숫자들 중 가운데에 있다.
			if (i % 2 == 1) {
				cout << min_num.top() << ' ';
				cout_stk++;
				if (cout_stk % 10 == 0 && N >= 10) {
					cout << '\n';
				}
			}
		}
		cout << '\n';
	}

	return 0;
}