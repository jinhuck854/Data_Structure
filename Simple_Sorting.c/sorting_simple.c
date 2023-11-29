#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20

void Select(int a[], int n) { // 선택 정렬
	int min, minindex = 0, temp;
	int CNT = 0;
	int Arr[MAX_SIZE];

	for (int i = 0; i < n; i++) { // 배열 복사
		Arr[i] = a[i];
	}

	for (int i = 0; i < n; i++) { // i = 0~48
		min = 200; // 1~100까지 랜덤이기 때문에
		for (int j = i; j < n; j++) {
			if (Arr[j] < min) {
				min = Arr[j];
				minindex = j;
			}
		}
		// swap
		temp = Arr[minindex];
		Arr[minindex] = Arr[i];
		Arr[i] = temp;
		CNT++;
	}

	printf("\n\nSelect Sorting : ");
	for (int i = 0; i < n; i++) {
		printf("%d ", Arr[i]);
	}
	printf("\n\n이동 횟수 : %d\n", CNT);
}

void Bubble(int a[], int n) { // 버블 정렬
	int temp = 0;
	int CNT = 0;
	int Arr[MAX_SIZE];

	for (int i = 0; i < n; i++) { // 배열 복사
		Arr[i] = a[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (Arr[j] > Arr[j + 1]) {
				temp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = temp;
				CNT++;
			}
		}
	}

	printf("\n\nBubble Sorting : ");
	for (int i = 0; i < n; i++) {
		printf("%d ", Arr[i]);
	}
	printf("\n\n이동 횟수 : %d\n", CNT);
}

/*
// 만약, 자리 교환이 발생하지 않는다 = 정렬이 다 됨. Bubble Sorting 능력 향상 no swaping == Sorting Array : Sorting 멈춤
void Bubble2(int a[], int n) { // 버블 정렬 2
	int temp, count;
	int num = 0, CNT = 0; // // temp : swap을 위한 변수, count : 버블 정렬 성능 향상, num : 버블 정렬 횟수
	int Arr[MAX_SIZE];

	for (int i = 0; i < n; i++) { // 배열 복사
		Arr[i] = a[i];
	}

	for (int i = 0; i < n; i++) { // 0~6까지
		int count = i;
		for (int j = 0; j < n - 1; j++) { // 오름차순
			if (Arr[j] > Arr[j + 1]) {
				temp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = temp;
				count += 1; // 정렬할 때마다 count ++
			}
		}
		num++;
		printf("\nNumber : %d\n", num);

		if (count == i) { // Sorting X 일 때, 정렬 끝냄 // 마지막이거나 중간에 Sorting 안 할 때 조건 만족
			printf("\n\nBubble2 Stop Sorting !");
			break;
		}
	}

	printf("\nBubble2 Sorting : ");

	for (int i = 0; i < n; i++) {
		printf("%d ", Arr[i]);
	}
	printf("\n\n이동 횟수 : %d\n", CNT);
}
*/

void Insert(int a[], int n) { // 삽입 정렬 : Insert Sort
	int key, j, CNT = 0;
	int Arr[MAX_SIZE];

	for (int i = 0; i < n; i++) { // 배열 복사
		Arr[i] = a[i];
	}

	for (int i = 1; i < n; i++) { // 삽입 정렬 시작
		key = Arr[i];

		for (j = i - 1; j >= 0 && Arr[j] > key; j--) {
			Arr[j + 1] = Arr[j];
		}

		Arr[j + 1] = key;
		CNT++;
	}

	printf("\n\nInsert Sorting : ");
	for (int i = 0; i < n; i++) {
		printf("%d ", Arr[i]);
	}
	printf("\n\n이동 횟수 : %d\n", CNT);
}

int main() { // 1, 10, 20, 30, 60, 50, 70
	int Array[MAX_SIZE]; // n개의 배열

	
	srand(time(NULL));
	int temp;

	for (int i = 0; i < MAX_SIZE; i++) { // 100개 랜덤
		temp = (rand() % 100); // 0~99까지 랜덤값
		Array[i] = temp;
	}
	

	/*
	// 값 고정 : Bubble Sorting 결과 고정해서 성능 향상 확인
	Array[0] = 1;
	Array[1] = 10;
	Array[2] = 20;
	Array[3] = 30;
	Array[4] = 60;
	Array[5] = 50;
	Array[6] = 70;
	

	// 원본
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", Array[i]);
	}
	*/

	//선택 정렬
	Select(Array, MAX_SIZE);

	//버블 정렬
	Bubble(Array, MAX_SIZE);

	//버블 정렬 성능 향상
	// Bubble2(Array, MAX_SIZE);

	//삽입 정렬
	Insert(Array, MAX_SIZE);

	return 0;
}