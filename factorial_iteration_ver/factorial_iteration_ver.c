#include <stdio.h>
#include <time.h>

int main(void) {
	int i, j; //scanf�� �Է��� �޾� �����ϴ� ������ ���� i ����
	int result = 1;
	double duration; //�ɸ��ð��� �����ϴ� double�� ���� duration ����

	scanf_s("%d", &j); //scanf�� ������ �Է¹޾� i�� ����

	for (i = 1; i <= j; i++) { //i=1���� 2,3, j���� j�� �ݺ�
		result *= i; // result = 1 * i;
		printf("%d\n", result);
	}

	clock_t start, finish; //�ڵ� �ɸ��� �ð� ������ ���� ���۰� ��
	start = clock(); //���丮�� �Լ��� ���� �ð�
	finish = clock(); //���丮�� �Լ��� �� �ð�
	duration = (double)(finish - start) / CLOCKS_PER_SEC; //�ɸ��� �ð� ���ϴ� ��, �Ҽ������� ǥ���ϱ� ���� double������ ��ȯ
	printf("�ɸ��ð� : %lf��\n", duration); //17���� ����� ���� �÷ο�(����), 4790~4793

	return 0;
}