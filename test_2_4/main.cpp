#include<iostream>
#include"SortTestHelper.h"
#include"insertionSort.h"
#include"MergeSort.h"
using namespace std;

int main()
{
	int n = 100000;
	cout << "Test for Random Array,size = " << n << ",random range [0, " << n << "]" << endl;

	// Test Random Array
	int * arr1 = SortTestHelper::generateRandArray(n, 0, n);
	int * arr2 = SortTestHelper::copyIntArray(arr1, n);
	//比较两种排序的运行时间
	SortTestHelper::testSort("Insertion Sort", insertion_sort, arr1, n);
	SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);

	delete[] arr1;
	delete[] arr2;
	cout << endl;

	system("pause");
	return 0;
}