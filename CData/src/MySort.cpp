/*
 * MySort.cpp
 *
 *  Created on: 2016��9��20��
 *      Author: Administrator
 */
#include "MySort.h"
//��·һ�ι鲢���̵��㷨
//lowΪ���ζ�·�鲢����ĵ�1�������ĵ�1��Ԫ�أ�iָ���1��Ԫ��, midΪ��1�����������1��Ԫ��
void merge1(int *list, int low, int mid, int high) {
	int i = low;
	int j = mid + 1;
	int *temp = (int *) malloc(sizeof(int) * (high - low + 1));
	if (!temp) {
		exit(-1);
	}
	int k = 0;
	while (i <= mid && j <= high) {
		if (list[i] <= list[j]) {
			temp[k++] = list[i++];
		} else {
			temp[k++] = list[j++];
		}
	}
	while (i <= mid) {
		temp[k++] = list[i++];
	}
	while (j <= high) {
		temp[k++] = list[j++];
	}
	for (i = low, k = 0; i <= high; i++, k++) {
		list[i] = temp[k];
	}
	free(temp);
}
//�ݹ�ʵ�ֶ�·�鲢
void mergeSort1(int *list, int low, int high) {
	//��·�鲢���򣬷�Ϊ��·
	int mid = (low + high) / 2;
	if (low < high) {
		mergeSort1(list, low, mid);
		mergeSort1(list, mid + 1, high);
		merge1(list, low, mid, high);
	}
}
void mergeSortTest1() {
	int list[] = { 25, 64, 12, 89, 41, 29, 30 };
	int n = sizeof(list) / sizeof(int);
	cout << n << endl;
	mergeSort1(list, 0, n - 1);
	cout << n << endl;
	for (int i = 0; i < n; i++) {
		cout << list[i] << "\t";
	}
}
//�ǵݹ鷽ʽʵ�ֶ�·�鲢���� length�������鳤��
void mergeSort2(int *list, int length) {
	int size = 1;
	int low, mid, high;
	//size ������ʶС����Ĵ�С��1,2,4.������
	while (size <= length - 1) {
		low = 0;
		while (low + size <= length - 1) {
			mid = low + size - 1;
			high = mid + size;
			if (high > length - 1) {
				high = length - 1;
			}
			merge1(list, low, mid, high);
			cout << "low: " << low << "mid: " << mid << "high: " << high
					<< endl;
			low = high + 1;
		}
		size *= 2;
	}
}
void mergeSortTest2() {
	int list[] = { 25, 64, 12, 89, 41, 29, 30 };
	int n = sizeof(list) / sizeof(int);
	cout << n << endl;
	mergeSort2(list, n);
	cout << n << endl;
	for (int i = 0; i < n; i++) {
		cout << list[i] << "\t";
	}
}
/******************ֱ�Ӳ�������************************/
void PrintDirectInsertSort(int a[], int n, int i) {
	cout << i << ":";
	for (int j = 0; j < n; j++) {
		cout << a[j] << "\t";
	}
	cout << endl;
}

void DirectInsertSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) { //�ҵ�С��
			int j = i - 1;
			int x = a[i]; //����Ϊ�ڱ������洢������Ԫ��
			a[i] = a[i - 1]; //��������һ��
			while (x < a[j] && j > -1) {
				a[j + 1] = a[j]; //�ҵ�С��Ӧ���ڵ�λ��
				j--;
			}
			a[j + 1] = x; //����С��
		}
		PrintDirectInsertSort(a, n, i);
	}
}
void DirectInsertSortTest() {
	int a[] = { 3, 2, 1, 5, 8, 9, 4, 3, 11, 10 };
	int n = sizeof(a) / sizeof(int);
	DirectInsertSort(a, n);
	PrintDirectInsertSort(a, n, n);
}
/******************���ֲ�������************************/
void PrintBinaryInsertSort(int a[], int n, int i) {
	cout << i << ":";
	for (int j = 0; j < n; j++) {
		cout << a[j] << "\t";
	}
	cout << endl;
}

void BinaryInsertSort(int a[], int n) {
	//�տ�ʼ����������ֻ��һ��Ԫ�� a[0],��������Ϊ[1...n]��
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) { //�ҵ�С��
			//����������Ԫ�ر������������һ��Ԫ��Сʱ�����ö��ֲ��ҷ������������в��Ҳ���λ��
			int low = 0;
			int high = i - 1;
			int mid = 0;
			int x = a[i]; //����Ϊ�ڱ������洢������Ԫ��

			while (low <= high) {
				mid = (low + high) / 2;
				if (x >= a[mid]) {
					low = mid + 1;
				} else {
					high = mid - 1;
				}
			}
			//lowλ�þ���Ҫ�����λ��,����low��i֮���Ԫ�ض���Ҫ�����ƶ�һ��λ��
			int j = i;
			while (j > low) {
				a[j] = a[j - 1];
				j--;
			}
			a[low] = x;
		}
		PrintDirectInsertSort(a, n, i);
	}
}
void BinaryInsertSortTest() {
	int a[] = { 3, 2, 1, 5, 8, 9, 4, 3, 11, 10 };
	int n = sizeof(a) / sizeof(int);
	BinaryInsertSort(a, n);
	PrintBinaryInsertSort(a, n, n);
}
/******************��·��������************************/
void PrintTwoInsertSort(int a[], int n, int i) {
	cout << i << ":";
	for (int j = 0; j < n; j++) {
		cout << a[j] << "\t";
	}
	cout << endl;
}

void TwoInsertSort(int a[], int n) {
	int first = 0, final = 0;
	int k = 0;
	int *temp = (int *) malloc(sizeof(int) * n);
	temp[0] = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] < temp[first]) { // ������Ԫ�ر���С��Ԫ��С
			first = (first - 1 + n) % n;
			temp[first] = a[i];
		} else if (a[i] > temp[final]) { // ������Ԫ�ر����Ԫ�ش�
			final = (final + 1 + n) % n;
			temp[final] = a[i];
		} else { // ����Ԫ�ر���С�󣬱����С
			k = (final + 1 + n) % n;
			while (temp[(k - 1 + n) % n] > a[i]) {
				temp[(k + n) % n] = temp[((k - 1 + n) % n)];
				k = (k - 1 + n) % n;
			}
			temp[(k + n) % n] = a[i];
			final = (final + 1 + n) % n;
		}
		PrintTwoInsertSort(temp, n, i);
	}
	for (k = 0; k < n; k++) {
		a[k] = temp[(first + k) % n];
	}
	free(temp);
}
void TwoInsertSortTest() {
	int a[] = { 3, 2, 1, 5, 8, 9, 4, 3, 11, 10 };
	int n = sizeof(a) / sizeof(int);
	TwoInsertSort(a, n);
	PrintTwoInsertSort(a, n, n);
}
