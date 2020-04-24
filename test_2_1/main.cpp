#include<iostream>
#include<string>
#include<algorithm>
#include"SortTestHelper.h"
#include"Student.h"

using namespace std;

template<typename T>
void selectionSort(T arr[], int n){    //选择排序
	for (int i = 0; i < n; i++){
		//寻找[i,n)区间的最小值
		int minIndex = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[minIndex])
				minIndex = j;
		swap(arr[i], arr[minIndex]);
	}
}

int main(){
	int arr[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	//int *arr = SortTestHelper::generateRandArray(n,0,n);
	selectionSort(arr, 10);
	SortTestHelper::printArray(arr, 10);

	float brr[4] = { 4.4, 3.3, 2.2, 1.1 };
	selectionSort(brr, 4);
	SortTestHelper::printArray(brr, 4);

	string crr[4] = { "D", "B", "A", "C" };
	selectionSort(crr, 4);
	SortTestHelper::printArray(crr, 4);

	Student d[4] = { { "D", 90 }, { "C", 100 }, { "B", 95 }, { "A", 95 } };
	selectionSort(d, 4);
	SortTestHelper::printArray(d, 4);

	//delete[] arr;

	system("pause");
	return 0;
}