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
/******************ϣ��������С��������************************/
void PrintShellInsertSort(int a[], int n, int i) {
	cout << i << ":";
	for (int j = 0; j < n; j++) {
		cout << a[j] << "\t";
	}
	cout << endl;
}

void ShellInsertSort(int a[], int n, int dk) {
	for (int i = dk; i < n; i++) {
		if (a[i] < a[i - dk]) {
			int j = i - dk;
			int x = a[i];
			a[i] = a[j];
			while (x < a[j]) {
				a[j + dk] = a[j];
				j -= dk;
			}
			a[j + dk] = x;
		}
		PrintShellInsertSort(a, n, i);
	}
}
void ShellSort(int a[], int n) {
	int dk = n / 2;
	while (dk >= 1) {
		ShellInsertSort(a, n, dk);
		dk /= 2;
	}
}
void ShellInsertSortTest() {
	int a[] = { 3, 2, 1, 5, 8, 9, 4, 3, 11, 10 };
	int n = sizeof(a) / sizeof(int);
	ShellSort(a, n);
	PrintShellInsertSort(a, n, n);
}
/******************ѡ������************************/
void PrintSelectSort(int a[], int n, int i) {
	cout << i << ":";
	for (int j = 0; j < n; j++) {
		cout << a[j] << "\t";
	}
	cout << endl;
}

void SelectSort(int a[], int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) {
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
		PrintSelectSort(a, n, i);
	}
}
void SelectTwoSort(int a[], int n) {
	for (int i = 0; i < n / 2; i++) {
		int min = i, max = i;
		for (int j = i + 1; j < n - i; j++) {
			if (a[j] >= a[max]) {
				max = j;
				continue;
			}
			if (a[j] < a[min]) {
				min = j;
			}
		}
		int temp = a[i];
		a[i] = a[min];
		a[min] = temp;
		temp = a[n - i - 1];
		a[n - i - 1] = a[max];
		a[max] = temp;
		PrintSelectSort(a, n, i);
	}
}
void SelectSortTest() {
	int a[] = { 3, 2, 1, 5, 8, 9, 4, 3, 11, 10 };
	int n = sizeof(a) / sizeof(int);
//	SelectSort(a, n);
//	PrintSelectSort(a, n, n);
//	cout << endl << endl;
	SelectTwoSort(a, n);
	PrintSelectSort(a, n, n);
}
/******************������************************/
void PrintHeapSort(int a[], int n) {
	for (int j = 0; j < n; j++) {
		cout << a[j] << "\t";
	}
	cout << endl;
}
void HeapAdjust(int a[], int parent, int length) {
	int temp = a[parent]; //���浱ǰ���ڵ�
	int child = 2 * parent + 1; //��ȡ����
	while (child < length) {
		/*****�󶥶�*******
		 //������к��ӣ����Һ��Ӵ��������ӣ�ѡȡ�Һ��ӽڵ�
		 if (child + 1 < length && a[child] < a[child + 1]) {
		 child++;
		 }
		 // ���������ֵ�Ѿ����ں��ӽ���ֵ����ֱ�ӽ���
		 if (a[parent] >= a[child]) {
		 break;
		 }*/
		/*****С����********/
		//������к��ӣ����Һ���С�������ӣ�ѡȡ�Һ��ӽڵ�
		if (child + 1 < length && a[child] > a[child + 1]) {
			child++;
		}
		// ���������ֵ�Ѿ�С�ں��ӽ���ֵ����ֱ�ӽ���
		if (a[parent] < a[child]) {
			break;
		}
		// �Ѻ��ӽ���ֵ���������
		a[parent] = a[child];
		// ѡȡ���ӽ������ӽ��,��������ɸѡ
		parent = child;
		child = 2 * child + 1;
		a[parent] = temp;
	}
	//PrintHeapSort(a, length);
}
/** 
 * ��ʼ�ѽ��е���
 * ��H[0..length-1]���ɶ�
 * ������֮���һ��Ԫ�������е���С��Ԫ��
 */
void BuildHeap(int a[], int length) {
	for (int i = (length - 1) / 2; i >= 0; --i) {
		HeapAdjust(a, i, length);
	}
}
void HeapSort(int a[], int length) {
	BuildHeap(a, length);
	PrintHeapSort(a, length);
	for (int i = length - 1; i > 0; i--) { //�󶥶�ʱ��˳��С����ʱ������
		int temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		HeapAdjust(a, 0, i);
		PrintHeapSort(a, length);
	}
}
void HeapSortTest() {
	int a[] = { 3, 2, 1, 5, 8, 9, 4, 3, 11, 10 };
	int n = sizeof(a) / sizeof(int);
	HeapSort(a, n);
	PrintHeapSort(a, n);
}
/******************ð������************************/
void PrintBubbleSort(int a[], int n, int i) {
	cout << i << ":";
	for (int j = 0; j < n; j++) {
		cout << a[j] << "\t";
	}
	cout << endl;
}
void BubbleSort(int a[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
		PrintBubbleSort(a, n, i);
	}
}
//����һ��־�Ա���pos,���ڼ�¼ÿ�����������һ�ν��н�����λ�á�
//����posλ��֮��ļ�¼���ѽ�����λ,���ڽ�����һ������ʱֻҪɨ�赽posλ�ü���
void BubbleSort1(int a[], int n) {
	int i = n - 1;
	while (i > 0) {
		int pos = 0;
		for (int j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				pos = j;
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
		i = pos;
		PrintBubbleSort(a, n, i);
	}
}
void BubbleSort2(int a[], int n) {
	int low = 0;
	int high = n - 1;
	int j, temp;
	while (low < high) {
		for (j = low; j < high; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
		--high;
		for (j = high; j > low; --j) {
			if (a[j] < a[j - 1]) {
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
		}
		++low;
		PrintBubbleSort(a, n, n);
	}
}
void BubbleSortTest() {
	int a[] = { 3, 2, 1, 5, 8, 9, 4, 3, 11, 10 };
	int n = sizeof(a) / sizeof(int);
	//BubbleSort(a, n);
	//BubbleSort1(a, n);
	BubbleSort2(a, n);
	PrintBubbleSort(a, n, n);
}
