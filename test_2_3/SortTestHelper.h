#ifndef SELECTIONSORT_SORTTESTHELPER_H
#define SELECTIONSORT_SORTTESRHELPER_H
#include <iostream>
#include <ctime>
#include <cassert>
#include <string>
using namespace std;

namespace SortTestHelper{
	int* generateRandArray(int n, int rangeL, int rangeR){

		assert(rangeL <= rangeR);

		int *arr = new int[n];
		srand(time(NULL));
		for (int i = 0; i < n; i++)
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
		return arr;
	}

	template <typename T>
	bool isSorted(T arr[], int n){
		for (int i = 0; i < n - 1; i++)
			if (arr[i]>arr[i + 1])
				return false;
		return true;
	}

	template<typename T>
	void testSort(const string &sortName, void(*sort)(T[], int), T arr[], int n){
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();
		cout << sortName << ": " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
		assert(isSorted(arr, n));
		return;
	}

	int* copyIntArray(int a[], int n){
		int* arr = new int[n];
		copy(a, a + n, arr);
		return arr;
	}

}

#endif