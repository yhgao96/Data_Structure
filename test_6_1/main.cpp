#include<iostream>
#include<vector>
#include<ctime>
#include"DenseGraph.h"
#include"SparseGraph.h"
#include"ReadGraph.h"
#include"Component.h"

using namespace std;

int main()
{
	/*int N = 20;
	int M = 100;
	srand(time(NULL));

	SparseGraph g1(N, false);
	for (int i = 0; i < M; i++){
		int a = rand() % N;
		int b = rand() % N;
		g1.addEdge(a, b);
	}

	for (int v = 0; v < N; v++){
		cout << v << ": ";
		SparseGraph::adjIterator adj(g1, v);
		for (int w = adj.begin(); !adj.end(); w = adj.next())
			cout << w << " ";
		cout << endl;
	}
	cout << endl;
	
	DenseGraph g2(N, false);
	for (int i = 0; i < M; i++){
		int a = rand() % N;
		int b = rand() % N;
		g2.addEdge(a, b);
	}

	for (int v = 0; v < N; v++){
		cout << v << " : ";
		DenseGraph::adjIterator adj(g2, v);
		for (int w = adj.begin(); !adj.end(); w = adj.next())
			cout << w << " ";
		cout << endl;
	}*/

	string filename1 = "test1.txt";
	SparseGraph g1(13, false);
	ReadGraph<SparseGraph> readGraph1(g1, filename1);
	Component<SparseGraph> component1(g1);
	cout << "Test1.txt,Component Count: " << component1.count() << endl;

	cout << endl;

	string filename2 = "test2.txt";
	SparseGraph g2(7, false);
	ReadGraph<SparseGraph> readGraph2(g2, filename2);
	Component<SparseGraph> component2(g2);
	cout << "Test2.txt,Component count: " << component2.count() << endl;

	system("pause");
	return 0;
}