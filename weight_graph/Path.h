#ifndef __PATH_H__
#define __PATH_H__

#include<iostream>
#include<vector>
#include<stack>

using namespace std;

template<typename Graph>
class Path{
private:
     bool *visited; //遍历信息
     int *from;  //上级节点
     int s; //顶点 节点
     Graph &G;

     void dfs(int v){
          assert( v >= 0 && v < G.V() );
          visited[v] = true;

          typename Graph::adjIterator adj(G,v);
          for( int i = adj.begin(); !adj.end(); i = adj.next() )
               if(!visited[i]){
                    from[i] = v;
                    dfs(i);
               }
     }
public:
     Path(Graph &graph, int v):G(graph){

          assert( v >= 0 && v < G.V() );


          visited = new bool[G.V()];
          from = new int[G.V()];

          s = v;
          for(int i = 0; i < G.V(); i++){
               visited[i] = false;
               from[i] = -1;
          }

          dfs(s);
     }

     ~Path(){
          delete[] visited;
          delete[] from;
     }

     bool hasPath(int w){
          assert( w >= 0 && w < G.V() );
          return visited[w];
     }

     void path(int w , vector<int> &vec){

          assert( hasPath(w) );

          stack<int> s;

          int p = w;

          while( p != -1 ){

               s.push(p);
               p = from[p];
          }

          vec.clear();

          while( !s.empty() ){

               vec.push_back(s.top());
               s.pop();
          }
     }

     void showPath( int w ){

          assert( hasPath(w) );

          vector<int> vec;

          path(w,vec);

          for(int i = 0 ; i < vec.size() ; i++ ){
               cout << vec[i];
               if( i == vec.size() - 1 )
                    cout << endl;
               else
                    cout << " -> " ;
          }

     }
};

#endif
