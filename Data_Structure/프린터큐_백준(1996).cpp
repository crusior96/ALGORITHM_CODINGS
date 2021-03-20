#include<iostream>
#include<queue>
#include<utility>
using namespace std;

//N개의 문서들이 있다고 가정하자. 해당 문서들은 FIFO의 규칙에 따라 저장돼있다.
//각각의 문서들은 번호를 부여받는데 0 ~ N-1의 번호를 순차적으로 받는다
//이제 각각의 문서들은 중요도를 부여받게 되는데 중요도의 범위는 1 ~ 9이며 중요도가 높을수록 그 문서는 먼저 출력된다
//문서 출력방식은 원형 큐 처럼 중요도가 더 높은 문서가 현재 있다면 출력대상이 될 뻔한 문서는 맨 뒤로 돌려보내게 된다
//이때 M번째로 출력되는 문서는 무엇인지 몇 번째 문서인지 구하여라

int main() {
	ios::sync_with_stdio(false);
	int Tc;
	cin >> Tc;
	for (int i = 0;i < Tc;i++) {
		int M, N, cnt;
		cnt = 0;
		//pair<int, int>를 자료형으로 가진 큐인 q에다가 현재 문서의 번호 및 중요도를 저장한다
		//우선순위 큐를 이용해서 q 내에 있는 문서들 중 먼저 출력할 문서들에 대한 순번을 중요도를 기준으로 저장한다
		queue<pair<int, int>>q;
		priority_queue<int> pq;
		cin >> N >> M;
		for (int j = 0;j < N;j++) {
			int temp;
			cin >> temp;
			q.push({ j,temp });
			pq.push(temp);
		}

		//이제 현재 있는 q의 문서들을 앞에서부터 비교하는데 pq.top()과 중요도가 같은 것들을 먼저 출력한다
		//같다면 해당 문서에 대한 정보를 q와 pq에서 pop하고, 그렇지 않다면 비교를 위해 뽑아놓았던 자료를
		//다시 q 맨 뒤로 입력시켜둔다
		while (!q.empty()) {
			int pt = q.front().first;
			int value = q.front().second;
			q.pop();

			if (pq.top() == value) {
				pq.pop();
				cnt++;
				if (pt == M) {
					cout << cnt << endl;
					break;
				}	
			}
			else {
				q.push({ pt,value });
			}
		}
		
	}
	return 0;
}
