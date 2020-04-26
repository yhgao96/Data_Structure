#include<iostream>
#include<algorithm>
#include"Heap.h"
#include"HeapSort.h"
#include"SortTestHelper.h"

using namespace std;

template<typename T>
void shiftdown(T arr[], int n, int k){
	while (2 * k+1 <n){
		int j = 2 * k + 1;      //在此轮循环中，arr[k]和arr[j]交换位置
		if (j + 1 <n&&arr[j + 1]>arr[j])
			j += 1;
		if (arr[k] >= arr[j])
			break;
		swap(arr[k], arr[j]);
		k = j;
	}
}

template<typename T>
void heapSort(T arr[], int n){      //原地堆排序
	//heapify
	for (int i = (n - 1) / 2; i >= 0; i--)
		shiftdown(arr, n, i);
	for (int i = n - 1; i > 0; i--){
		swap(arr[0], arr[i]);
		shiftdown(arr, i, 0);
	}
}

int main()
{
	int n = 10000;
	cout << "Test for Random Array,size = " << n << ",random range [0, " << n << "]" << endl;
	int *arr1 = SortTestHelper::generateRandArray(n, 0, n);
	int *arr2 = SortTestHelper::copyIntArray(arr1, n);
	int *arr3 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Heap Sort1", heapSort1, arr1, n);
	SortTestHelper::testSort("Heap Sort2", heapSort2, arr2, n);
	SortTestHelper::testSort("Heap Sort", heapSort, arr3, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;

	system("pause");
	return 0;

}