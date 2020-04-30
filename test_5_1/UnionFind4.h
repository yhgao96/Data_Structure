#ifndef UNIONFIND_UNIONFIND4_H
#define UNIONFIND_UNIONFIND4_H

#include<cassert>

using namespace std;

namespace UF4{
	class UnionFind{
	private:
		int* parent;
		int* rank;
		int count;

	public:
		UnionFind(int count){
			parent = new int[count];
			rank = new int[count];
			this->count = count;
			for (int i = 0; i < count; i++){
				parent[i] = i;
				rank[i] = i;
			}
		}
		~UnionFind(){
			delete[] parent;
			delete[] rank;
		}
		int find(int p){
			assert(p >= 0 && p < count);
			/*while (p != parent[p]){
				parent[p] = parent[parent[p]];
				p = parent[p];
			}
			return p;*/
			if (p != parent[p])
				parent[p] = find(parent[p]);
			return parent[p];
		}
		bool isConnected(int p, int q){
			return find(p) == find(q);
		}
		void unionElements(int p, int q){
			int pRoot = find(p);
			int qRoot = find(q);

			if (pRoot == qRoot)
				return;
			if (rank[pRoot] < rank[qRoot]){
				parent[pRoot] = qRoot;
			}
			else if (rank[qRoot]<rank[pRoot]){
				parent[qRoot] = pRoot;
			}
			else{
				parent[pRoot] = qRoot;
				rank[qRoot] += 1;
			}
		}
	};
}

#endif