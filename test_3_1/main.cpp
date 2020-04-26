#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<ctime>
#include<cassert>

using namespace std;

template<typename Item>  //定义了一个最大堆的类模板
class MaxHeap{
private:
	Item * data;
	int count;
	int capacity;
	void shiftUp(int k){
		while (k>1 && data[k / 2] < data[k]){
			swap(data[k / 2], data[k]);
			k /= 2;
		}
	}
	void shiftDown(int k){
		while (2 * k <= count){
			int j = 2 * k;      //在此轮循环中，data[k]和data[j]交换位置
			if (j + 1 <= count&&data[j + 1]>data[j])
				j += 1;
			if (data[k] >= data[j])
				break;
			swap(data[k], data[j]);
			k = j;
		}
	}
public:
	MaxHeap(int capacity){
		data = new Item[capacity + 1];
		count = 0;
		this->capacity = capacity;
	}
	~MaxHeap(){
		delete[] data;
	}
	int size(){
		return count;
	}
	bool isEmpty(){
		return count == 0;
	}

	void insert(Item item){          //增加一个元素
		assert(count + 1 <= capacity);
		data[count + 1] = item;
		count++;
		shiftUp(count);
	}

	Item extractMax(){             //删除一个元素
		assert(count > 0);
		Item ret = data[1];
		swap(data[1], data[count]);
		count--;
		shiftDown(1);
		return ret;
	}

	void testPrint() {
		cout << "data in heap : " << this->size() << endl;
		for (int i = 1; i <= this->size(); i++) {
			cout << this->data[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	MaxHeap<int> maxheap = MaxHeap<int>(100);   //定义了一个堆
	//cout << maxheap.size() << endl;

	srand(time(NULL));
	for (int i = 0; i < 100; i++){
		maxheap.insert(rand() % 100);
	}
	//maxheap.testPrint();

	while (!maxheap.isEmpty()){
		cout << maxheap.extractMax() << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}