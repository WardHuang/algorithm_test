#include<iostream>
#include"SortTestHelper.h"

template<typename T>
int __partition(T arr[],int l, int r)
{
     T v = arr[l];

     int j = l;

     for(int i =l + 1; i <= r; i++){
          if(arr[i] < v)
               swap(arr[++j] , arr[i]);
     }

     swap(arr[l],arr[j]);
     return j;
}


template<typename T>
void __quicksort(T arr[],int l, int r)
{
     if( l >= r)
          return;
     int p = __partition(arr,l,r);
     __quicksort(arr,l,p-1);
     __quicksort(arr,p+1,r);
}

template<typename T>
void quicksort(T arr[],int n)
{
     __quicksort(arr,0,n-1);
}

int main()
{
     int n = 100000;
     int *arr = SortTestHelper::generateRandomArray(n,0,n);
     SortTestHelper::testPraTime("quicksort:",quicksort,arr,n);
     return 0;
}
