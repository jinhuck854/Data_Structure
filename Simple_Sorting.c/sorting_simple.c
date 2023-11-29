#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 20

void Select(int a[], int n) { // ���� ����
	int min, minindex = 0, temp;
	int CNT = 0;
	int Arr[MAX_SIZE];

	for (int i = 0; i < n; i++) { // �迭 ����
		Arr[i] = a[i];
	}

	for (int i = 0; i < n; i++) { // i = 0~48
		min = 200; // 1~100���� �����̱� ������
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
	printf("\n\n�̵� Ƚ�� : %d\n", CNT);
}

void Bubble(int a[], int n) { // ���� ����
	int temp = 0;
	int CNT = 0;
	int Arr[MAX_SIZE];

	for (int i = 0; i < n; i++) { // �迭 ����
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
	printf("\n\n�̵� Ƚ�� : %d\n", CNT);
}

/*
// ����, �ڸ� ��ȯ�� �߻����� �ʴ´� = ������ �� ��. Bubble Sorting �ɷ� ��� no swaping == Sorting Array : Sorting ����
void Bubble2(int a[], int n) { // ���� ���� 2
	int temp, count;
	int num = 0, CNT = 0; // // temp : swap�� ���� ����, count : ���� ���� ���� ���, num : ���� ���� Ƚ��
	int Arr[MAX_SIZE];

	for (int i = 0; i < n; i++) { // �迭 ����
		Arr[i] = a[i];
	}

	for (int i = 0; i < n; i++) { // 0~6����
		int count = i;
		for (int j = 0; j < n - 1; j++) { // ��������
			if (Arr[j] > Arr[j + 1]) {
				temp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = temp;
				count += 1; // ������ ������ count ++
			}
		}
		num++;
		printf("\nNumber : %d\n", num);

		if (count == i) { // Sorting X �� ��, ���� ���� // �������̰ų� �߰��� Sorting �� �� �� ���� ����
			printf("\n\nBubble2 Stop Sorting !");
			break;
		}
	}

	printf("\nBubble2 Sorting : ");

	for (int i = 0; i < n; i++) {
		printf("%d ", Arr[i]);
	}
	printf("\n\n�̵� Ƚ�� : %d\n", CNT);
}
*/

void Insert(int a[], int n) { // ���� ���� : Insert Sort
	int key, j, CNT = 0;
	int Arr[MAX_SIZE];

	for (int i = 0; i < n; i++) { // �迭 ����
		Arr[i] = a[i];
	}

	for (int i = 1; i < n; i++) { // ���� ���� ����
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
	printf("\n\n�̵� Ƚ�� : %d\n", CNT);
}

int main() { // 1, 10, 20, 30, 60, 50, 70
	int Array[MAX_SIZE]; // n���� �迭

	
	srand(time(NULL));
	int temp;

	for (int i = 0; i < MAX_SIZE; i++) { // 100�� ����
		temp = (rand() % 100); // 0~99���� ������
		Array[i] = temp;
	}
	

	/*
	// �� ���� : Bubble Sorting ��� �����ؼ� ���� ��� Ȯ��
	Array[0] = 1;
	Array[1] = 10;
	Array[2] = 20;
	Array[3] = 30;
	Array[4] = 60;
	Array[5] = 50;
	Array[6] = 70;
	

	// ����
	for (int i = 0; i < MAX_SIZE; i++) {
		printf("%d ", Array[i]);
	}
	*/

	//���� ����
	Select(Array, MAX_SIZE);

	//���� ����
	Bubble(Array, MAX_SIZE);

	//���� ���� ���� ���
	// Bubble2(Array, MAX_SIZE);

	//���� ����
	Insert(Array, MAX_SIZE);

	return 0;
}