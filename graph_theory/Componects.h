#ifndef __COMPONENTS_H__
#define __COMPONENTS_H__

#include<iostream>
#include<cassert>

using namespace std;

//无权图的联通分量
template <typename Graph>
class Components{
private:
     bool *visited;
     int ccount;
     Graph &G;
     int *id;

     void dfs( int v ){

          visited[v] = true;
          id[v] = ccount;

          typename Graph::adjIterator adj(G,v);

          for( int i = adj.begin() ; !adj.end() ; i = adj.next() ){
               if( !visited[i] )
                    dfs(i);
          }
     }
public:
     Components(Graph &graph,int v):G(graph){

          visited = new bool[G.V()];
          id = new int[G.V()];
          ccount = 0;

          for( int i = 0 ; i < G.V() ; i++ ){
               visited[i] = false;
               id[i] = -1;
          }

          //求图的联通分量
          for( int i = 0; i < G.V() ; i++ ){
               if( !visited[i] ){
                    dfs(i);
                    ccount ++;
               }
          }
     }

     ~Components(){
          delete[] visited;
          delete[] id;
     }

     int count(){
          return ccount;
     }

     bool isConnected( int v , int w ){

          assert( v >= 0 && v < G.V() );
          assert( w >= 0 && w < G.V() );

          return id[v] == id[w];
     }
};

#endif
