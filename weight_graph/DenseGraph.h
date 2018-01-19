#include<iostream>
#include<vector>
#include<cassert>
#include"Edge.h"

using namespace std;

//稠密图 邻接矩阵
template <typename Weight>
class DenseGraph{

private:
     int n,m; //n description node,m description line;
     bool direct; //是否为有向图
     vector<vector<Edge<Weight> *> > g; //图中具体的数据
public:
     DenseGraph(int n, bool direct){
          assert( n >= 0 );
          this->n = n;
          this->m = 0;
          this->direct = direct;
          //g is n*n matrix 初始为没有任何边
          g = vector<vector<Edge<Weight> *> >(n,vector<Edge<Weight> *>(n,NULL));
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
     void addEdge(int v,int w,Weight weight){
          //cout << v << " : " << w << " " << m <<endl;
          assert( v >= 0 && v < n);
          assert( w >= 0 && w < n);

          if( hasEdge( v,w ) ){
               delete g[v][w];
               if(v != w &&  !direct )
                    delete g[w][v];  //检查是不是有向图 若是 @ 处设置即可。
               m--;
          }

          g[v][w] = new Edge<Weight>(v,m,weight);
          if(v != w && !direct )
               g[w][v] = new Edge<Weight>(w,v,weight);
          m++;
//          cout << "add {" << m << endl;
     }

     bool hasEdge( int v,int w ){
//          cout << v << ":" << w << ":" << n <<endl;
          assert( v >= 0 && v < n);
          assert( w >= 0 && w < n);

          return g[v][w] != NULL;
     }

     void show(){
          for(int i = 0; i < n ; i++){
               for(int j = 0 ; j < n; j++)
                    if(g[i][j])
                         std::cout << g[i][j] << "\t";
                    else
                         std::cout << "NULL\t";
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
          Edge<Weight>*  begin(){
               index = -1;
               return next();
          }

          Edge<Weight>*  next(){

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
