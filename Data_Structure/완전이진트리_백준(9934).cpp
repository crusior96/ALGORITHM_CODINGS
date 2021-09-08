#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

//트리의 Inorder를 구현하는 문제
//트리라는 자료구조를 직접적으로 사용하는 것은 아니지만
//그 순서만 알고 있다면 풀어나갈 수 있는 문제였다

//어떠한 완전이진 탐색트리를 Inorder로 탐색했을 때, K개의 단계로 이루어진 숫자들로 주어진다고 가정하자
//이때, 트리의 Root부터 단말 노드까지 각각의 층별로 있는 숫자들을 순서대로 출력하면 되는 문제
//K의 값은 최대 10이다
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<int> arr[12];
	int num[1500] = {};
	int K;
	cin >> K;

	//K단계의 완전이진 탐색트리는 pow(2,K) - 1개의 노드들이 주어진다
	for (int i = 0;i < pow(2, K) - 1;i++) {
		cin >> num[i];
	}



	if (K == 1) {
		cout << num[0] << '\n';
	}
	else {
		//K값이 2 이상인경우, 각 숫자들의 인덱스를 지정하는 작업을 진행한다
		//이전 단계 트리의 탐색 인덱스를 현 단계 트리의 탐색 인덱스 앞뒤로 붙히는식으로 인덱스를 확장한다
		//이후 해당 인덱스를 string형식으로 지정한다
		//또한, K가 10인경우엔 특수하게 지정해서 z로 인덱스를 지정한다
		string S = "1";
		string ans;
		for (int i = 2;i <= K;i++) {
			if (i == 10) {
				string tmp = "z";
				ans = S + tmp + S;
				S = ans;
			}
			else {
				string tmp = to_string(i);
				ans = S + tmp + S;
				S = ans;
			}
		}

		//인덱스 상태에 따라 해당 인덱스를 지닌 값을 arr[인덱스]에 넣어둔다
		//문자열의 숫자처리도 해줘야한다
		for (int i = 0;i < ans.length();i++) {
			if (ans[i] == 'z') {
				arr[10].push_back(num[i]);
			}
			else {
				arr[ans[i] - '0'].push_back(num[i]);
			}

		}


		for (int i = K;i >= 1;i--) {
			for (int j = 0;j < arr[i].size();j++) {
				cout << arr[i][j] << " ";
			}
			cout << '\n';
		}
	}

	return 0;
}