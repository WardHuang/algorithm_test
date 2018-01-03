#include<iostream>
#include"SortTestHelper.h"
#include"insertsort.h"

template<typename T>
void __quick3ways(T arr[],int l,int r)
{
     if( l >= r)
          return ;

     //小数组 插入较快
     if(r - l <= 15){
          insertsort(arr,l,r);
          return ;
     }

     T v = arr[l];
     int lt = l;  // arr[lt ...i) < v 
     int gt = r+1; //arr[gt....r] > v
     int i = l+1;  //arr[lt... i) = v

     while( i < gt ){
          if(arr[i] < v)
               swap(arr[i++],arr[++lt]);
          else if(arr[i] > v)
               swap(arr[i] , arr[--gt]);
          else
               i++;
     }
     swap(arr[l],arr[lt]);
     __quick3ways(arr,l,lt-1);
     __quick3ways(arr,gt,r);

}

template<typename T>
void quick3ways(T arr[],int n)
{
     srand(time(NULL));
     __quick3ways(arr,0,n-1);
}


int main()
{
     int n =  10000;
     int *arr = SortTestHelper::generateRandomArray(n,0,n);
     SortTestHelper::testPraTime("quick3ways:",quick3ways,arr,n);
     return 0;
}
