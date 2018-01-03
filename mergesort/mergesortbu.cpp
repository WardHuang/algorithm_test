//#include<iostream>
#include"mergesort.h"
#include"insertsort.h"

template<typename T>
void mergesortbu(T arr[],int n)
{
     for(int sz = 0; sz < n; sz += 16)
          insertsort(arr,sz,min(sz+15,n-1));
     for(int sz = 16; sz < n;sz += sz)
          for(int i = 0; i +sz < n; i += sz + sz){
               if(arr[i+sz-1] > arr[i+sz])
                    __merge(arr,i,i+sz-1,min(i+sz+sz-1,n-1));
          }
}

int main()
{
     int n = 5000000;
     int *arr = SortTestHelper::generateRandomArray(n,0,n);
     SortTestHelper::testPraTime("mergesrotBu",mergesortbu,arr,n);
     //mergesortbu(arr,n);
     //SortTestHelper::printArray(arr,n);
     return 0;
}
