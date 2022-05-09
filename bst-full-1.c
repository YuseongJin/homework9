/* Binary Search Tree #1 */

#include <stdio.h>//standard input/output library, 표준 입출력 라이브러리
#include <stdlib.h>//c표준 유틸리티 함수들을 모아 놓은 헤더파일

typedef struct node {//구조체 선언
	int key;//int 형 변수 key 멤버 선언
	struct node *left;//자기참조 구조체, left
	struct node *right;//자기참조 구조체, right
} Node;//구조체 별칭

/* 함수 리스트 */
//함수 원형선언

int initializeBST(Node** h);

/* functions that you have to implement */
void inorderTraversal(Node* ptr);	  /* recursive inorder traversal */
void preorderTraversal(Node* ptr);    /* recursive preorder traversal */
void postorderTraversal(Node* ptr);	  /* recursive postorder traversal */
int insert(Node* head, int key);  /* insert a node to the tree */
int deleteLeafNode(Node* head, int key);  /* delete the leaf node for the key */
Node* searchRecursive(Node* ptr, int key);  /* search the node for the key */
Node* searchIterative(Node* head, int key);  /* search the node for the key */
int freeBST(Node* head); /* free all memories allocated to the tree */

/* you may add your own defined functions if necessary */


int main()//메인함수
{
	char command;//char형 변수 선언, 명령어
	int key;//int형 변수 선언, 키보드
	Node* head = NULL;//node head의 값을 NULL로 초기화
	Node* ptr = NULL;	/* temp */
	//node ptr의 값을 NULL로 초기화

	printf("[----- [Yuseong Jin] [2018038022] -----]");//이름, 학번 출력

	do{//do-while문을 통하여 반복 출력
		printf("\n\n");
		printf("----------------------------------------------------------------\n");
		printf("                   Binary Search Tree #1                        \n");
		printf("----------------------------------------------------------------\n");
		printf(" Initialize BST       = z                                       \n");
		printf(" Insert Node          = n      Delete Leaf Node             = d \n");
		printf(" Inorder Traversal    = i      Search Node Recursively      = s \n");
		printf(" Preorder Traversal   = p      Search Node Iteratively      = f\n");
		printf(" Postorder Traversal  = t      Quit                         = q\n");
		printf("----------------------------------------------------------------\n");
		//메뉴 출력

		printf("Command = ");
		scanf(" %c", &command);
		//명령어 입력받기

		switch(command) {//스위치문
		//소문자와 대문자 모두 입력 받기
		case 'z': case 'Z'://z키를 입력 받았을 때
			initializeBST(&head);//initializeBST함수 실행
			break;//스위치문 끝
		case 'q': case 'Q'://q키를 입력 받았을 때
			freeBST(head);//freeBST함수 실행
			break;//스위치문 끝
		case 'n': case 'N'://n키를 입력 받았을 때
			printf("Your Key = ");
			scanf("%d", &key);
			//키 값 입력받기
			insert(head, key);//insert함수 실행
			break;//스위치문 끝
		case 'd': case 'D'://d키를 입력 받았을 때
			printf("Your Key = ");
			scanf("%d", &key);
			//키 값 입력받기
			deleteLeafNode(head, key);//deleteLeafNode함수 실행
			break;//스위치문 끝
		case 'f': case 'F'://f키를 입력 받았을 때
			printf("Your Key = ");
			scanf("%d", &key);
			//키 값 입력받기
			ptr = searchIterative(head, key);
			//searchIterative함수 실행 후 ptr에 대입
			if(ptr != NULL)//ptr이 NULL이 아니라면
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
				//노드와 찾은 주소 출력
			else//ptr이 NULL이라면
				printf("\n Cannot find the node [%d]\n", key);
				//노드를 찾지 못했음을 출력
			break;//스위치문 끝 
		case 's': case 'S'://s키를 입력 받았을 때
			printf("Your Key = ");
			scanf("%d", &key);
			//키 값 입력받기
			ptr = searchRecursive(head->left, key);
			//searchRecursive함수 실행후 ptr에 대입
			if(ptr != NULL)//ptr이 NULL이 아니라면
				printf("\n node [%d] found at %p\n", ptr->key, ptr);
				//노드와 찾은 주소 출력
			else//ptr이 NULL이라면
				printf("\n Cannot find the node [%d]\n", key);
				//노드를 찾지 못했음을 출력
			break;//스위치문 끝

		case 'i': case 'I'://i키를 입력 받았을 때
			inorderTraversal(head->left);
			//inorderTraversal함수 실행
			break;//스위치문 끝
		case 'p': case 'P'://p키를 입력 받았을 때
			preorderTraversal(head->left);
			//preorderTraversal함수 실행
			break;//스위치문 끝
		case 't': case 'T'://t키를 입력 받았을 때
			postorderTraversal(head->left);
			//postorderTraversal함수 실행
			break;//스위치문 끝
		default://이 외의 입력을 받았을 때
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			//경고문 출력
			break;//스위치문 끝
		}

	}while(command != 'q' && command != 'Q');
	//q키를 사용하기 전까지 계속 반복

	return 1;//종료
}

int initializeBST(Node** h) {//BST초기화함수

	/* if the tree is not empty, then remove all allocated nodes from the tree*/
	if(*h != NULL)//h가 NULL이 아니라면
		freeBST(*h);//freeBST함수 실행

	/* create a head node */
	*h = (Node*)malloc(sizeof(Node));
	//h를 동적 메모리 할당
	(*h)->left = NULL;	/* root */
	//h의 left값을 NULL로 초기화
	(*h)->right = *h;
	//h의 right에 h를 대입
	(*h)->key = -9999;
	//h의 key값을 -9999로 초기화
	return 1;//종료
}



void inorderTraversal(Node* ptr)
//노드를 기준으로 왼쪽자식, 부모, 오른쪽 자식 순으로 읽어나가는 것
{
	if(ptr) {//ptr이라면
		inorderTraversal(ptr->left);
		//inorderTraversal함수 실행, left
		printf(" [%d] ", ptr->key);
		//ptr의 키 값 출력
		inorderTraversal(ptr->right);
		//inorderTraversal함수 실행, right
	}
}

void preorderTraversal(Node* ptr)
//전위순회 함수
{
	if(ptr) {//ptr이라면
		printf(" [%d] ", ptr->key);
		//ptr의 키 값 출력
		preorderTraversal(ptr->left);
		//preorderTraversal함수 실행, left
		preorderTraversal(ptr->right);
		//preorderTraversal함수 실행, right
	}
}

void postorderTraversal(Node* ptr)
//후위순회 함수
{
	if(ptr) {//ptr이라면
		postorderTraversal(ptr->left);
        //postorderTraversal함수 실행, left 
		postorderTraversal(ptr->right);
		//postorderTraversal함수 실행, right
		printf(" [%d] ", ptr->key);
		//ptr의 키 값 출력
	}
}


int insert(Node* head, int key)
//삽입 함수
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	//node 포인터 변수 newNode 선언후 동적 메모리 할당
	newNode->key = key;
	//key값을 newNode의 key에 대입
	newNode->left = NULL;
	newNode->right = NULL;
	//newNode의 left, right 값을 NULL로 초기화

	if (head->left == NULL) {
	//head의 left값이 NULL이라면
		head->left = newNode;
		//newNode값을 head의 left에 삽입
		return 1;
		//종료
	}

	/* head->left is the root */
	Node* ptr = head->left;
	//node 포인터 변수 ptr 선언후 head의 left값 삽입

	Node* parentNode = NULL;
	//node 포인터 변수 parentNode 선언후 NULL로 초기화
	while(ptr != NULL) {
	//ptr의 값이 NULL과 다르다면

		/* if there is a node for the key, then just return */
		if(ptr->key == key) return 1;
		//ptr의 key값이 key값과 같다면, 종료

		/* we have to move onto children nodes,
		 * keep tracking the parent using parentNode */
		parentNode = ptr;
		//ptr의 값을 parentNode에 삽입

		/* key comparison, if current node's key is greater than input key
		 * then the new node has to be inserted into the right subtree;
		 * otherwise the left subtree.
		 */
		if(ptr->key < key)
		//ptr의 key값이 key값 보다 작다면
			ptr = ptr->right;
			//ptr에 ptr의 right값 대입
		else//이외
			ptr = ptr->left;
			//ptr에 ptr의 left값 대입
	}

	/* linking the new node to the parent */
	if(parentNode->key > key)
	//parentNode의 key값이 key보다 작다면
		parentNode->left = newNode;
		//parentNode의 left에 newNode값 대입
	else//이외
		parentNode->right = newNode;
		//parentNode의 right에 newNode값 대입
	return 1;//종료
}

int deleteLeafNode(Node* head, int key)
//Leaf 노드 삭제 함수
{
	if (head == NULL) {//head가 NULL이라면
		printf("\n Nothing to delete!!\n");
		//삭제할 것이 없음을 출력
		return -1;//종료
	}

	if (head->left == NULL) {
	//head의 left가 NULL이라면	
		printf("\n Nothing to delete!!\n");
		//삭제할 것이 없음을 출력
		return -1;//종료
	}

	/* head->left is the root */
	Node* ptr = head->left;
	//Node의 포인트변수 ptr선언후 head의 left값 대입


	/* we have to move onto children nodes,
	 * keep tracking the parent using parentNode */
	Node* parentNode = head;
	//Node의 포인트변수 parentNode 선언후 head 대입

	while(ptr != NULL) {//ptr이 NULL이 아니라면

		if(ptr->key == key) {
		//ptr의 key값이 key값과 같다면 
			if(ptr->left == NULL && ptr->right == NULL) {
			//ptr의 left와 right가 동시에 NULL이라면

				/* root node case */
				if(parentNode == head)
				//parentNode가 head와 같다면
					head->left = NULL;
					//head의 left값을 NULL로 초기화

				/* left node case or right case*/
				if(parentNode->left == ptr)
				//parentNode의 left값이 ptr과 같다면
					parentNode->left = NULL;
					//parentNode의 left값을 NULL로 초기화
				else//이외
					parentNode->right = NULL;
					//parentNode의 right값을 NULL로 초기화

				free(ptr);//ptr 할당해제
			}
			else {//이외
				printf("the node [%d] is not a leaf \n", ptr->key);
				//해당 노드가 leafnode가 아님을 출력
			}
			return 1;//종료
		}

		/* keep the parent node */
		parentNode = ptr;//ptr을 parentNode에 대입

		/* key comparison, if current node's key is greater than input key
		 * then the new node has to be inserted into the right subtree;
		 * otherwise the left subtree.
		 */
		if(ptr->key < key)
		//ptr의 key값이 key값 보다 작다면
			ptr = ptr->right;
			//ptr의 right값을 ptr에 대입
		else//그외
			ptr = ptr->left;
			//ptr의 left값을 ptr에 대입


	}

	printf("Cannot find the node for key [%d]\n ", key);
	//key 노드를 못찾았음을 출력

	return 1;//종료
}

Node* searchRecursive(Node* ptr, int key)
//searchRecursive함수 실행, 재귀검색
{
	if(ptr == NULL)
	//ptr이 NULL 이라면
		return NULL;//NULL값 반환

	if(ptr->key < key)
	//ptr의 key값이 key값 보다 작다면
		ptr = searchRecursive(ptr->right, key);
		//searchRecursive함수 실행 후 ptr에 대입, right
	else if(ptr->key > key)
	//ptr의 key값이 key값 보다 크다면
		ptr = searchRecursive(ptr->left, key);
		//searchRecursive함수 실행 후 ptr에 대입, left

	/* if ptr->key == key */
	return ptr;//ptr값 반환

}
Node* searchIterative(Node* head, int key)
//searchIterative 함수, 검색반복
{
	/* root node */
	Node* ptr = head->left;
	//node 포인터 변수 ptr 선언후 head의 left값 대입

	while(ptr != NULL)//ptr이 NULL과 다르다면 
	{
		if(ptr->key == key)
		//ptr의 key값이 key값과 같다면
			return ptr;//ptr 값 반환

		if(ptr->key < key) ptr = ptr->right;
		//ptr의 key값이 key값 보다 작다면 ptr에 ptr의 right값 대입
		else//그 외
			ptr = ptr->left;//ptr의 left값을 ptr에 대입
	}

	return NULL;//NULL값 반환
}

void freeNode(Node* ptr)//freenode 함수
{
	if(ptr) {//Ptr이라면
		freeNode(ptr->left);
		freeNode(ptr->right);
		//freenode함수 실행, left/right
		free(ptr);//ptr 할당해제
	}
}

int freeBST(Node* head)
//freeBST, 함수이진 탐색 트리 (BST, Binary Search Tree)
{

	if(head->left == head)//head의 left값이 head와 같가면
	{
		free(head);//head 할당해제
		return 1;//종료
	}

	Node* p = head->left;
	//node 포인터 변수 p 선언후 head의 left값 대입

	freeNode(p);//freeNode함수 실행

	free(head);//head 할당해제
	return 1;//종료
}