#include<iostream>
#include <bits/stdc++.h> 
#include <ctime>
#include <cstdio>
#include<fstream> 
#include <time.h>
#include <cstdio>
#include<string>
using namespace std;
class Source
{
public:
    char data[100];
    
};
class Sort{
public:
   // string datasource;
    int arr[500];
    char sou[100];

    void print(int array[],int n)
    {
        for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    }

    void laymang(char sou[]){
        FILE *f =fopen(sou,"r");
        if (f == NULL)
	    {
		    cout<<"Can't open file!";
	    } 
        else{
            int so;
            int i=0;
            while (fscanf(f, "%d", &so) != EOF)
	            {
                    arr[i]=so;
                    i++;
	            }
    }
    }
};
class radix:Sort{
    public:
    //Lay so lon nhat trong day
int getMax(int arr[], int n) 
{ 
    int mx = arr[0]; 
    for (int i = 1; i < n; i++) 
        if (arr[i] > mx) 
            mx = arr[i]; 
    return mx; 
} 
//In ra cot tuong ung voi so do, Chieu cao cot bang gia tri /100
// void hinhchunhat(int x1,int y1,int x2,int y2)
// {
// 	line(x1,y1,x1,y2);
// 	line(x1,y2,x2,y2);
// 	line(x2,y2,x2,y1);
// 	line(x2,y1,x1,y1);
// } 
//in ra man hinh day so theo do hoa
// void screen(int arr[], int n)
// {
// 	int xstart=0,ystart=0;
// 	for(int i=0;i<n;i++)
// 	{
// 		hinhchunhat(xstart+i*800/n,0,xstart+(i+1)*800/n,arr[i]/100);
// 	}
// }
//sap xep day so
void countSort(int arr[], int n, int exp) 
{ 
    int output[n];  
    int i, count[10] = { 0 }; 
  
    for (i = 0; i < n; i++) 
        count[(arr[i] / exp) % 10]++; 
  
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
    
    for (i = n - 1; i >= 0; i--) { 
        output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
        count[(arr[i] / exp) % 10]--; 
    } 
  
    
    for (i = 0; i < n; i++) 
        arr[i] = output[i];
		//  screen(arr,n);
        // delay(500);
        // cleardevice(); 
} 
  

void radixsort(int arr[], int n) 
{ 
    // Tim so lon nhat de lay so chu so nhieu nhat
    int m = getMax(arr, n); 
  
    // Thuc hien sap xep theo vi tri chu so, exp la vi tri chu so, i la so hien tai 
    for (int exp = 1; m / exp > 0; exp *= 10)
	{ 
        countSort(arr, n, exp);
       
	}
} 
  
// In mang sau khi sap xep 
void print(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
}

};
class insert:Sort{
    public:
    void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        // Dich chuyen phan tu len truoc neu phan tu lon hon key
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;
		// 	screen(arr,n);
        // delay(10);
        // cleardevice();  
    }
  
}  
  
// ham in mang 
void printArray(int arr[], int n)  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl; 
}
};
int main()
{
    Source s100, s250, s500;
    strcpy(s100.data,"D:\\Thuctapcoso\\ThucTapCoSo\\dauvao100.txt");
    strcpy(s250.data,"D:\\Thuctapcoso\\ThucTapCoSo\\dauvao250.txt");
    strcpy(s500.data,"D:\\Thuctapcoso\\ThucTapCoSo\\dauvao500.txt");
    radix ra;
    insert ins;
    // strcpy(sous,s100.data);
    ra.laymang(s100.data);

    
}