#include<iostream>
#include<cassert>
#include<vector>
#include"Edge.h"
using namespace std;

template <typename Weight>
class SparseGraph{
public:
     SparseGraph(int n, bool directed){
          assert(n >= 0);
          this->n = n;
          this->m = 0;
          this->directed = directed;

          g = vector<vector<Edge<Weight>*> >(n,vector<Edge<Weight>*>());
     }

     ~SparseGraph(){
     }

     int V () { return n; }
     int E () { return m; }

     void addEdge( int v , int w ,Weight weight){

          assert( v >= 0 && v < n );
          assert( w >= 0 && w < n );

          g[v].push_back(new Edge<Weight>(v,w,weight));
          if( !directed )
               g[w].push_back(new Edge<Weight>(w,v,weight));
          m++;
     }

     //这样判断平行边之后，算法变成O(n) 。
     bool hasEdge( int v , int w ){

          assert( v >= 0 && v < n);
          assert( w >= 0 && w < n);

          for( int i = 0 ; i < g[v].size() ; i++ )
               if(g[v][i]->other(v) == w)
                    return true;
          return false;
     }
     // 显示图的信息
    void show(){

        for( int i = 0 ; i < n ; i ++ ){
            cout<<"vertex "<<i<<":\t";
            for( int j = 0 ; j < g[i].size() ; j ++ )
                cout<<"( to:" << g[i][j]->w() << "weight : " << g[i][j]->wt() <<")\t";
            cout<<endl;
        }
    }

private:
     int n;
     int m;
     bool directed;
     vector<vector<Edge<Weight>* > > g;

public:
     class adjIterator{
     private:
          SparseGraph &G;
          int v;
          int index;  //迭代到什么位置
     public:
          adjIterator( SparseGraph &graph, int v):G(graph){
               this->v = v;
               this->index = 0;
          }

          Edge<Weight>* begin() {
               index = 0;
               if( G.g[v].size() )
                    return G.g[v][index];
               return NULL;
          }

          Edge<Weight>* next(){
               index++;
               if( index < G.g[v].size())
                    return G.g[v][index];
               return NULL;
          }

          bool end(){
               return index >= G.g[v].size();
          }
     };
};
