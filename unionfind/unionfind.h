#ifndef _UNIONFIND_H_
#define _UNIONFIND_H_
#include<cassert>

namespace UF{
     class UnionFind{
     private:
          int *parent;
          int *sz;
          int *rank;
          int count;
     public:
          UnionFind(int n){
               parent = new int[n];
               sz = new int[n];
               rank = new int[n];
               count = n;

               for(int i = 0 ; i < n ; i++){
                    parent[i] = i;
                    sz[i] = 1;
                    rank[i] = 1;
               }
          }

          ~UnionFind(){
               delete []parent;
               delete []sz;
          }

          int find(int p){
               assert( p >= 0 && p <= count );

               while(p != parent[p]){
                    //p = parent[p];
                    parent[p] = parent[parent[p]];
                    p = parent[p];
               }

               return p;
          }
          //union-find's  find
          bool isConnect(int p,int q){
               return find(p) == find(q);
          }
          //union-find's  union
          //base on size() optimize
          void unionElementsBaseSize(int p, int q){

               int pRoot = find(p);
               int qRoot = find(q);

               if(pRoot == qRoot)
                    return;
               //a less numble add to a more numble;
               if( sz[pRoot] < sz[qRoot]){
                    parent[pRoot] = qRoot;
                    sz[qRoot] += sz[pRoot];
               }else {
                    parent[qRoot] = pRoot;
                    sz[pRoot] += sz[qRoot];
               }
          }

          void unionElementsbaseRank(int p, int q){

               int pRoot = find(p);
               int qRoot = find(q);

               if(pRoot == qRoot)
                    return;

               if(rank[pRoot] < rank[qRoot])
                    parent[pRoot] = qRoot;
               else if(rank[qRoot] < rank[pRoot])
                    parent[qRoot] = pRoot;
               else{

                    parent[pRoot] = qRoot;
                    rank[pRoot] += 1;
               }
          }
     };
}
#endif
