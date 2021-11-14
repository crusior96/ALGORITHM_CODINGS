#include<iostream>
#include<string>

using namespace std;
int color[2] = { 0, 1 };	//RED가 0, BLACK을 1로 표기한다
int node_depth = 0;			//찾고자 하는 key값을 가진 노드의 깊이를 저장하는 전역변수
							//Show_Depth함수와 연관된 부분이다

//app 정보에 대한 구조체
struct apps {
	int APP_ID;
	string APP_NAME;
	int APP_SIZE;
	int APP_PRICE;
};

//RedBlackTree에서 사용할 node의 초기값 지정
//이 RedBlackTree에선 id값을 key값처럼 다룰 것이다
//또한 각각의 node들은 key값이자 id값에 맞는 app의 정보를 node_app에 저장한다
struct node {
	int key;
	apps node_app;
	node *right = nullptr;
	node *left = nullptr;
	node *parent = nullptr;
	int node_color = color[1];
};

//NULL과 nullptr은 엄연히 다르다는 것에 주의하자
class RedBlackTree {
private:
	node *root;
	node *leaf_node;

	//해당 key값이자 ID값이 존재하는지에 대해 체크하는 함수
	//key값이 있다면 해당 key값의 포인터값을, 아니면 NULL이 나오게 된다
	node* search_key(int k) {
		node* temp = root;
		node* parent = NULL;
		
		//key값이 k인 node를 찾거나, 못 찾을 때 까지 반복한다
		while (temp != NULL && temp->key != k) {
			parent = temp;
			if (k < parent->key) {
				temp = parent->left;
			}
			else {
				temp = parent->right;
			}
		}
		return temp;
	}

	//현재의 노드가 얼마나 깊은지를 알아내는 함수
	//재귀를 이용해서 root까지 뻗어나간다
	void Show_Depth(node* curr) {
		int temp_depth = 0;

		//현재 노드가 root가 아니라면 while문을 진행한다
		if (curr->parent != nullptr) {
			while (curr->parent != nullptr) {
				if (curr->parent == nullptr) {
					break;
				}

				temp_depth++;
				curr = curr->parent;
			}
		}
		
		//전역변수인 node_depth에 temp_depth값 이식
		node_depth = temp_depth;
	}

	//key값이 k인 node를 입력한다. 또한 해당 node는 app의 정보가 들어간 app_tmp의 정보를 가지고 있다
	void Insert(int k, apps app_tmp) {
		node* temp_1 = this->root;		//temp_3이 삽입되는 공간을 찾기위해 사용한 노드. 초기값은 RedBlackTree의 root
		node* temp_2 = nullptr;			//temp_3의 부모 노드 역할
		node* temp_3 = new node();		//이번에 삽입이 되는 노드

		//RedBlackTree에 이제 막 들어가는 Node의 초기설정
		//맨 끝에 들어갔으니 node_color는 Red가 된다
		temp_3->key = k;
		temp_3->node_color = color[0];
		temp_3->right = leaf_node;
		temp_3->left = leaf_node;
		temp_3->parent = nullptr;
		temp_3->node_app = app_tmp;

		//일반적인 이진트리에서의 탐색방식을 사용한다
		while (temp_1 != leaf_node) {
			temp_2 = temp_1;
			if (temp_1->key < k) {
				temp_1 = temp_1->right;
			}
			else {
				temp_1 = temp_1->left;
			}
		}

		temp_3->parent = temp_2;

		//부모 노드가 null이라면
		if (temp_2 == nullptr) {
			//root 노드는 temp_3인 것이다
			root = temp_3;
		}
		//그외에는 부모 노드와 자기 자신의 key값을 비교해서
		//부모 노드의 right 혹은 left에 배치하게 된다
		else if (temp_3->key > temp_2->key) {
			temp_2->right = temp_3;
		}
		else {
			temp_2->left = temp_3;
		}

		//현재 노드가 root라면
		if (temp_3->parent == nullptr) {
			//해당 node의 color는 black이 되고 현재 함수를 종료하면 된다
			temp_3->node_color = color[1];
			return;
		}

		//현재 노드의 부모 노드가 root라면 굳이 색변환이 필요하지 않다
		if (temp_3->parent->parent == nullptr) {
			return;
		}

		//그 외의 경우엔 RedBlackTree의 배치에 위배되는 경우이기 때문에 재배치 작업을 진행한다
		Reconstruction(temp_3);
		return;

	}

	//RedBlackTree로의 삽입 작업 이후 규칙에 위배되는 점을 해결하기 위해 재배치 작업을 진행한다
	void Reconstruction(node* target) {
		node* grandnode;			//해당 노드의 부모의 부모 노드가 들어간다
		node* parent_sibling;		//부모의 부모 노드가 가지고 있는 또 다른 자식
		bool wayside;

		//현재 작업은 이번에 삽입하게 되는 노드가 root값이 아니며, 
		//해당 노드의 부모가 가지는 color값이 RED라서 Double RED 상태일 때 발생하게 된다
		while (target != root && target->parent->node_color == color[0]) {

			grandnode = target->parent->parent;

			//부모 노드가 부모의 부모 노드 상에 배치된 위치에 따라 parent_sibling이 배치되는 곳이 달라진다
			//또한 부모 노드가 부모의 부모 노드 상에 왼쪽에 배치돼있다면 true를, 아니라면 false를 wayside에 배치해둔다
			if (target->parent == grandnode->left) {
				parent_sibling = grandnode->right;
				wayside = true;
			}
			else {
				parent_sibling = grandnode->left;
				wayside = false;
			}

			//만약 parent_sibling 노드가 존재하고, parent_sibling 노드도 RED라면
			//parent_sibling과 부모 노드는 BLACK이 되고, 부모의 부모 노드는 root라 할지라도 일단은 RED가 된다
			//이후 부모의 부모 노드를 target으로 두고, while문을 계속 반복한다
			if (parent_sibling && parent_sibling->node_color == color[0]) {
				target->parent->node_color = color[1];
				parent_sibling->node_color = color[1];
				grandnode->node_color = color[0];
				target = grandnode;
			}
			else {
				//만약 parent_sibling 노드가 존재하지 않거나 parent_sibling 노드의 색이 BLACK이라면
				//부모 노드가 부모의 부모 노드 상에 왼쪽에 있고, 해당 노드는 부모 노드의 오른쪽에 배치돼있다면
				if (wayside == true && target == target->parent->right) {
					//해당 노드를 해당 노드의 부모로 바꾼 다음 왼쪽 방향으로 회전을 진행한다
					target = target->parent;
					Left_Turn(target);
				}
				//부모 노드가 부모의 부모 노드 상에 오른쪽에 있고, 해당 노드는 부모 노드의 왼쪽에 배치돼있다면
				else if (wayside == false && target == target->parent->left) {
					//해당 노드를 해당 노드의 부모로 바꾼 다음 오른쪽 방향으로 회전을 진행한다
					target = target->parent;
					Right_Turn(target);
				}

				//회전이전 or 회전 이후에 Recoloring 작업 진행
				//부모 노드는 BLACK, 부모의 부모 노드는 RED로 진행한다
				//이 경우에는 위에 target값이 parent로 지정 된 경우도 있으니 색 변환에 관해선 보고서에 더 자세히 기재해보자
				target->parent->node_color = color[1];
				grandnode->node_color = color[0];

				//회전 이전 or 회전 이후에 단순히 부모 노드가 부모 노드 상에 왼쪽에 있다면 오른쪽 방향으로 회전을 진행한다
				if (wayside == true) {
					Right_Turn(grandnode);
				}
				//회전 이전 or 회전 이후에 부모 노드가 부모의 부모 노드 상에 오른쪽에 있다면 왼쪽 방향으로 회전을 진행한다
				else if (wayside == false) {
					Left_Turn(grandnode);
				}

				
			}
		}

		//절대적인 규칙인 root의 색은 BLACK이어야 한다는 조건에 따라 root의 색을 BLACK으로 지정해둔다
		root->node_color = color[1];
	}



	//key값이 k인 node가 가지고 있는 node_app에 관한 정보 및 해당 node의 깊이를 출력한다
	void Show_Info(int k, node* target) {
		cout << node_depth << " " << target->node_app.APP_NAME << " " << target->node_app.APP_SIZE << " " << target->node_app.APP_PRICE << '\n';
	}

	//포인터값이 targer인 node가 가지고 있는 node_app의 정보를 app_tmp로 대체한다
	void Update_Status(apps app_tmp, node* target) {
		target->node_app = app_tmp;
	}

	//왼쪽으로 회전할 때 쓰이는 함수
	//변수로 배정받은 node 포인터인 tmp_2를 기준으로 왼쪽으로 이동하게 된다
	void Left_Turn(node* tmp_2) {
		node* tmp_1;

		//tmp_1은 tmp_2의 right이 되고, tmp_2의 right은 tmp_1의 left가 된다
		tmp_1 = tmp_2->right;
		tmp_2->right = tmp_1->left;
		
		//만약 tmp_1의 left에 있는 값이 leaf_node가 아니라면[즉, 하위 노드를 가지고 있다면]
		//tmp_1의 left에 있는 값의 parent를 tmp_2로 지정한다
		if (tmp_1->left != leaf_node) {
			tmp_1->left->parent = tmp_2;
		}

		//tmp_1의 parent를 tmp_2의 parent로 지정한다. 사실상 tmp_1의 grandparent를 parent로 지정한다는 뜻
		tmp_1->parent = tmp_2->parent;

		//위에 지정했듯이 tmp_1->parent가 NULL이라는건 tmp_1은 root가 될 수 있다는 뜻이다
		if (!tmp_2->parent) {
			root = tmp_1;
		}
		//tmp_2가 tmp_2의 부모 노드의 left에 위치한다면
		//해당 위치에 tmp_2 대신 tmp_1을 넣는다
		else if (tmp_2 == tmp_2->parent->left) {
			tmp_2->parent->left = tmp_1;
		}
		//tmp_2가 tmp_2의 부모 노드의 right에 위치한다면
		//해당 위치에 tmp_2 대신 tmp_1일 넣는다
		else {
			tmp_2->parent->right = tmp_1;
		}

		//이후 tmp_2의 parent자리에 tmp_1을 넣고
		//그렇게 올라간 tmp_1의 left에 tmp_2를 위치시킨다
		tmp_2->parent = tmp_1;
		tmp_1->left = tmp_2;

	}

	//오른쪽으로 회전할 때 쓰이는 함수
	//변수로 배정받은 node 포인터인 tmp_1로 만들어진 node 포인터 tmp_2를 기준으로 오른쪽으로 회전하게 된다
	//위의 Left_Turn과 방향 개념은 비슷하며 방향 위치가 서로 반대된 상황이라 보면 된다
	void Right_Turn(node* tmp_1) {
		node* tmp_2;

		tmp_2 = tmp_1->left;
		tmp_1->left = tmp_2->right;

		if (tmp_2->right != leaf_node) {
			tmp_2->right->parent = tmp_1;
		}

		tmp_2->parent = tmp_1->parent;

		if (!tmp_1->parent) {
			root = tmp_2;
		}
		else if (tmp_1 == tmp_1->parent->left) {
			tmp_1->parent->left = tmp_2;
		}
		else {
			tmp_1->parent->right = tmp_2;
		}

		tmp_1->parent = tmp_2;
		tmp_2->right = tmp_1;

	}

	
	public:

	//RedBlackTree 내부의 leaf_node와 root에 관한 초기값을 지정
	RedBlackTree() {
		leaf_node = new node;
		leaf_node->node_color = color[1];
		leaf_node->right = nullptr;
		leaf_node->left = nullptr;
		leaf_node->parent = nullptr;
		root = leaf_node;
	}

	//private에 있는 search_key를 사용하기 위한 함수
	node* s_key(int k) {
		return search_key(k);
	}

	//private에 있는 Insert를 사용하기 위한 함수
	void ins(int k, apps app_t) {
		Insert(k, app_t);
	}

	//private에 있는 Update_Status를 사용하기 위한 함수
	void us(apps app_t, node* t) {
		Update_Status(app_t, t);
	}

	//private에 있는 Show_Depth를 사용하기 위한 함수
	void sd(node* t) {
		Show_Depth(t);
	}

	//private에 있는 Show_Info를 사용하기 위한 함수
	void si(int k, node* t) {
		Show_Info(k, t);
	}

};


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	RedBlackTree rbTree;
	int N;
	cin >> N;

	while (N > 0) {
		N--;
		string order, name, new_name;
		int id, size, price, new_size, new_price, start_idx, end_idx, discount_rate;
		cin >> order;
		if (order == "I") {
			//key값이자 id, 이름, 용량, 가격 입력
			cin >> id >> name >> size >> price;

			//현재 key값을 가진 node가 없다면
			if (rbTree.s_key(id) == nullptr) {
				//app 정보 구조체인 app에 app 내용 입력 이후
				apps app;
				app.APP_ID = id;
				app.APP_NAME = name;
				app.APP_PRICE = price;
				app.APP_SIZE = size;
				//RedBlackTree에 key값과 app 내용 정보 입력
				rbTree.ins(id, app);
			}

			//정보 입력 이후 재배치 작업이 진행 된 이후 다시금 key값을 찾는다
			if (rbTree.s_key(id) != nullptr) {
				//찾아낸 node 포인트값을 기준으로 해당 node의 깊이를 찾아낸다
				node* temp = rbTree.s_key(id);
				rbTree.sd(temp);
				cout << node_depth << '\n';
			}

		}
		else if (order == "F") {
			cin >> id;
			//현재 RedBlackTree에 id를 key값으로 가진 node가 없다면 NULL을 출력하고
			//만약 있다면, 해당 node의 app 정보 및 node의 depth를 출력하면 된다
			node* temp = rbTree.s_key(id);
			if (temp == nullptr) {
				cout << "NULL" << '\n';
			}
			else {
				rbTree.sd(temp);
				rbTree.si(id, temp);
			}
		}
		else if (order == "R") {
			//key값이자 id, 변환하고자 하는 app의 이름, 용량, 가격을 입력한다
			cin >> id >> new_name >> new_size >> new_price;
			node* temp = rbTree.s_key(id);
			//id를 key값으로 가진 node가 RedBlackTree에 없다면, NULL을 출력한다
			if (temp == nullptr) {
				cout << "NULL" << '\n';
			}
			else {
				//현재 RedBlackTree에 id를 key값으로 가진 node가 있다면
				//app 구조체에 app 정보들을 입력한다음, 해당 node가 지닌 app정보를 업데이트 한다
				//이후 해당 node의 depth를 출력하면 된다
				apps app;
				app.APP_ID = id;
				app.APP_NAME = new_name;
				app.APP_PRICE = new_price;
				app.APP_SIZE = new_size;
				rbTree.us(app, temp);
				rbTree.sd(temp);
				cout << node_depth << '\n';
			}
		}
		else if (order == "D") {
			//할인이 적용이 될 범위의 시작점인 start_idx와 끝점인 end_idx, 할인율인 discount_rate를 입력한다
			cin >> start_idx >> end_idx >> discount_rate;
			for (int i = start_idx;i <= end_idx;i++) {
				//start_idx와 end_idx 사이의 값인 i를 기준으로 node를 찾아서 성공적으로 찾아낸다면
				//해당 node의 app 가격정보를 받아와서 할인율을 기준으로 할인된 가격을 그 node의 app 가격정보에 넣어둔다
				//시간복잡도가 제일 걱정되는 부분이지만 NlogM일테니 함 해보자
				node* temp = rbTree.s_key(i);
				if (temp != nullptr) {
					int now_price = temp->node_app.APP_PRICE;
					now_price = (now_price * (100 - discount_rate)) / 100;
					temp->node_app.APP_PRICE = now_price;
				}
			}
		}
	}

	return 0;
}
