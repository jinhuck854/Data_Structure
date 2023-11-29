#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 8 // 짝수 : 내림

void mergeSort_Iter(int data[], int temp[], int left, int right) { // Iterative : Array, TEMP, left = 0, right = 7
    int mid = (left+right/2); // mid = 3
    int i, j, k, l;
    i = left; j = mid + 1; k = left; // i = 0부터, j = mid + 1부터, k = 0부터

    while (i <= mid && j <= right) { // 2개 이상일 때
        if (data[i] <= data[j])    // 왼쪽이 더 작을 때
            temp[k++] = data[i++]; // 배열 k번째에 배열에서 제일 작은 값(왼쪽)을 넣음
        else                       // 오른쪽이 더 작을 때
            temp[k++] = data[j++]; // 배열 k번째에 배열에서 제일 작은 값(오른쪽)을 넣음
    }

    if (i > mid) { // 왼쪽이 다 끝나면, 오른쪽 모두 넣기
        for (l = j; l <= right; l++)
            temp[k++] = data[j++];
    }
    else { // 오른쪽이 다 끝나면, 왼쪽 나머지 모두 넣기
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
    int tmp[8]; // 새 배열
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
    int Array[MAX_SIZE]; // 정렬 전 배열
    int TEMP[MAX_SIZE]; // 정렬 후 배열
    int temp;

    srand(NULL);
    for (int i = 0; i < MAX_SIZE; i++) { // 1~100까지 랜덤값 8번 삽입
        temp = (rand() % 100) + 1;
        Array[i] = temp;
    }

    printf("\n정렬 전\n");
    for (int i = 0; i < MAX_SIZE; i++) { // 정렬 전 랜덤값 출력
        printf("%d ", Array[i]);
    }

    mergeSort_Iter(Array, TEMP, 0, MAX_SIZE - 1);

    /*
    mergeSort(Array, 0, MAX_SIZE-1);
    printf("\n정렬 후\n");
    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", Array[i]);
    }
    */

    return 0;
}