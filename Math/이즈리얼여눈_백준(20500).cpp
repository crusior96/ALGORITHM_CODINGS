#include<iostream>
#include<string>
using namespace std;
long long int arr[1517] = {};

//��ǻ� ����������� ���� �˾ƺ� �� �־��� ����
//�츮�� �˰� �ִ� �� �ڸ��� ��� �Ӹ� �ƴ϶� �پ��� 2�ڸ� �� ������� ���ǿ� ���ؼ��� �� �� �ִ�
//������ ���� �� 1�� 5�θ� �̷���� N�ڸ��� �� 15�� ����� ������ ������ ���϶�� ���̴�
//���� 1000000007�� ���� �������� ���� ����ϰ� �ȴ�
//https://ko.wikipedia.org/wiki/%EB%B0%B0%EC%88%98_%ED%8C%90%EC%A0%95%EB%B2%95

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;

	//�ʱⰪ�� ã�ƺ��ٸ� ������ DP�� Ǯ �� �־���
	for (int i = 4;i <= N;i++) {
		arr[i] = ((arr[i - 2] * 2) % 1000000007 + (arr[i - 1]) % 1000000007) % 1000000007;
	}
	cout << arr[N] << '\n';
	return 0;
}