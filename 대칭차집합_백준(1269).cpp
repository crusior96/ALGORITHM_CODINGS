#include<cstdio>
#include<set>
using namespace std;

//각각 20만 이하의 자연수인 A와 B의 크기로 이루어진 집합이 있다고 가정하자. 이때, 집합의 원소들은 10^8 이하의 자연수이다.
//A 차집합 B와 B 차집합 A의 원소들의 합을 구하여라.


//처음으로 써본 set 컨테이너의 사용. 입력된 원소는 자동으로 정렬되지만 중복되어 정렬되지 않는다.
//또한, 특정 원소를 찾아내기 위해선 원소가 있는 주소를 알아내야하는데
//배열과는 달리 구체적으로 나와있는 주소가 없기 때문에 find()함수로 주소를 찾아내거나 count()함수를 통해 유무를 판단할 수 있다.
int main()
{
	int A, B; //각각의 두 집합 내에 있는 원소들의 갯수.
	set <long long int> Anum;
	scanf("%d %d", &A, &B);
	int answer = A + B; //교집합 상태를 고려하지 않은 원소들의 총합. 교집합 원소의 갯수*2만큼 빼주면 답을 얻을 수 있다.

	//첫 번째 집합에 원소들을 입력한 후, 두 번째 집합에 입력될 원소들이 첫 번째 집합에 존재하는 원소인지 알아내는 방식으로 문제를 푼다.
	//로그 시간복잡도를 가지고 있기에 시간초과도 예방할 수 있다.
	for (int i = 0;i < A;i++)
	{
		long long int temp;
		scanf("%lld", &temp);
		Anum.insert(temp);
	}

	for (int i = 0;i < B;i++)
	{
		long long int temp;
		scanf("%lld", &temp);
		//이미 Anum 집합에 있는 원소가 입력되었다면 Anum.count(temp)의 값은 1이 된다.
		if (Anum.count(temp) >= 1)
		{
			answer = answer - 2;
		}
	}
	printf("%d\n", answer);
	return 0;
}