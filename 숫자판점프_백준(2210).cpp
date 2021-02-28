#include<iostream>
#include<string>
#include<set>
using namespace std;
set <int> numbers;
int temp_answer[6];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int num[5][5];

//비교적 간단한 형식의 DFS문제이자 set 자료구조를 처음 사용해본 문제
//set은 중복되는 자료를 자동적으로 걸러서 저장한다
//유사한 자료구조로는 map이 있다
//5 * 5의 숫자판이 있고 숫자판 내에서 6칸을 상하좌우 아무렇게나 움직여서 만들수 있는 중복되지 않는 숫자의 갯수를 구하여라


//현재까지 입력된 임시숫자의 자릿수와 숫자판 위의 좌표
void DFS(int index, int x, int y) {
	if (index == 6) {
		//총 6자리가 입력되면 만들어진 숫자를 numbers 셋에 넣는다
		int real_answer = temp_answer[0] * 100000 + temp_answer[1] * 10000 + temp_answer[2] * 1000 + temp_answer[3] * 100 + temp_answer[4] * 10 + temp_answer[5];
		numbers.insert(real_answer);
	}
	else if(index != 6){
		//6자리가 아직 완성되지 않았다면 숫자판을 넘지않는 선에서 좌표를 이동한다
		temp_answer[index] = num[x][y];
		if (x >= 1) {
			DFS(index + 1, x - 1, y);
		}
		if (x < 4) {
			DFS(index + 1, x + 1, y);
		}
		if (y >= 1) {
			DFS(index + 1, x, y - 1);
		}
		if (y < 4) {
			DFS(index + 1, x, y + 1);
		}
	}
}


int main() {

	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			cin >> num[i][j];
		}
	}

	for (int i = 0;i < 5;i++) {
		for (int j = 0;j < 5;j++) {
			DFS(0, i, j);
		}
	}

	cout << numbers.size();

	return 0;
}