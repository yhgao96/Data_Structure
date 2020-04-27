#include<iostream>

using namespace std;

//二分查找法，在有序数组arr[]中，查找target
//如果找到target，返回相应的索引index,没找到的话，返回-1
template<typename T>
int BinarySearch(T arr[], int n, T target){

	int l = 0, r = n - 1;           //在arr[l...r]之中查找target
	while (l <= r){

		//int mid = (l + r) / 2;
		int mid = l + (r - l) / 2;   //这种表示求取mid不会产生溢出的情况
		if (arr[mid] == target)
			return mid;

		//在arr[l...mid-1]中查找target
		if (target < arr[mid])
			r = mid - 1;
		else
			l = mid + 1;           //在arr[mid+1...r]中查找target
	}
	return -1;
}

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6 };
	int n = 6;
	int target = 4;
	int index = BinarySearch(a, n, target);
	cout << index << endl;
	system("pause");
	return 0;
}