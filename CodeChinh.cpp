#include <iostream>
#include <bits/stdc++.h> 
#include <ctime>
#include <cstdio>
#include <fstream> 
#include <time.h>
#include <cstdlib>
#include <string>
#include <conio.h>
#include <unistd.h>
#include <graphics.h>

using namespace std;
class Source
{
	public:
    Source()
	{
		
	}
    void DocFile(char* s,int arr[])
    {
        fstream F;
        F.open(s, ios::in);
        if (F.eof())
        {
            cout << "Doc file thanh cong !";
        }
        else
        {
  		    int tam ;
            int i = 0;
            while (F >> tam)
            {
                arr[i] = tam;
                i++;
            }
        }
        F.close();
    }
    void XuatMang(int arr[],int n)
    {
    	cout << "\nMang chua sap xep:\n";
        for(int i = 0 ; i < n ; i++)
        {
            cout << arr[i] << " ";
        }
    }
};
class Source100: public Source
{
	public:
	int dulieu100[100];
	int n = 100;
	Source100(): Source()
	{
	
	}
	void LayMangFile100(char *s, int dulieu100[])
	{
		Source::DocFile(s,dulieu100);	
	}
	void XuatMang100(int dulieu100[],int n)
	{
		Source::XuatMang(dulieu100,n);
	}
};
class Source250: public Source
{
	public:
	int dulieu250[250];
	int n = 250;
	Source250(): Source()
	{
	
	}
	void LayMangFile250(char *s, int dulieu250[])
	{
		Source::DocFile(s,dulieu250);	
	}
	void XuatMang250(int dulieu250[],int n)
	{
		Source::XuatMang(dulieu250,n);
	}
};
class Source500: public Source
{
	public:
	int dulieu500[500];
	int n = 500;
	Source500(): Source()
	{
	
	}
	void LayMangFile500(char *s, int dulieu500[])
	{
		Source::DocFile(s,dulieu500);	
	}
	void XuatMang500(int dulieu500[],int n)
	{
		Source::XuatMang(dulieu500,n);
	}
};
/*====================================================================*/
class Sort
{
	public:
	void inmang(int arr[],int n)
    {
        for (int i = 0 ; i < n ; i++) 
        cout << arr[i] << " "; 
    }
    void hinhchunhat(int x1, int y1, int x2, int y2)
    {
	    line(x1,y1,x1,y2);
	    line(x1,y2,x2,y2);
	    line(x2,y2,x2,y1);
	    line(x2,y1,x1,y1);  
    } 
	//in ra man hinh day so theo do hoa
	void screen(int arr[], int n)
	{
		int xstart = 0, ystart = 0;
		for(int i = 0; i < n; i++)
		{
			hinhchunhat(xstart + i * 800 / n, 0, xstart + ( i + 1 ) * 800 / n,	arr[i] / 100);
		}
	}
};
class MergeSort: public Sort
{	
	public:
	void merge(int arr[], int l, int m, int r)
	{
		// tao 2 mang con
	    int n1 = m - l + 1;
	    int n2 = r - m;
	    int L[n1], R[n2];
	    //  sao chep du lieu vao 2 mang
	    for (int i = 0; i < n1; i++)
	        L[i] = arr[l + i];
	    for (int j = 0; j < n2; j++)
	        R[j] = arr[m + 1 + j];
	        
	    int i = 0;	// khoi tao chi so bat dau cua mang L
		int j = 0;	// khoi tao chi so bat dau cua mang R
		int k = l;	// khoi tao chi so bat dau cua mang luu ket qua
	    // thuc hien tron code
	    while (i < n1 && j < n2)
		{
	        if (L[i] <= R[j]) {
	            arr[k] = L[i];
	            i++;
	        }
	        else {
	            arr[k] = R[j];
	            j++;
	        }
	        k++;
	    }
	    // sao chep cac phan tu con lai vao mang neu co
	    while (i < n1)
		{
	        arr[k] = L[i];
	        i++;
	        k++;
	    }
	    while (j < n2)
		{
	        arr[k] = R[j];
	        j++;
	        k++;
	    }
	}
	// Ham de qui sap xep chinh
	void mergeSort(int arr[], int l, int r)
	{
	    if(l<r)
		{	
			int m = ( l + r ) / 2;
			// de qui tach mang
		    mergeSort(arr, l, m);
		    mergeSort(arr, m+1, r);
		    // tron code 
		    merge(arr, l, m, r);
	    }
	}
	// ---- do hoa minh hoa thuat toan merge
	void mergeSort_dohoa(int arr[], int l, int r)
	{
	    if(l<r)
		{	
			int m = ( l + r ) / 2;
			// de qui tach mang
		    mergeSort(arr, l, m);
		    mergeSort(arr, m+1, r);
		    // tron code 
		    merge(arr, l, m, r);
		    cleardevice();
			Sort::screen(arr,r+1);
			delay(100);
	    }
	}
	//-----------------------------------------
	void InMang(int arr[], int n)
	{
		Sort::inmang(arr, n);
	}
	// tinh thoi gian thuc hien thuat toan MergeSort
	double t_MergeSort (int arr[], int n)
	{
		int l = 0;	// arr bat dau tai l
		int r = n - 1; // ket thuc tai r
		clock_t star = clock();
			mergeSort(arr, l, r);
			sleep(1);
		clock_t end = clock();
		double d = (double)(end - star - 1) / CLOCKS_PER_SEC;
		return d;
	}
};
class HeapSort : public Sort
{
	public:
    // tim max heap
	void heapify(int arr[], int n, int i)
	{
		int largest = i; // khoi tao largest nhu la root
		int l = 2 * i + 1; // left = 2*i + 1
		int r = 2 * i + 2; // right = 2*i + 2
		// Neu nut con trai lon hon so voi root
		if (l < n && arr[l] > arr[largest])
			largest = l;
		// Neu nut con phai lon hon so voi root
		if (r < n && arr[r] > arr[largest])
			largest = r;
		// Neu root khong phai la lon nhat
		if (largest != i)
		{
			swap(arr[i], arr[largest]);
			// De quy lai ham heapify
			heapify(arr, n, largest);
		}
	}
	// Ham vun dong
	void heapSort(int arr[], int n)
	{
		// Tao mot dong (Sap xep lai mang)
		for (int i = n / 2 - 1; i >= 0; i--)
			heapify(arr, n, i);
		for (int i = n - 1; i >= 0; i--)
		{
			// Di chuyen root ve cuoi cung
			swap(arr[0], arr[i]);
			// goi ham heapify
			heapify(arr, i, 0);
		}
	}
	// ---Do hoa thuat toan Heap Sort ------
	void heapSort_dohoa(int arr[], int n)
	{
		// Tao mot dong (Sap xep lai mang)
		for (int i = n / 2 - 1; i >= 0; i--)
		{
			heapify(arr, n, i);
			cleardevice();
			Sort::screen(arr,n);
			delay(100);
		}
		for (int i = n - 1; i >= 0; i--)
		{
			// Di chuyen root ve cuoi cung
			swap(arr[0], arr[i]);
			// goi ham heapify
			heapify(arr, i, 0);
			cleardevice();
			Sort::screen(arr,n);
			delay(100);
		}
	}
	void InMang (int arr[], int n)
	{
		Sort::inmang(arr, n);
	}
	// tinh thoi gian thuc hien thuat toan HeapSort
	double t_HeapSort(int arr[], int n)
	{
		clock_t star = clock();
			heapSort(arr, n);
			sleep(1);
		clock_t end = clock();
		double d = (double)(end - star - 1) / CLOCKS_PER_SEC;
		return d;
	}
};
void laymang(Source100 &s100,Source250 &s250,Source500 &s500)
{
	s100.LayMangFile100("D:\\dauvao100.txt",s100.dulieu100);
    s250.LayMangFile250("D:\\dauvao250.txt",s250.dulieu250);
	s500.LayMangFile500("D:\\dauvao500.txt",s500.dulieu500);	
}
int main()
{
	initwindow(800,1000);
	Source100 s100;
	Source250 s250;
	Source500 s500;
	
	MergeSort ms100, ms250, ms500;
	HeapSort hs100, hs250, hs500;
	
	double sumMS100=0, sumMS250=0, sumMS500=0;
	double sumHS100=0, sumHS250=0, sumHS500=0;
	
	// tinh thoi gian trung binh sau 10 lan thuc hien
	cout << "Size\t\t100\t250\t500";
	for(int i= 0;i<10;i++)
	{
		sumMS100 = sumMS100 + ms100.t_MergeSort(s100.dulieu100,s100.n);
		sumMS250 = sumMS250 + ms250.t_MergeSort(s250.dulieu250,s250.n);
		sumMS500 = sumMS500 + ms500.t_MergeSort(s500.dulieu500,s500.n);
		
		sumHS100 = sumHS100 + hs100.t_HeapSort(s100.dulieu100,s100.n);
		sumHS250 = sumHS250 + hs250.t_HeapSort(s250.dulieu250,s250.n);
		sumHS500 = sumHS500 + hs500.t_HeapSort(s500.dulieu500,s500.n);
	}
	cout << "\nMerge Sort :\t" << sumMS100/10 << "\t" << sumMS250/10 << "\t" << sumMS500/10;
	cout << "\nHeap Sort :\t" << sumHS100/10 << "\t" << sumHS250/10 << "\t" << sumHS500/10;
	
	// bieu dien do hoa
	int lc;
	cout << "\n\nDo hoa minh hoa:\n(1: Do hoa Merge Sort| 2: Do hoa Heap Sort)" << endl;
   	cout << ">>";	cin >> lc;
   	if(lc == 1)
   	{	// minh hoa qua trinh sap xep voi dau vao 100
   		laymang(s100,s250,s500);
   		ms100.mergeSort_dohoa(s100.dulieu100,0,s100.n-1);
 		//ms250.heapSort_dohoa(s250.dulieu250,0,s250.n-1);
 		//ms500.heapSort_dohoa(s500.dulieu500,0,s250.n-1);
   	}
   	if(lc == 2)
   	{	// minh hoa qua trinh sap xep voi dau vao 100
   		laymang(s100,s250,s500);
   		hs100.heapSort_dohoa(s100.dulieu100,s100.n);
 		//hs250.heapSort_dohoa(s250_2.dulieu250,s250_2.n);
 		//hs500.heapSort_dohoa(s500_2.dulieu500,s250_2.n);
   	}
  	fflush(stdin);
	getchar();
  	system("cls");
}
