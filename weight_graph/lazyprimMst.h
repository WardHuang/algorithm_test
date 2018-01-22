#ifndef _LAZY_PRIM_MST_H_
#define _LAZY_PRIM_MST_H_

#include<iostream>
#include<vector>
#include<cassert>
#include"Edge.h"
#include"Minheap.h"

using namespace std;

template <typename Graph , typename Weight>
class LazyPrimMst{
private:
     Graph &G;
     bool* marked;
     MinHeap<Edge<Weight> > pq;
     vector<Edge<Weight> > mst;
     Weight mstWeight;

     //visit
     void visited(int k){
          assert( !marked[k]);
          marked[k] = true;

          typename Graph::adjIterator adj(G,k);
          for( Edge<Weight> * e = adj.begin(); !adj.end(); e = adj.next())
               if(!marked[e->other(k)])
                    pq.insert(*e);
     }
public:
     LazyPrimMst(Graph &graph):G(graph),pq(Minheap<Edge<Weight> >(graph.E())){
          //algorithm init
          marked = new bool[G.V()];
          for( int i = 0; i < G.V() ; i++)
               marked[i] = false;
          mst.clear();

          visited(0);
          while( !pq.empty()){

               //visit all line find the smallest line;
               Edge<Weight> e = pq.extractMin();

               if( marked[e.v()] ==  marked[e.w()])
                    continue;

               mst.push_back( e );

               if( !marked[e.v()])
                    visited(e.v());
               else
                    visited(e.w());
          }

          mstWeight = mst[0].wt();
          for(int i = 1; i < mst.size() ;i++)
               mstWeight += mst[i].wt();
     }

     ~LazyPrimMst(){
          delete[] marked;
     }

     vector<Edge<Weight> > mstEdges(){
          return mst;
     }

     Weight result(){
          return mstWeight;
     }

};


#endif
