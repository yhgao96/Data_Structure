#include<iostream>
#include"Heap.h"

using namespace  std;

template<typename T>
void heapSort1(T arr[], int n){
	MaxHeap<T> maxheap = MaxHeap<T>(n);
	for (int i = 0; i < n; i++){
		maxheap.insert(arr[i]);             //依次将数组中的元素放入到最大堆当中
	}
	for (int i = n - 1; i >= 0; i--)
		arr[i] = maxheap.extractMax();
}

template<typename T>
void heapSort2(T arr[], int n)              //Heapify
{
	MaxHeap<T> maxheap = MaxHeap<T>(arr, n);
	for (int i = n - 1; i >= 0; i--)
		arr[i] = maxheap.extractMax();
}
