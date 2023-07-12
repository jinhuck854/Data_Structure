#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 5

typedef int element;

typedef struct { // dynamic array
	int top;
	int capacity;
	int* array;
} arrayStack;

arrayStack* createStack() { // 스택 초기화
	arrayStack* S = malloc(sizeof(arrayStack));
	if (!S) return NULL;

	S->top = -1;
	S->capacity = 1;
	S->array = malloc(S->capacity * sizeof(int));

	if (!S->array) return NULL;

	return S;
}


int isFull(arrayStack* S) { // 스택 가득찼을 때
	return (S->top == S->capacity - 1);
}

int isEmpty(arrayStack* S) { // 스택 비었을 때
	return (S->top == -1);
}

void push(arrayStack* S, int data) { // PUSH
	if (isFull(S)) { // 가득찼을 때
		printf("공간 늘리기 전 : %d\n", S->capacity);
		S->capacity *= 2; // Max Size 2배씩 늘림
		S->array = (int*)realloc(S->array, S->capacity * sizeof(int));
		printf("공간 늘린 후 : %d\n", S->capacity);
	}
	S->array[++(S->top)] = data;
	printf("현재 공간 : %d\n", S->capacity);
}

int pop(arrayStack* S) { // POP
	if (isEmpty(S)) {
		printf("underflow\n");
		exit(1);
	}
	else {
		return S->array[S->top--];
	}
}

int peek(arrayStack* S) { // PEEK
	if (isEmpty(S)) {
		fprintf(stderr, "underflow\n");
		exit(1);
	}
	else {
		return S->array[S->top];
	}
}

void deleteStack(arrayStack* S) { // 스택 삭제
	if (S) { // 배열부터 삭제
		free(S->array);
	}
	free(S);
}

void start() {
	arrayStack* myS = createStack();

	for (int i = 0; i < 5; i++) { // 5번 Push
		printf("==================================\n");
		push(myS, i);
		printf("PEEK : %d\n", peek(myS));
	}

	for (int j = 0; j < 5; j++) { // 5번 Pop
		printf("==================================\n");
		int tmp = pop(myS);
		printf("POP : %d\n", tmp);
	}
	deleteStack(myS); // 스택 삭제
}

int main() {
	start();
	return 0;
}
