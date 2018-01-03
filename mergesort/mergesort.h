#include<iostream>
#include<algorithm>
#include"SortTestHelper.h"
//#include"insertsort
using namespace std;

template<typename T>
void __merge(T arr[],int l , int mid, int r)
{
     T aux[r-l+1];
     for(int i = l ; i <= r;i++){
          aux[i - l] = arr[i];
     }
     int i = l,j = mid + 1;
     for(int k = l; k <= r; k++){
          if(i > mid){
               arr[k] = aux[j-l];
               j++;
          } else if(j > r){
               arr[k] = aux[i-l];
               i++;
          }
          else if( aux[i-l] < aux[j-l]){
               arr[k] = aux[i - l];
               i++;
          }else {
               arr[k] = aux[j-l];
               j++;
          }
     }
}
template<typename T>
void __mergesort(T arr[],int l,int r)
{
     if( l >= r)
          return;
    // int mid = l + ( r - l )/2;
    int mid = (l + r) / 2;
     __mergesort(arr,l,mid);
     __mergesort(arr,mid+1,r);
     __merge(arr,l,mid,r);
}

template<typename T>
void mergesort(T arr[],int n)
{
     __mergesort(arr,0,n-1);
}
/*
int main()
{
     int n = 5;
     int* arr = SortTestHelper::generateRandomArray(n,0,n);
     mergesort(arr,n);
     SortTestHelper::printArray(arr,n);
     return 0;
}
*/
