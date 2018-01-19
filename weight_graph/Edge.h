#ifndef __EDGE_H__
#define __EDGE_H__

#include<iostream>
#include<cassert>


template <typename Weight>
class Edge{
private:
     int a,b;  //这条边的两个顶点
     Weight weight;
public:
     Edge(int a, int b, Weight weight){
          this->a = a;
          this->b = b;
          this->weight = weight;
     }

     int v() { return a; }
     int w() { return b; }
     Weight wt() { return weight; }

     int other(int x) {
          assert ( x == a || x == b);
          return x == a ? b : a ;
     }

     friend ostream& operator<<(ostream& os , const Edge& e){
          os << e.a << "-" << e.b << "-" << e.weight;
          return os;
     }

     // 边的大小比较, 是对边的权值的大小比较
     bool operator<(Edge<Weight>& e){
          return weight < e.wt();
     }
     bool operator<=(Edge<Weight>& e){
          return weight <= e.wt();
     }
     bool operator>(Edge<Weight>& e){
          return weight > e.wt();
     }
     bool operator>=(Edge<Weight>& e){
          return weight >= e.wt();
     }
     bool operator==(Edge<Weight>& e){
          return weight == e.wt();
     }
};

#endif
