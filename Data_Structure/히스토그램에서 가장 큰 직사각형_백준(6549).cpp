#include<iostream>
#include<stack>
using namespace std;
unsigned long long int arr[100001] = {};	//직사각형들의 높이 입력

//어떠한 테스트케이스마다 N개의 직사각형들이 있다고 가정하자
//각각의 직사각형들은 입력받은 순서대로 서로 붙어있으며 가로 길이는 1이다
//높이들이 순서대로 주어진다고 가정할 때, 이 직사각형들 안에서 만들 수 있는 제일큰 직사각형의 넓이를 구하여라
//단, 최초입력 N의 값이 0으로 주어진다면 입력을 종료한다

int main() {
	stack<unsigned long long int> height;	//직사각형들의 위치에 대한 정보가 저장되는 곳. 높이값이 아니다.
	bool now = true;
	while (now) {
		unsigned long long int max = 0;		//답안으로 출력할 변수
		int N;
		cin >> N;
		if (N == 0) {
			break;
		}
		else {
			for (int i = 0;i < N;i++) {
				cin >> arr[i];
			}


			//첫 번째 직사각형서부터 N번째 직사각형에 대해서 for문 실행
			for (int i = 0;i < N;i++) {
				int left = i;
				//현재 height스택이 비어있지 않고, 해당 스택의 top()에 있는 위치에 해당하는 높이값이 이번에 입력되는 값보다 큰 경우
				//즉, 직사각형 높이 상태가 바로 앞에 있는 직사각형이 뒤에있는 애보다 긴 경우
				//스택값을 pop()하면서 pop되는 직사각형의 높이 * 스택에서 바로 아래 직사각형까지의 거리를 계산해준다
				while (!height.empty() && arr[height.top()] > arr[i]) {
					int j = arr[height.top()];
					height.pop();
					long long int width = i;
					//비교해야 할 height의 위치값이 남아있는 경우
					//이번에 빼낼 직사각형의 높이(j) * 이번에 빼낼 직사각형의 위치에서부터 해당 쿼리가 진행된 i값까지의
					//거리(width)를 곱해준다
					if (height.empty() != true) {
						width = i - height.top() - 1;
					}
					if (max < width*j) {
						max = width * j;
					}
				}
				height.push(i);

			}

			//그 외 나머지 남은 값들을 기준으로 최댓값 구하기 재실행
			//작동 방식은 위와 같다
			while (height.empty() != true) {
				int j = arr[height.top()];
				height.pop();
				long long int width = N;
				if (!height.empty()) {
					width -= height.top() + 1;
				}
				if (max < width*j) {
					max = width * j;
				}
			}

			cout << max << endl;
		}
	}
	return 0;
}