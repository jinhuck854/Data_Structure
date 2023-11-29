#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 8 // ¦�� : ����

void mergeSort_Iter(int data[], int temp[], int left, int right) { // Iterative : Array, TEMP, left = 0, right = 7
    int mid = (left+right/2); // mid = 3
    int i, j, k, l;
    i = left; j = mid + 1; k = left; // i = 0����, j = mid + 1����, k = 0����

    while (i <= mid && j <= right) { // 2�� �̻��� ��
        if (data[i] <= data[j])    // ������ �� ���� ��
            temp[k++] = data[i++]; // �迭 k��°�� �迭���� ���� ���� ��(����)�� ����
        else                       // �������� �� ���� ��
            temp[k++] = data[j++]; // �迭 k��°�� �迭���� ���� ���� ��(������)�� ����
    }

    if (i > mid) { // ������ �� ������, ������ ��� �ֱ�
        for (l = j; l <= right; l++)
            temp[k++] = data[j++];
    }
    else { // �������� �� ������, ���� ������ ��� �ֱ�
        for (l = i; l <= mid; l++)
            temp[k++] = data[i++];
    }

    printf("MergeSorting Iterative !\n");
    for (int a = 0; a < MAX_SIZE; a++) {
        printf("%d ", temp[a]);
    }
}

/*
void mergeSort(int data[], int left, int right) { //Recursion
    int mid;
    if (left < right) {
        mid = (left + right) / 2;
        mergeSort(data, left, right);
        mergeSort(data, mid+1, right);
        merge(data, left, mid, right);
    }
}

void merge(int data[], int p, int q, int r) { // Recursion
    int i = p, j = q + 1, k = p;
    int tmp[8]; // �� �迭
    while (i <= q && j <= r) {
        if (data[i] <= data[j]) tmp[k++] = data[i++];
        else tmp[k++] = data[j++];
    }
    while (i <= q) tmp[k++] = data[i++];
    while (j <= r) tmp[k++] = data[j++];
    for (int a = p; a <= r; a++) data[a] = tmp[a];
}
*/

int main() {
    int Array[MAX_SIZE]; // ���� �� �迭
    int TEMP[MAX_SIZE]; // ���� �� �迭
    int temp;

    srand(NULL);
    for (int i = 0; i < MAX_SIZE; i++) { // 1~100���� ������ 8�� ����
        temp = (rand() % 100) + 1;
        Array[i] = temp;
    }

    printf("\n���� ��\n");
    for (int i = 0; i < MAX_SIZE; i++) { // ���� �� ������ ���
        printf("%d ", Array[i]);
    }

    mergeSort_Iter(Array, TEMP, 0, MAX_SIZE - 1);

    /*
    mergeSort(Array, 0, MAX_SIZE-1);
    printf("\n���� ��\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", Array[i]);
    }
    */

    return 0;
}