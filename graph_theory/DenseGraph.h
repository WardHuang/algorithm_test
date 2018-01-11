#include<iostream>


class DenseGraph{

private:
     int n,m; //n description node,m description line;
     bool direct;
     vector<vector<bool>> g;
public:
     DenseGraph(int n, bool direct){
          assert( n >= 0 );
          this->n = n;
          this->direct = direct;
          //g is n*n matrix
          g = vector<vector<bool>>(n,vector<bool>(n,false));
     }

     ~DenseGraph(){
     }

     int V() { return n;}
     int E() { return m;}

     //add a line to graph
     void addEdge(int v,int w){

     }
};
