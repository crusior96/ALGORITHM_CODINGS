#include<iostream>
#include<string>
using namespace std;
int M, N;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);


	int DNA_proto[1000][4] = {};
	int len_answer = 0;
	string DNA_answer;

	cin >> M >> N;
	for (int j = 0;j < M;j++) {

		string temp;
		cin >> temp;

		for (int k = 0;k < temp.length();k++) {
			switch (temp[k]) {
			case 'A':
				DNA_proto[k][0]++;
				break;
			case 'C':
				DNA_proto[k][1]++;
				break;
			case 'G':
				DNA_proto[k][2]++;
				break;
			case 'T':
				DNA_proto[k][3]++;
				break;
			}
		}
	}

	for (int j = 0;j < N;j++) {
		int idx = 0;
		int cnt = 0;

		for (int k = 0;k < 4;k++) {
			if (DNA_proto[j][k] > cnt) {
				idx = k;
				cnt = DNA_proto[j][k];
			}
		}

		len_answer += M - cnt;

		switch (idx) {
		case 0:
			DNA_answer += 'A';
			break;
		case 1:
			DNA_answer += 'C';
			break;
		case 2:
			DNA_answer += 'G';
			break;
		case 3:
			DNA_answer += 'T';
			break;
		}
	}

	cout << DNA_answer << '\n' << len_answer << '\n';
	
	return 0;
}