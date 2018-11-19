#include<iostream>
#include<algorithm>
using namespace std;

//N개의 로프를 이용하여 이런 저런 물체를 들어올릴수 있다.
//이때, k개의 로프를 m의 중량을 가진 물건에 연결하여 들어올리면
//각각의 로프는 m/k의 중량을 받은 채로 물건을 들어올릴 수 있다. 즉, 중량을 나누어서 들어올릴 수 있는 것.
//N개의 로프가 버틸 수 있는 중량이 주어진다면, 최대한 들어올릴 수 있는 물체의 중량을 구해라.
//단, 로프는 전부 다 사용할 필요는 없다.

int main()
{
	int N, rope_len;
	unsigned long long int max_rope = 0; //최대한 들어올릴 수 있는 물건의 무게
	cin >> N;
	int *rope = (int*)malloc(sizeof(int)*N); //각각의 로프들이 들어올릴 수 있는 최대 중량을 저장해두는 배열

	for (int i = 0;i < N;i++)
	{
		cin >> rope_len;
		rope[i] = rope_len;
	}
	sort(rope, rope + N); //로프들의 최대 중량을 오름차순으로 정렬해둔다.

	for (int i = 0;i < N;i++)
	{
		if (max_rope < rope[i] * (N - i))
			max_rope = rope[i] * (N - i);
		//오름차순으로 정렬되어있으니, 로프가 들어올릴 수 있는 제일 작은 무게는 다른 로프들도 들어올릴 수 있다.
		//그 다음으로 로프가 들어올릴 수 있는 무제는 앞의 1개의 로프를 제외한 다른 로프들이 들어올릴 수 있다.
		//이렇게 병렬적으로 최대한 연결하여 들어올릴 수 있는 상황을 비교하여 최대한 들어올릴 수 있는 중량을 찾아낸다.
	}
	cout << max_rope << endl;

	return 0;

}