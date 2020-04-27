#include<iostream>

using namespace std;

//���ֲ��ҷ�������������arr[]�У�����target
//����ҵ�target��������Ӧ������index,û�ҵ��Ļ�������-1
template<typename T>
int BinarySearch(T arr[], int n, T target){

	int l = 0, r = n - 1;           //��arr[l...r]֮�в���target
	while (l <= r){

		//int mid = (l + r) / 2;
		int mid = l + (r - l) / 2;   //���ֱ�ʾ��ȡmid���������������
		if (arr[mid] == target)
			return mid;

		//��arr[l...mid-1]�в���target
		if (target < arr[mid])
			r = mid - 1;
		else
			l = mid + 1;           //��arr[mid+1...r]�в���target
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