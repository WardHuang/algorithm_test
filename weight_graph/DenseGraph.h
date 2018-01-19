#include<iostream>
#include<vector>
#include<cassert>
#include"Edge.h"

using namespace std;

//稠密图 邻接矩阵
template <typename weight>
class DenseGraph{

private:
     int n,m; //n description node,m description line;
     bool direct; //是否为有向图
     vector<vector<Edge<weight> *> > g; //图中具体的数据
public:
     DenseGraph(int n, bool direct){
          assert( n >= 0 );
          this->n = n;
          this->m = 0;
          this->direct = direct;
          //g is n*n matrix 初始为没有任何边
          g = vector<vector<Edge<weight> *> >(n,vector<Edge<weight> *>(n,NULL));
     }

     ~DenseGraph(){
          for(int i = 0 ; i < n ; i ++)
               for(int j = 0 ; j < n ; j++)
                    if(g[i][j] != NULL)
                         delete g[i][j];
     }

     int V() { return n;}
     int E() { return m;}

     //add a line to graph
     void addEdge(int v,int w){
          assert( v >= 0 && v < n);
          assert( w >= 0 && w < m);

          if( hasEdge( v,m ) ){
               delete g[v][m];
               if(v != w &&  !direct )
                    delete g[w][v];  //检查是不是有向图 若是 @ 处设置即可。
               m--;
          }

          g[v][m] = new Edge(v,m,weight);
          if(v != m && !direct )
               g[m][v] = new Edge<weight>(m,v,weight);
          m++;
     }

     bool hasEdge( int v,int w ){

          assert( v >= 0 && v < n);
          assert( w >= 0 && w < n);

          return g[v][w] != NULL;
     }

     void show(){
          for(int i = 0; i < n ; i++){
               for(int j = 0 ; j < n; j++)
                    if(g[i][j])
                         std::cout << g[i][j] ;
                    else
                         std::cout << "NULL";
               std::cout << std::endl;
          }
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
          Edge<weight>*  begin(){
               index = -1;
               return next();
          }

          Edge<weight>*  next(){

               for( index += 1 ; index < G.V() ; index++ )
                    if( G.g[v][index] )
                         return index;
               return NULL;
          }

          bool end(){
               return index >= G.V();
          }
     };
};
