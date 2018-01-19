#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

//稠密图 邻接矩阵
class DenseGraph{

private:
     int n,m; //n description node,m description line;
     bool direct; //是否为有向图
     vector<vector<bool> > g; //图中具体的数据
public:
     DenseGraph(int n, bool direct){
          assert( n >= 0 );
          this->n = n;
          this->m = 0;
          this->direct = direct;
          //g is n*n matrix 初始为没有任何边
          g = vector<vector<bool> >(n,vector<bool>(n,false));
     }

     ~DenseGraph(){
     }

     int V() { return n;}
     int E() { return m;}

     //add a line to graph
     void addEdge(int v,int w){
          assert( v >= 0 && v < n);
          assert( w >= 0 && w < n);

          if( hasEdge( v,m ) )
               return;
          g[v][w] = true;     //@ 
          if( !direct )
               g[w][v] = true;  //检查是不是有向图 若是 @ 处设置即可。

          m++;
     }

     bool hasEdge( int v,int w ){

          assert( v >= 0 && v < n);
          assert( w >= 0 && w < n);

          return g[v][w];
     }
     class adjIterator{
     private:
          int index;
          int v;
          DenseGraph &G;
     public:
          adjIterator(DenseGraph &graph, int v):G(graph){
               this->v = v;
               index = -1;
          }

          ~adjIterator(){
          }
          int begin(){
               index = -1;
               return next();
          }

          int next(){

               for( index += 1 ; index < G.V() ; index++ )
                    if( G.g[v][index] )
                         return index;
               return -1;
          }

          bool end(){
               return index >= G.V();
          }
     };
};
