#include <stdio.h>
#include <time.h>				//시간 측정을 위한 time.h 헤더 파일 선언

int recursion(int n);			//재귀함수를 이용한 팩토리얼 함수 선언
int iteration(int m);			//for문을 이용한 팩토리얼 함수 선언

int main(void) {
	int i, result;				//scanf로 입력을 받아 저장하는 정수형 변수 i와 결과값 result 변수 선언

	scanf_s("%d", &i);			//scanf로 정수를 입력받아 i에 저장

	clock_t start, finish;		//코딩 걸리는 시간 측정을 위한 시작과 끝
	start = clock();			//팩토리얼 함수의 시작 시간
	result = iteration(i);		//재귀함수 또는 반복문 함수 호출하여 결과값을 result에 저장
	finish = clock();			//팩토리얼 함수의 끝 시간
	double duration = (double)(finish - start) / CLOCKS_PER_SEC; //결과값 담을 duration, 시간 측정을 위해 double과 CLOCKS_PER_SEC 사용

	printf("%d! : %d\n", i, result);				//재귀함수 또는 for문을 이용한 팩토리얼 결과값 출력
	printf("걸린시간 : %lf초\n", duration);			//걸린시간 출력
	
	return 0;
}

int recursion(int n) {				//재귀를 이용한 팩토리얼 함수 정의
	if (n == 1) {
		return 1;					// n=1 일 때 베이스 케이스
	}
	else
	{
		printf("%d\n", n);					//쓰레기값, 4750~ 4780 사이에 스택 오버플로우 발생
		return n * (recursion(n - 1));		//n부터 n-1, n-2 ... 베이스 케이스인 n=1 까지 반복, 자기 자신을 호출
	}
}

int iteration(int m) {						//for문을 이용한 팩토리얼 함수 정의
	int i, result = 1;						//반복문을 위한 정수형 변수 i와 결과값을 저장하는 result 변수 선언
	for (i = 1; i <= m; i++) {				//i=1부터 2,3 ... m까지 반복
		result *= i;						// result = 1 * i로 1부터 m까지의 팩토리얼 계산
		printf("%d\n", i);					//시간을 늘리기 위한 쓰레기값
	}
	return result;							// result값을 반환
}