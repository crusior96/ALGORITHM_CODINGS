#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

//어떠한 배열이 주어진다고 가정하자
//배열을 뒤집는 명령인 R과 배열의 맨 앞 수를 제거하는 D가 문자열 상태로 제공된다
//만약 배열이 비어있는데 D 명령을 진행하려 한다면 error 문자열을 출력하게 된다
//초기 배열 상태도 문자열로 주어지며, [숫자,숫자,숫자,숫자]와 같은 양식으로 주어진다
//명령을 다 이행하게 된다면 그 결과값을 출력하되, 초기에 저장된 양식에 맞춰서 출력해야 한다
//배열의 크기와 명령어의 길이는 둘 다 1 이상 100000이하일때 해당 명령을 수행한 결과값을 출력하라

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int Tc;
	cin >> Tc;
	for (int i = 0;i < Tc;i++) {
		string numbers, orders;		//각각 중괄호가 포함된 배열과 명령어 문자열을 의미한다
		cin >> orders;
		int num;
		cin >> num;

		//초기 배열 상태를 입력한 다음, 배열 내에 있는 숫자들을 추출해내는 모습
		//이 과정에서 파싱에 대한 과정과 char* 와 string간에 변환 과정을 알 수 있었다
		cin >> numbers;
		numbers = numbers.substr(1,numbers.length() - 2);				//맨 앞과 맨 뒤 대괄호 제거 작업
		vector<char> numbers_before(numbers.begin(), numbers.end());	//strtok 함수를 사용하기 위해 자료 복사
		numbers_before.push_back('\0');									//문자열의 끝이라는 의미로 '\0' 입력
		char* temp1 = &*numbers_before.begin();							//복사된 벡터의 시작지점을 temp1로 지정한다
		char* ptr = strtok(temp1, ",");									//이후 ','를 기준으로 문자열들을 분리해낸다

		//preorder는 정방향의 벡터, postorder는 반대방향의 벡터이다
		//괜히 벡터 하나 가지고 reverse 함수를 적용하느니 초기에 벡터값을 2개 만들어두는게 편하다
		//postorder에 우선 저장한 다음, preorder에 postorder에 있는 값을 reverse하여 저장해둔다
		vector<int> numbers_preorder;
		vector<int> numbers_postorder;
		while (ptr != NULL) {
			int num_temp = stoi(ptr);
			numbers_postorder.push_back(num_temp);
			ptr = strtok(NULL, ",");
		}
		numbers_preorder = numbers_postorder;
		reverse(numbers_postorder.begin(), numbers_postorder.end());

		int pre_cnt = 0;		//정방향 벡터에서 앞에서부터 제거된 값들
		int post_cnt = 0;		//반대방향 벡터에서 앞에서부터 제거된 값들
		int status = 0;			//현재 벡터 상태가 정방향인지 반대방향인지 알려주는 값
								//0이면 정방향, 1이면 반대방향인 상황이다
		int bad_status = 1;		//만약 배열이 빈 상황에서 D 명령이 실행됐으면 bad_status를 0으로 지정한다
		for (int j = 0;j < orders.length();j++) {
			//R 명령어 : 방향회전
			if (orders[j] == 'R') {
				status++;
				status %= 2;
			}
			else if (orders[j] == 'D') {
				//배열 크기가 사실상 0인 상황인데 D 명령이 적용되는 경우
				if (pre_cnt + post_cnt == numbers_preorder.size()) {
					cout << "error" << '\n';
					bad_status = 0;
					break;
				}
				//그렇지 않다면, 현재 방향을 기준으로 cnt값을 올려준다
				else if (pre_cnt + post_cnt < numbers_preorder.size()) {
					if (status == 0) {
						pre_cnt++;
					}
					else if (status == 1) {
						post_cnt++;
					}
				}
			}
		}

		//해당 명령은 bad_status값이 1인 경우에만 실행됨
		if (bad_status == 1) {
			//명령만으로 순수하게 빈 배열을 만들었을 경우
			if (pre_cnt + post_cnt == numbers_preorder.size()) {
				cout << "[]" << '\n';
			}
			else {
				//배열에 값이 남아있는 경우, 양식에 맞게 값을 출력해낸다
				//status 상태에 따라 출력에 참조할 벡터 배열을 지정한 다음
				//마지막 값은 콤마를 함께 출력하지 않고 대괄호를 출력한다
				if (pre_cnt + post_cnt < numbers_preorder.size()) {
					cout << "[";
					if (status == 0) {
						for (int j = pre_cnt;j < numbers_preorder.size() - post_cnt - 1;j++) {
							cout << numbers_preorder[j] << ",";
						}
						cout << numbers_preorder[numbers_preorder.size() - post_cnt - 1];
					}
					else if (status == 1) {
						for (int j = post_cnt;j < numbers_postorder.size() - pre_cnt - 1;j++) {
							cout << numbers_postorder[j] << ",";
						}
						cout << numbers_postorder[numbers_postorder.size() - pre_cnt - 1];
					}

					cout << "]";
				}
				cout << '\n';
			}
		}


	}
	return 0;
}