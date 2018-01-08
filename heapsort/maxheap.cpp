#include<iostream>
#include<string>
#include<cassert>
#include<ctime>
#include<algorithm>

template<typename Item>
class MaxHeap{
public:
     MaxHeap(int capacity){
          Itemarr = new Item[capacity+1];
          count = 0;
          this->capacity = capacity;
     }

     int size(){
          return count;
     }

     bool isEmpty(){
          return count == 0;
     }

     void insert(Item item){
          assert( count+1 <= capacity);
          data[count+1] = item;
          count ++;
          shiftUp(count);
     }
     ~MaxHeap(){
          delete[] Itemarr;
     }
private:
     Item* Itemarr;
     int count;
     int capacity;

     void shiftUp(int k){
          while(k > 1 && Itemarr[k/2] < Itemarr[k]){
               swap(Itemarr[k/2],Itemarr[k]);
               k /= 2;
          }
     }
};

int main()
{
     MaxHeap<int> heap = MaxHeap<int>(10);
     std::cout << heap.size() << std::endl;
     return 0;
}
