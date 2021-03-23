#include<iostream>
#include<stack>
using namespace std;
unsigned long long int arr[100001] = {};	//���簢������ ���� �Է�

//��� �׽�Ʈ���̽����� N���� ���簢������ �ִٰ� ��������
//������ ���簢������ �Է¹��� ������� ���� �پ������� ���� ���̴� 1�̴�
//���̵��� ������� �־����ٰ� ������ ��, �� ���簢���� �ȿ��� ���� �� �ִ� ����ū ���簢���� ���̸� ���Ͽ���
//��, �����Է� N�� ���� 0���� �־����ٸ� �Է��� �����Ѵ�

int main() {
	stack<unsigned long long int> height;	//���簢������ ��ġ�� ���� ������ ����Ǵ� ��. ���̰��� �ƴϴ�.
	bool now = true;
	while (now) {
		unsigned long long int max = 0;		//������� ����� ����
		int N;
		cin >> N;
		if (N == 0) {
			break;
		}
		else {
			for (int i = 0;i < N;i++) {
				cin >> arr[i];
			}


			//ù ��° ���簢�������� N��° ���簢���� ���ؼ� for�� ����
			for (int i = 0;i < N;i++) {
				int left = i;
				//���� height������ ������� �ʰ�, �ش� ������ top()�� �ִ� ��ġ�� �ش��ϴ� ���̰��� �̹��� �ԷµǴ� ������ ū ���
				//��, ���簢�� ���� ���°� �ٷ� �տ� �ִ� ���簢���� �ڿ��ִ� �ֺ��� �� ���
				//���ð��� pop()�ϸ鼭 pop�Ǵ� ���簢���� ���� * ���ÿ��� �ٷ� �Ʒ� ���簢�������� �Ÿ��� ������ش�
				while (!height.empty() && arr[height.top()] > arr[i]) {
					int j = arr[height.top()];
					height.pop();
					long long int width = i;
					//���ؾ� �� height�� ��ġ���� �����ִ� ���
					//�̹��� ���� ���簢���� ����(j) * �̹��� ���� ���簢���� ��ġ�������� �ش� ������ ����� i��������
					//�Ÿ�(width)�� �����ش�
					if (height.empty() != true) {
						width = i - height.top() - 1;
					}
					if (max < width*j) {
						max = width * j;
					}
				}
				height.push(i);

			}

			//�� �� ������ ���� ������ �������� �ִ� ���ϱ� �����
			//�۵� ����� ���� ����
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