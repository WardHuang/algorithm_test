#ifndef __SHORTESPATH_H__
#define __SHORTESPATH_H__

#include<vector>
#include<queue>
#include<iostream>
#include<stack>

using namespace std;

template <typename Graph>
class ShortPath{
private:
     Graph &G;
     int s; //start point
     int *from; //prev point
     int *visited; //dfs arrived
     int *odr; //odr[i] -> i  distance
public:
     ShortPath(Graph &graph,int v):G(graph){
          this->s = v;
          from = new int[G.V()];
          visited = new int[G.V()];
          odr = new int[G.V()];

          for( int i = 0 ; i < G.V() ; i++ ){
               from[i] = -1;
               odr[i] = -1;
               visited[i] = false;
          }

          queue<int> q;

          q.push(s);
          visited[s] = true;
          from[s] = -1;
          odr[s] = 0;

          while( !q.empty() ){

               int p = q.front();
               q.pop();

               typename Graph::adjIterator adj(G,s);

               for( int i = adj.begin(); !adj.end() ; i = adj.next() ){
                    if( !visited[i] ){
                         q.push(i);
                         visited[i] = true;
                         from[i] = p;
                         odr[i] = odr[v] + 1;
                    }
               }
          }

     }

     ~ShortPath(){
          delete[] odr;
          delete[] visited;
          delete[] from;
     }
private:

     void hasPath( int w ){
          assert( w >= 0 && w < G.V() );
          return visited[w];
     }

     void Path(int w ,vector<int> &vec){
          assert( w >= 0 && w < G.V() );

          stack<int> s;

          int p = w;

          while( p != -1){
               s.push(p);
               p = from[p];
          }

          vec.clear();

          while( !s.empty() ){
               vec.push_back(s.top());
               s.pop();
          }
     }
public:
     void showPath(int w){
          assert( w >= 0 && w < G.V() );

          vector<int> vec;
          Path(w,vec);

          for(int i = 0 ; i < vec.size() ; i++ ){
               cout << vec[i] ;

               if( i == vec.size() - 1 )
                    cout << endl;
               else
                    cout << " -> " ;
          }
     }

     int length( int w ) {

          assert( w >= 0 && w < G.V() );
          return odr[w];
     }
};


#endif
