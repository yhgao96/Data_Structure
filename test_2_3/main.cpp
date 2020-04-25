#include<iostream>
#include<algorithm>
#include"SortTestHelper.h"
#include"SelectionSort.h"

using namespace std;

/*template<typename T>
void insertionSort(T arr[], int n){   //插入排序
	for (int i = 1; i < n; i++){
		//寻找元素arr[i]合适的插入位置
		for (int j = i; j > 0; j--){
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
			else
				break;
		}
	}
}*/

//优化插入排序
template <typename T>
void insertionSort(T arr[], int n){
	for (int i = 1; i < n; i++){
		//寻找元素arr[i]合适的插入位置
		T e = arr[i];
		int j;//j保存元素e应该插入的位置
		for (j = i; j > 0 && arr[j - 1]>e; j--){
			arr[j] = arr[j - 1];
		}
		arr[j] = e;
	}
}

int main()
{
	int n = 10000;
	int *arr = SortTestHelper::generateRandArray(n, 0, 3);
	int *arr2 = SortTestHelper::copyIntArray(arr, n);

	//比较两种排序的运行时间
	SortTestHelper::testSort("Insertion Sort", insertionSort, arr, n);  
	SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n);

	delete[] arr;
	delete[] arr2;

	system("pause");
	return 0;
}