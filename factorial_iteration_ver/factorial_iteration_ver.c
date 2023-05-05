#include <stdio.h>
#include <time.h>

int main(void) {
	int i, j; //scanf로 입력을 받아 저장하는 정수형 변수 i 선언
	int result = 1;
	double duration; //걸린시간을 저장하는 double형 변수 duration 선언

	scanf_s("%d", &j); //scanf로 정수를 입력받아 i에 저장

	for (i = 1; i <= j; i++) { //i=1부터 2,3, j까지 j번 반복
		result *= i; // result = 1 * i;
		printf("%d\n", result);
	}

	clock_t start, finish; //코딩 걸리는 시간 측정을 위한 시작과 끝
	start = clock(); //팩토리얼 함수의 시작 시간
	finish = clock(); //팩토리얼 함수의 끝 시간
	duration = (double)(finish - start) / CLOCKS_PER_SEC; //걸리는 시간 구하는 식, 소숫점으로 표현하기 위해 double형으로 변환
	printf("걸린시간 : %lf초\n", duration); //17부터 결과값 오버 플로우(음수), 4790~4793

	return 0;
}