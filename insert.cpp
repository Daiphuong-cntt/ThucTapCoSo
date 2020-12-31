
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
    int arr[500];
    int i=0;
    FILE *f =fopen("D:\\Thuctapcoso\\ThucTapCoSo\\dauvao500.txt","r");
    if (f == NULL)
	{
		cout<<"Can't open file!";
	} 
    else{
        int so;
        while (fscanf(f, "%d", &so) != EOF)
	        {
                arr[i]=so;
                i++;
	        }
    }
     int n = sizeof(arr) / sizeof(arr[0]);
    clock_t begin = clock();
    insertionSort(arr, n);  
     clock_t end = clock();
	  // cout<<"Time run: "<<(float)(/*end-*/begin)/*/CLOCKS_PER_SEC*/<<" s"<<endl;
      cout<<begin<<"\n"<<end<<"\n";
     printArray(arr, n); 
     getchar();
    return 0;  
}  