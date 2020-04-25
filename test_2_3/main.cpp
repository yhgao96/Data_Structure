#include<iostream>
#include<algorithm>
#include"SortTestHelper.h"
#include"SelectionSort.h"

using namespace std;

/*template<typename T>
void insertionSort(T arr[], int n){   //��������
	for (int i = 1; i < n; i++){
		//Ѱ��Ԫ��arr[i]���ʵĲ���λ��
		for (int j = i; j > 0; j--){
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
			else
				break;
		}
	}
}*/

//�Ż���������
template <typename T>
void insertionSort(T arr[], int n){
	for (int i = 1; i < n; i++){
		//Ѱ��Ԫ��arr[i]���ʵĲ���λ��
		T e = arr[i];
		int j;//j����Ԫ��eӦ�ò����λ��
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

	//�Ƚ��������������ʱ��
	SortTestHelper::testSort("Insertion Sort", insertionSort, arr, n);  
	SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n);

	delete[] arr;
	delete[] arr2;

	system("pause");
	return 0;
}