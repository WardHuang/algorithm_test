#ifndef __READGRAPH_H__
#define __READGRAPH_H__
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cassert>

using namespace std;

template<typename Graph,typename weight>
class ReadGraph{
private:

public:
     ReadGraph(Graph &graph,const string &filename){
          ifstream file(filename);
          string line;
          int V , E;
          //确保文件已经打开
          assert(file.is_open());
          //确保文件读取成功
          assert( getline(file,line) );
          stringstream ss(line);

          ss >> V >> E;

          assert( V == graph.V());

          for( int i = 0; i < E ; i++ ){
               assert( getline(file,line) );

               stringstream ss(line);

               int a, b;
               weight wt;

               ss >> a >> b >> wt;

               assert( a >= 0 && a < V );
               assert( b >= 0 && b < E );

               graph.addEdge(a,b,wt);
          }
     }
};
#endif
