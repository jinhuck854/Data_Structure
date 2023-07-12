#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct DListNode { // Doubly Linked List
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
}DListNode;

void insert_position(DListNode** h, int position, element value) { // 위치 삽입
	int k = 1; // k : 위치 이동
	DListNode* newNode, * temp; // newNode : 새로운 노드 삽입 / temp : 노드
	newNode = (DListNode*)malloc(sizeof(DListNode)); // newNode 동적 할당
	newNode->data = value;

	// 위치 직접 입력
	/*
	int position;
	printf("위치 입력 : ");
	scanf("%d", &position);
	*/

	if (position == 1) { // ① 위치 position이 1일 때
		if ((*h) == NULL) {	// 노드 첫 삽입
			newNode->llink = NULL;
			newNode->rlink = *h;
			*h = newNode;
		}
		else { // 맨앞 삽입
			newNode->llink = NULL;
			newNode->rlink = *h;
			(*h)->llink = newNode;
			*h = newNode;
		}
		return;
	}
	else {	// 위치 position이 2이상일 때
		temp = *h;
		while ((k < position - 1) && temp->rlink != NULL) {	// k가 위치 찾거나 NULL 만날 때까지 반복
			temp = temp->rlink;
			k++;
		}
		if (temp->rlink == NULL) { // ② 위치가 마지막 자리
			newNode->rlink = temp->rlink;
			newNode->llink = temp;
			temp->rlink = newNode;
		}
		else { // ③ 중간 위치
			newNode->rlink = temp->rlink;
			newNode->llink = temp;
			temp->rlink->llink = newNode;
			temp->rlink = newNode;
		}
	}
	return;
}

void delete_position(DListNode** h, int position) { // 위치 삭제
	int k = 1;
	DListNode* pre, * removed; // pre : 삭제 노드의 이전 노드 / removed : 삭제할 노드
	pre = *h;
	removed = *h;

	// 위치 직접 입력
	/*
	int position;
	printf("위치 입력 : ");
	scanf("%d", &position);
	*/

	if ((*h) == NULL) return;// 아무것도 없을 때 NULL 리턴
	else if (position == 1) { // ① 위치 position이 1일 때
		pre = pre->rlink;
		pre->llink = NULL;
		*h = pre;
		free(removed);
	}
	else { // position이 2 이상일 때
		if ((*h) == NULL) return; // 헤드의 값 == NULL일 때
		else {
			removed = (*h)->rlink;
			while ((k < position) && removed->rlink != NULL) { // 위치 찾거나 NULL을 만날 때까지 반복
				pre = removed;
				removed = removed->rlink;
				k++;
			}
			if (removed->rlink == NULL) { // ② 위치가 마지막 자리
				pre->rlink = removed->rlink;
				free(removed);
			}
			else { // ③ 중간 위치
				pre->rlink = removed->rlink;
				removed->rlink->llink = pre;
				free(removed);
			}
		}return;
	}

}

void print_Dlist(DListNode* h) {	// 출력
	for (DListNode* p = h->rlink; p != NULL; p = p->rlink) {
		printf(" <- || %d || ->", p->data);
	}
	printf("\n");
}

void start() {
	DListNode* head = NULL; // 구조체 head선언 후 NULL값으로 초기화

	printf("이중 연결 리스트 위치 선택 삽입 !\n");
	for (int i = 0; i <= 5; i++) {	// 0~4까지 첫 번째 위치 삽입 후 출력
		insert_position(&head, 1, i);
		print_Dlist(head);
	}

	printf("\n이중 연결 리스트 위치 선택 삭제 !\n");
	delete_position(&head, 10); print_Dlist(head);
}

int main(void) {
	start();
	return 0;
}
