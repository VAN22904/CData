/*
 * MySort.cpp
 *
 *  Created on: 2016年9月20日
 *      Author: Administrator
 */
#include "MySort.h"
//二路一次归并过程的算法
//low为本次二路归并排序的第1有序区的第1个元素，i指向第1个元素, mid为第1有序区的最后1个元素
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
//递归实现二路归并
void mergeSort1(int *list, int low, int high) {
	//二路归并排序，分为两路
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
//非递归方式实现二路归并排序 length代表数组长度
void mergeSort2(int *list, int length) {
	int size = 1;
	int low, mid, high;
	//size 用来标识小区间的大小，1,2,4.。。。
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
/******************直接插入排序************************/
void PrintDirectInsertSort(int a[], int n, int i) {
	cout << i << ":";
	for (int j = 0; j < n; j++) {
		cout << a[j] << "\t";
	}
	cout << endl;
}

void DirectInsertSort(int a[], int n) {
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) { //找到小数
			int j = i - 1;
			int x = a[i]; //复制为哨兵，即存储待排序元素
			a[i] = a[i - 1]; //大数后移一次
			while (x < a[j] && j > -1) {
				a[j + 1] = a[j]; //找到小数应该在的位置
				j--;
			}
			a[j + 1] = x; //插入小数
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
/******************二分插入排序************************/
void PrintBinaryInsertSort(int a[], int n, int i) {
	cout << i << ":";
	for (int j = 0; j < n; j++) {
		cout << a[j] << "\t";
	}
	cout << endl;
}

void BinaryInsertSort(int a[], int n) {
	//刚开始设有序序列只有一个元素 a[0],无序序列为[1...n]了
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) { //找到小数
			//当无序序列元素比有序序列最后一个元素小时，利用二分查找法在有序序列中查找插入位置
			int low = 0;
			int high = i - 1;
			int mid = 0;
			int x = a[i]; //复制为哨兵，即存储待排序元素

			while (low <= high) {
				mid = (low + high) / 2;
				if (x >= a[mid]) {
					low = mid + 1;
				} else {
					high = mid - 1;
				}
			}
			//low位置就是要插入的位置,所以low到i之间的元素都需要往后移动一个位置
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
/******************二路插入排序************************/
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
		if (a[i] < temp[first]) { // 待插入元素比最小的元素小
			first = (first - 1 + n) % n;
			temp[first] = a[i];
		} else if (a[i] > temp[final]) { // 待插入元素比最大元素大
			final = (final + 1 + n) % n;
			temp[final] = a[i];
		} else { // 插入元素比最小大，比最大小
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
/******************希尔排序（缩小增量排序）************************/
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
/******************选择排序************************/
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
/******************堆排序************************/
void PrintHeapSort(int a[], int n) {
	for (int j = 0; j < n; j++) {
		cout << a[j] << "\t";
	}
	cout << endl;
}
void HeapAdjust(int a[], int parent, int length) {
	int temp = a[parent]; //保存当前父节点
	int child = 2 * parent + 1; //获取左孩子
	while (child < length) {
		/*****大顶堆*******
		 //如果有有孩子，且右孩子大于做孩子，选取右孩子节点
		 if (child + 1 < length && a[child] < a[child + 1]) {
		 child++;
		 }
		 // 如果父结点的值已经大于孩子结点的值，则直接结束
		 if (a[parent] >= a[child]) {
		 break;
		 }*/
		/*****小顶堆********/
		//如果有有孩子，且右孩子小于做孩子，选取右孩子节点
		if (child + 1 < length && a[child] > a[child + 1]) {
			child++;
		}
		// 如果父结点的值已经小于孩子结点的值，则直接结束
		if (a[parent] < a[child]) {
			break;
		}
		// 把孩子结点的值赋给父结点
		a[parent] = a[child];
		// 选取孩子结点的左孩子结点,继续向下筛选
		parent = child;
		child = 2 * child + 1;
		a[parent] = temp;
	}
	//PrintHeapSort(a, length);
}
/** 
 * 初始堆进行调整
 * 将H[0..length-1]建成堆
 * 调整完之后第一个元素是序列的最小的元素
 */
void BuildHeap(int a[], int length) {
	for (int i = (length - 1) / 2; i >= 0; --i) {
		HeapAdjust(a, i, length);
	}
}
void HeapSort(int a[], int length) {
	BuildHeap(a, length);
	PrintHeapSort(a, length);
	for (int i = length - 1; i > 0; i--) { //大顶堆时，顺序；小顶堆时，逆序
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
/******************冒泡排序************************/
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
//设置一标志性变量pos,用于记录每趟排序中最后一次进行交换的位置。
//由于pos位置之后的记录均已交换到位,故在进行下一趟排序时只要扫描到pos位置即可
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
/******************快速排序************************/
void PrintQuickSort(int a[], int n, int i) {
	cout << i << ":";
	for (int j = 0; j < n; j++) {
		cout << a[j] << "\t";
	}
	cout << endl;
}
void QuickSort(int a[], int left, int right) {
	if (left > right)
		return;
	int proKey = a[left];
	int i, j;
	i = left;
	j = right;
	while (i != j) {
		while (a[j] >= proKey && j > i) {
			j--;
		}
		while (a[i] <= proKey && i < j) {
			i++;
		}
		if (i < j) {
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
	}
	a[left] = a[i];
	a[i] = proKey;
	//显示排序轨迹
	//PrintQuickSort(a, 10, i);
	QuickSort(a, left, i - 1);
	QuickSort(a, i + 1, right);
}
void QuickSortTest() {
	int a[] = { 3, 2, 1, 5, 8, 9, 4, 3, 11, 10 };
	int n = sizeof(a) / sizeof(int);
	QuickSort(a, 0, n - 1);
	PrintQuickSort(a, n, n);
}
/******************基数排序************************/
void PrintRadixSort(int a[], int n, int i) {
	cout << i << ":";
	for (int j = 0; j < n; j++) {
		cout << a[j] << "\t";
	}
	cout << endl;
}
//得到最大数字位数
int getNums(int a[], int n) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	int j = 1;
	while (max >= 10) {
		j++;
		max /= 10;
	}
	return j;
}
//得到某位上的数字,最大支持5位数
int getDigit(int x, int d) {
	int temp[] = { 1, 10, 100, 1000, 10000 };
	return ((x / temp[d - 1]) % 10);
}
//n长度，radix基数个数
void RadixSort(int a[], int n, int radix) {
	int *count = (int *) malloc(sizeof(int) * radix);
	int *bucket = (int *) malloc(sizeof(int) * n);
	int digit = getNums(a, n);	//得到最大数字位数
	int i = 0, j = 0;
	//LSD 从低位到高位排序
	for (int d = 1; d <= digit; d++) {
		//清空计数
		for (i = 0; i < radix; i++) {
			count[i] = 0;
		}
		//统计各个桶要装入数据的个数
		for (i = 0; i < n; i++) {
			j = getDigit(a[i], d);
			count[j]++;
		}
		// count[i]表示第i个桶的右边界索引,将桶映射到数组
		//--|---|----|-----|
		for (i = 1; i < radix; i++) {
			count[i] = count[i] + count[i - 1];
		}
		// 将数据依次装入桶中
		// 这里要从右向左扫描，保证排序稳定性
		for (i = n - 1; i >= 0; i--) {
			j = getDigit(a[i], d);
			bucket[count[j] - 1] = a[i];		//根据索引，得到桶对应数组的位置，从后向前
			count[j]--;
		}
		for (i = 0; i < n; i++) {
			a[i] = bucket[i];
		}
		PrintRadixSort(a, n, d);
	}

	free(count);
	free(bucket);
}
void RadixSortTest() {
	int a[] = { 3, 500, 10, 1012, 100, 6 };
	int n = sizeof(a) / sizeof(int);
	//cout << getNums(a, n) << endl;
	//cout << getDigit(68935, 4) << endl;
	RadixSort(a, n, 10);
	PrintRadixSort(a, n, n);
}
/******************外排序************************/
#include <stdio.h>
#include <time.h>
#include <math.h>
//在文件中随机产生m个数据，每个一行
void OutSortGenData(char *fileName, int m) {
	FILE *fp = fopen(fileName, "w");
	if (fp == NULL) {
		printf("open file failed \n");
		exit(-1);
	}
	srand(time(0));
	for (int i = 0; i < m; i++) {
		int temp = (rand() << 15) | rand();	//rand一般产生15位随机数(32767)，扩展成30位
		fprintf(fp, "%d\n", temp);
	}
	fclose(fp);
}
void OutSortSplit(char *fileName, int m, int n) {
	FILE *in = fopen(fileName, "r");
	int *buf = (int *) malloc(sizeof(int) * n);
	int k = ceil(double(m) / n);
	for (int i = 0, j; i < k; i++) {
		for (j = 0; j < n; j++) {
			if (fscanf(in, "%d", buf + j) != 1)
				break;
		}
		int num = j;
		QuickSort(buf, 0, num - 1);
		char tempfile[20];
		sprintf(tempfile, "./res/tempfile_%d.txt", i);
		FILE *out = fopen(tempfile, "w");
		for (j = 0; j < num; j++) {
			fprintf(out, "%d\n", buf[j]);
		}
		fclose(out);
	}
	free(buf);
}
typedef struct ospair {
	int num;
	int pos;
} OPair;
void OutSortAdjust(OPair a[], int parent, int length) {
	OPair temp = a[parent]; //保存当前父节点
	int child = 2 * parent + 1; //获取左孩子
	while (child < length) {
		/*****小顶堆********/
		//如果有有孩子，且右孩子小于做孩子，选取右孩子节点
		if (child + 1 < length && a[child].num > a[child + 1].num) {
			child++;
		}
		// 如果父结点的值已经小于孩子结点的值，则直接结束
		if (a[parent].num < a[child].num) {
			break;
		}
		// 把孩子结点的值赋给父结点
		a[parent] = a[child];
		// 选取孩子结点的左孩子结点,继续向下筛选
		parent = child;
		child = 2 * child + 1;
		a[parent] = temp;
	}
	//PrintHeapSort(a, length);
}
/**
 * 初始堆进行调整
 * 将H[0..length-1]建成堆
 * 调整完之后第一个元素是序列的最小的元素
 */
void OutSortBuildHeap(OPair a[], int length) {
	for (int i = (length - 1) / 2; i >= 0; --i) {
		OutSortAdjust(a, i, length);
	}
}
void OutSortMerge(char *outfile, int m, int n) {
	FILE *out = fopen(outfile, "w");
	int k = ceil((double) m / n);
	OPair *buf = (OPair *) malloc(sizeof(OPair) * k);
	FILE **fp = (FILE **) malloc(sizeof(FILE*) * k);
	for (int i = 0; i < k; i++) {
		*(fp + i) = (FILE*) malloc(sizeof(FILE));
		char tempfile[20];
		sprintf(tempfile, "./res/tempfile_%d.txt", i);
		fp[i] = fopen(tempfile, "r");
		int tem;
		fscanf(fp[i], "%d", &tem);
		buf[i].num = tem;
		buf[i].pos = i;
	}
	OutSortBuildHeap(buf, k);
	int nums = 0;
	while (1) {
		int minNum = buf[0].num;
		int minPos = buf[0].pos;
		if (nums == m)
			break;
		fprintf(out, "%d\n", minNum);
		int tem;
		fscanf(fp[minPos], "%d", &tem);
		buf[0].num = tem;
		OutSortBuildHeap(buf, k);
		nums++;
	}
	for (int i = 0; i < k; i++) {
		fclose(fp[i]);
		free(fp[i]);
	}
	free(*fp);
	free(buf);
	fclose(out);
}
void OutSortTest() {
	char src[] = "./res/src.txt";
	char result[] = "./res/result.txt";
	int m = 200, n = 20;
	OutSortGenData(src, m);
	OutSortSplit(src, m, n);
	OutSortMerge(result, m, n);
}
