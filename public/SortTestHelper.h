#ifndef SORTTESTHELPER_H
#define SORTTESTHELPER_H
#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<cassert>
using namespace std;


namespace SortTestHelper{
     int* generateRandomArray(int n,int rangeL,int rangeR){
          int* arr = new int[n];
          assert(rangeL <= rangeR);
          srand(time(NULL));
          for(int i = 0;i < n;i++)
              arr[i] = rand()%( rangeR - rangeL + 1) + rangeL;

          return arr;
     }

     int* generateNearlyOrderedArray(int n, int swaptimes)
     {
          int *arr = new int[n];
          for(int i = 0; i < n; i++)
               arr[i] = i;

          srand(time(NULL));
          for(int i = 0 ; i < swaptimes ; i++){
               int posx = rand()%n;
               int posy = rand()%n;
               swap(arr[posx],arr[posy]);
          }
          return arr;
     }
     template <typename T>
     void printArray(T arr[],int n){
          for(int i = 0 ; i < n ; i++){
               cout << arr[i] << endl;
          }
     }

     template<typename T>
     bool isSort(T arr[],int n)
     {
          for(int i = 1 ; i < n ; i++)
               if(arr[i] < arr[i - 1])
                    return false;
          return true;
     }
     template<typename T>
     void testPraTime(const string &sname,void (*test)(T[] ,int) ,T arr[],int n)
     {
          clock_t startime = clock();
          test(arr,n);
          clock_t endtime = clock();
          std::cout << sname << ":" << double(endtime - startime)/CLOCKS_PER_SEC << " s" << std::endl;
          assert(isSort(arr,n));
          return;
     }
}
#endif

