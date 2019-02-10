#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#define MAX_HEAP_SIZE 10

void Decrease_key_min_heap(int A[], int i, int key) {//i�� �ִ� key���� �� �۰� ���鵵��
	if (key >= A[i])
		printf("error new key is not smaller thatn current key\n");

	A[i] = key;

	int parent;
	int child;
	int temp;

	while (i != 1) {//i=1�̸� ���� ���� ����̱� ������
		parent = i / 2;//parent��带 ã��
		if (A[i] < A[parent]) {//���� parent���� ���� ��쿡�� �ٲ��ش�
			temp = A[i];
			A[i] = A[parent];
			A[parent] = temp;
		}
		i = parent;//�׸��� �񱳴���� ���� �÷��ش�.
	}
}

void Increase_min_heap(int A[], int i, int key) {
	if (key <= A[i])
		printf("error new key is not smaller thatn current key\n");

	A[i] = key;

	int child;
	int temp;

	while (i <= MAX_HEAP_SIZE / 2) {//��ü ����� ����/2������ �����ָ� ����
		child = i * 2;
		if (A[child] < A[child + 1])
			child++;

		if (A[i] > A[child]) {//�ٲٱ� ����
			temp = A[i];
			A[i] = A[child];
			A[child] = temp;
		}
		i = child;//�ϳ� �����ش�.
	}
}

int main() {
	int h1[11] = { 0,1,4,2,7,5,3,3,7,8,9 };//�迭
	Decrease_key_min_heap(h1, 4, 3);
	Increase_min_heap(h1, 3, 10);

	for (int i = 1; i <= MAX_HEAP_SIZE; i++) {
		printf("%d\n", h1[i]);
	}
}
