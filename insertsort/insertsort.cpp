#include<iostream>
#include<algorithm>
#include"SortTestHelper.h"
using namespace std;

void insertsort(int arr[],int n)
{
     for(int i = 1 ; i < n ; i++){
          int currval = arr[i];
          int j ;
          for(j = i; j > 0 && arr[j] < arr[j - 1];j--){
               arr[j] = arr[j-1];
          }
          arr[j] = currval;
     }
}

int main()
{
     int *arr = SortTestHelper::generateRandomArray(10000,1,20000);
     insertsort(arr,10000);
     for(int i = 0 ; i <  10000; i++)
          cout << i << endl;
     return 0;
}
