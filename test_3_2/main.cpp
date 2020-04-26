#include<iostream>
#include<algorithm>
#include"Heap.h"
#include"SortTestHelper.h"
#include"QuickSort.h"


using namespace std;

template<typename T>
void heapSort1(T arr[], int n){
	MaxHeap<T> maxheap = MaxHeap<T>(n);
	for (int i = 0; i < n; i++){
		maxheap.insert(arr[i]);             //依次将数组中的元素放入到最大堆当中
	}
	for (int i = n - 1; i >= 0; i--)
		arr[i] = maxheap.extractMax();
}
int main()
{
	int n = 10000;
	cout << "Test for Random Array,size = " << n << ",random range [0, " << n << "]" << endl;
	int *arr1 = SortTestHelper::generateRandArray(n, 0, n);
	int *arr2 = SortTestHelper::copyIntArray(arr1, n);

	//比较两种排序的运行时间
	SortTestHelper::testSort("Heap Sort", heapSort1, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
	delete[] arr1;
	delete[] arr2;

	system("pause");
	return 0;
}