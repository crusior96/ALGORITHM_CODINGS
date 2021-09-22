#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;
long long int N, P, Q, X, Y;
unordered_map<long long, unsigned long long> infi;

//���Ѽ���(1351)�� ����������, ��¦ �ٸ� ����
//N�� ������ �޶����� �� �� �ƴ϶�, X�� Y��� ���ο� ������ �߰��Ʊ� ������ �ð��� ���� �����ؾ� �Ѵ�
//�̿� �ٸ� �ڷᱸ���� ���� �˾ƺ��� �� ���, unordered_map�̶�� �ڷᱸ���� ���� �� �� �ְ� �ƴ�
//�̿ܿ��� �� �ٸ� ������ map�� �ִµ�, �ش� �κп� ���ؼ� ���Ŀ� �ٷﺸ���� ����

unsigned long long calc(long long  a) {
	if (a <= 0) {
		return 1;
	}


	if (infi[a]) {
		return infi[a];
	}

	return infi[a] = calc(a / P - X) + calc(a / Q - Y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> P >> Q >> X >> Y;
	cout << calc(N) << '\n';
	return 0;
}