#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

template <typename T>
void selectsort(T a[],int n)
{
     int i ;
     for( i = 0 ; i < n ; i++){
          int min = i;
          for(int j = i+1;j < n;j++){
               if(a[j] < a[min])
                    min = j;
          }
          swap(a[min],a[i]);
     }
}

int main()
{
     int arr1[10] = { 10,9,8,7,6,5,4,3,2,1};
     selectsort(arr1,10);
     for(int i = 0 ; i < 10; i++)
          cout << arr1[i] << " " ;
     cout << endl;
     float arr2[10] = { 10.1,9.2,8.3,7.4,6.5,5.6,4.7,3.8,2.9,1.10};
     selectsort(arr2,10);
     for(int i = 0 ; i < 10; i++)
          cout << arr2[i] << " " ;
     cout << endl;
     string arr3[6] = { "A", "B" , "E" , "C" ,"T" , "F"};
     selectsort(arr3,6);
     for(int i = 0 ; i < 6; i++)
          cout << arr3[i] << " " ;
     cout << endl;
     return 0;
}
