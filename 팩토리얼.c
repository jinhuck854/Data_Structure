#include <stdio.h>
#include <time.h>				//�ð� ������ ���� time.h ��� ���� ����

int recursion(int n);			//����Լ��� �̿��� ���丮�� �Լ� ����
int iteration(int m);			//for���� �̿��� ���丮�� �Լ� ����

int main(void) {
	int i, result;				//scanf�� �Է��� �޾� �����ϴ� ������ ���� i�� ����� result ���� ����

	scanf_s("%d", &i);			//scanf�� ������ �Է¹޾� i�� ����

	clock_t start, finish;		//�ڵ� �ɸ��� �ð� ������ ���� ���۰� ��
	start = clock();			//���丮�� �Լ��� ���� �ð�
	result = iteration(i);		//����Լ� �Ǵ� �ݺ��� �Լ� ȣ���Ͽ� ������� result�� ����
	finish = clock();			//���丮�� �Լ��� �� �ð�
	double duration = (double)(finish - start) / CLOCKS_PER_SEC; //����� ���� duration, �ð� ������ ���� double�� CLOCKS_PER_SEC ���

	printf("%d! : %d\n", i, result);				//����Լ� �Ǵ� for���� �̿��� ���丮�� ����� ���
	printf("�ɸ��ð� : %lf��\n", duration);			//�ɸ��ð� ���
	
	return 0;
}

int recursion(int n) {				//��͸� �̿��� ���丮�� �Լ� ����
	if (n == 1) {
		return 1;					// n=1 �� �� ���̽� ���̽�
	}
	else
	{
		printf("%d\n", n);					//�����Ⱚ, 4750~ 4780 ���̿� ���� �����÷ο� �߻�
		return n * (recursion(n - 1));		//n���� n-1, n-2 ... ���̽� ���̽��� n=1 ���� �ݺ�, �ڱ� �ڽ��� ȣ��
	}
}

int iteration(int m) {						//for���� �̿��� ���丮�� �Լ� ����
	int i, result = 1;						//�ݺ����� ���� ������ ���� i�� ������� �����ϴ� result ���� ����
	for (i = 1; i <= m; i++) {				//i=1���� 2,3 ... m���� �ݺ�
		result *= i;						// result = 1 * i�� 1���� m������ ���丮�� ���
		printf("%d\n", i);					//�ð��� �ø��� ���� �����Ⱚ
	}
	return result;							// result���� ��ȯ
}