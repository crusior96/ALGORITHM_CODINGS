#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

int N;
int alphabets[27] = {};	//alphabets[i] : 숫자의 자릿수를 고려했을 때, 해당 알파벳이 표현할 수 있는 자릿수에 대한 정보를 저장해둔다

//N개의 숫자가 주어지는데 각각 알파벳으로 이루어진 문자열로만 주어진다고 가정하자
//각각의 알파벳에 임의의 숫자를 넣어서 모든 숫자들을 더할 수 있다면
//이러한 조건으로 만들수 있는 숫자들의 최대합을 구하여라

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N;
	int answer = 0;

	for (int i = 0;i < N;i++) {
		string tmp;
		cin >> tmp;
		//현재 알파벳 문자열의 위치에 따라 alphabets에 더해지는 값이 달라진다
		//이를 통해 alphabets[i]가 몇 번 언급되는지 알 수 있고, 높은 값부터 정렬해서 9 ~ 0의 값을 제공하면 된다
		for (int j = tmp.length() - 1;j >= 0;j--) {
			alphabets[tmp[tmp.length() - 1 - j] - 'A'] += pow(10, j);
		}
	}

	sort(alphabets, alphabets + 27);

	//정렬 이후 가장 많이 언급된 알파벳부터 숫자값을 부여한다
	for (int i = 9;i >= 0;i--) {
		answer += alphabets[26 - (9 - i)] * i;
	}

	cout << answer << '\n';
	return 0;
}