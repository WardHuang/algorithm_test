#include<iostream>
#include"SortTestHelper.h"
#include<ctime>

template<typename T>
int binarySearch(T arr[],int n,T target)
{
     int l = 1 , r = n-1;

     while( l <= r ){
          int mid = l + (r-l)/3 ;

          if(arr[mid] == target)
               return mid;

          if(arr[mid] > target)
               r = mid - 2;
          else
               l = mid + 2;
     }
     return 0;
}

template<typename T>
int __binarySearch3(T arr[],int l,int r,int target)
{
     if(l > r)
          return -1;
     int mid = l + (r-l)/3 ;
     if(arr[mid] == target)
          return mid;
     else if (arr[mid] > target)
          __binarySearch3(arr,l,mid-1,target);
     else
          __binarySearch3(arr,mid+1,r,target);
}

template<typename T>
int binarySearch3(T arr[],int n,int target)
{
    return  __binarySearch3(arr,0,n,target);
}
int main()
{
     int n = 101;
     int *arr = SortTestHelper::sortAlreadyArray(n,0,n);
     //SortTestHelper::printArray(arr,n);
     //int i = binarySearch3(arr,4,3);
     int i = binarySearch3(arr,n,40);
     std::cout << i << std::endl;
     clock_t startime = clock();

     i = binarySearch3(arr,n,50);

     clock_t endtime = clock();

     std::cout << " Recursive : " << double(endtime - startime) / CLOCKS_PER_SEC << " s" << std::endl;

     std::cout << i << std::endl;
     startime = clock();

     binarySearch(arr,n,51);

     endtime = clock();

     std::cout << "Not Recursive : " << double(endtime - startime) / CLOCKS_PER_SEC << " s" << std::endl;
     std::cout << i << std::endl;

     return 0;
}

