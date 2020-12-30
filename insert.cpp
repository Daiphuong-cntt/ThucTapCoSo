
// C++ program for insertion sort  
#include <bits/stdc++.h> 
#include <iostream>
#include <time.h>
#include <cstdio>
using namespace std; 
  
/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}  
  
// A utility function to print an array of size n  
void printArray(int arr[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl; 
}  
  
/* Driver code */
int main()  
{  
    int arr[] = { 5, 10, 15, 20, 25, 50, 40, 30, 20, 10, 9524, 878, 17, 1, 99, 18785, 3649, 164, 94,
		123, 432, 654, 3123, 654, 2123, 543, 131, 653, 123, 533, 1141, 532, 213, 2241, 824, 1124, 42, 134, 411,
		491, 341, 1234, 527, 388, 245, 1992, 654, 243, 987 };  
    int n = sizeof(arr) / sizeof(arr[0]);  
    clock_t start = clock();
    insertionSort(arr, n);  
     
     printf("Time: %.9fs\n", (double)(clock() - start)/CLOCKS_PER_SEC);
     printArray(arr, n); 
     getchar();
    return 0;  
}  