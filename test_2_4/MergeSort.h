#ifndef INC_01_MERGE_SORT_MERGESORT_H
#define INC_01_MERGE_SORT_MERGESORT_H

#include "insertionSort.h"

/*
* �鲢�������˼·���£�
*
*  ��������֣����֣�ֱ���ֳ�ֻ��һ��Ԫ�ص����飨���Լ򵥵ļ�����㼶��ʵ����log��N����
*  Ȼ���������С��λ��������кϲ�����
*  ֱ�����ȫ���Ĳ���
*
*  �����л���Ҫ�õ�һ����ʱ�ռ䣬���Թ鲢������ڴ�ռ�����һ�������ĵ�
*  ����˼����ʵ��˵�������Ѿ��ź��������ϲ���һ�����������
*
*  �����ټ򵥵�˵��Nlog��N�������㷨�ļ�˼����ʵ���ǣ�
*      �����зֳ�log��N���Ĳ㼶���ٶ�ÿ���㼶����O(N)������㷨������
* */



// �� arr[l...mid] �� arr[mid+1...r] �����ֽ��й鲢
template <typename T>
void __merge(T arr[], int l, int mid, int r)
{
	// �����ԣ����� aux���������Ч������
	T aux[r - l + 1];
	for (int i = l; i <= r; ++i) {
		aux[i - l] = arr[i];
	}

	int i = l, j = mid + 1;
	for (int k = l; k <= r; ++k) {
		if (i > mid) {
			arr[k] = aux[j - l];
			++j;
		}
		else if (j > r) {
			arr[k] = aux[i - l];
			++i;
		}
		else if (aux[i - l] < aux[j - l]) {
			arr[k] = aux[i - l];
			++i;
		}
		else {
			arr[k] = aux[j - l];
			++j;
		}
	}
}

// �ݹ�ʹ�ù鲢���򣬶�arr[l...r]�ķ�Χ��������
template <typename T>
void __mergeSort(T arr[], int l, int r)
{
	if (l >= r) {
		return;
	}

	int mid = (l + r) / 2;
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid + 1, r);
	__merge(arr, l, mid, r);
}

template <typename T>
void mergeSort(T arr[], int n)
{
	__mergeSort(arr, 0, n - 1);
}


#endif //INC_01_MERGE_SORT_MERGESORT_H