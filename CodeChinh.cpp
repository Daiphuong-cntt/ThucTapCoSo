#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <fstream> 

using namespace std;

// doi tuong can sap xep
class Source{
	public:
	Source(){}
	void CreSource(int A[],int n)
	{
		srand(time(NULL));
		for(int i=0;i<n;i++)
		{
			A[i]=rand();
		}
	}
	void PrSource(int A[],int n)
	{
		for(int i=0;i<n;i++)
		{
			cout << A[i] << " ";
		}
	}
};
class Source_10: public Source{
	public:
	int dauvao10[10];
	int n=10;
	Source_10(): Source(){}
	void DocFile()
	{
		fstream fsFile;
		fsFile.open("D:\\dauvao10.txt", ios::in);
	    if (fsFile.eof())
	    {
	        cout << "Doc file thanh cong !";
	    }
        else
	    {
	  		int tam ;
	        int i = 0;
	        while (fsFile>>tam)
	        {
	            this->dauvao10[i]=tam;
	            i++;
	        }
	    }
	}
	void TaoMang_10(int dauvao10[],int n)
	{
		Source::CreSource(dauvao10,n);
	}
	void XuatMang_100(int dauvao10[],int n)
	{
		Source::PrSource(dauvao10,n);
	}
};
class Source_100: public Source{
	public:
	int dauvao100[100];
	int n=100;
	Source_100(): Source(){}
	void DocFile()
	{
		fstream fsFile;
		fsFile.open("D:\\dauvao100.txt", ios::in);
	    if (fsFile.eof())
	    {
	        cout << "Doc file thanh cong !";
	    }
        else
	    {
	  		int tam ;
	        int i = 0;
	        while (fsFile>>tam)
	        {
	            this->dauvao100[i]=tam;
	            i++;
	        }
	    }
	}
	void TaoMang_100(int dauvao100[],int n)
	{
		Source::CreSource(dauvao100,n);
	}
	void XuatMang_100(int dauvao100[],int n)
	{
		Source::PrSource(dauvao100,n);
	}
};
class Source_500: public Source{
	public:
	int dauvao500[500];
	int n=500;
	Source_500(): Source(){}
	void DocFile()
	{
		fstream fsFile;
		fsFile.open("D:\\dauvao500.txt", ios::in);
	    if (fsFile.eof())
	    {
	        cout << "Doc file thanh cong !";
	    }
        else
	    {
	  		int tam ;
	        int i = 0;
	        while (fsFile>>tam)
	        {
	            this->dauvao500[i]=tam;
	            i++;
	        }
	    }
	}
	void TaoMang_500(int dauvao500[],int n)
	{
		Source::CreSource(dauvao500,n);
	}
	void XuatMang_500(int dauvao500[],int n)
	{
		Source::PrSource(dauvao500,n);
	}
};

// thuat toan sap xep
class Sort{
	public:
	void printArray(int A[],int n)
	{
		for(int i=0;i<n;i++)
		{
			cout << A[i] << " ";
		}
	}
};
class MergeSort: public Sort{	
	public:
	void merge(int arr[], int l, int m, int r)
	{
		// tao 2 mang con.
	    int n1 = m - l + 1;
	    int n2 = r - m;
	    int L[n1], R[n2];
	    // chep du lieu vao 2 mang
	    for (int i = 0; i < n1; i++)
	        L[i] = arr[l + i];
	    for (int j = 0; j < n2; j++)
	        R[j] = arr[m + 1 + j];
	    // thuc hien tron code
	    int i = 0;	int j = 0;	int k = l;
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
	    // sao chep cac phan tu con lai vao mang (neu co)
	    while (i < n1) {
	        arr[k] = L[i];
	        i++;
	        k++;
	    }
	    while (j < n2) {
	        arr[k] = R[j];
	        j++;
	        k++;
	    }
	}
	// Ham de qui sap xep chinh
	void mergeSort(int arr[],int l,int r)
	{
	    if(l<r)
		{	
			int m = (l+r)/2;
			// de qui tach mang
		    mergeSort(arr,l,m);
		    mergeSort(arr,m+1,r);
		    // tron code 
		    merge(arr,l,m,r);
	    }
	}
	void ThoiGianThucHien(int arr[],int n)
	{
		clock_t star = (double)clock();
		int l=0;
		int r=n-1;
		mergeSort(arr,l,r);
		//Sort:: printArray(arr,n);
		clock_t end = clock();
		cout<<"Merge Sort: "<<(float)(end-star)/CLOCKS_PER_SEC<<" s"<<endl;
	}
};
class HeapSort : public Sort{
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
	void ThoiGianThucHien(int arr[],int n)
	{
		clock_t star = clock();
		heapSort(arr,n);
		//Sort:: printArray(arr,n);
		clock_t end = clock();
		cout<<"Heap Sort: "<<(double)(end-star)/CLOCKS_PER_SEC<<" s"<<endl;
	}
};

int main()
{
    MergeSort ms10, ms100, ms500;
    HeapSort hs10, hs100, hs500;
    
 	// dau vao 10
 	Source_10 s10;
 	s10.DocFile();
 	s10.TaoMang_10(s10.dauvao10,s10.n);
 	cout << "n = 10\n";
 	ms10.ThoiGianThucHien(s10.dauvao10,s10.n);
    hs10.ThoiGianThucHien(s10.dauvao10,s10.n);
 	
 	// dau vao 100
 	Source_100 s100;
 	s100.DocFile();
 	s100.TaoMang_100(s100.dauvao100,s100.n);
 	cout << "n = 100\n";
    ms100.ThoiGianThucHien(s100.dauvao100,s100.n);	
    hs100.ThoiGianThucHien(s100.dauvao100,s100.n);
 	
 	// dau vao 500
 	Source_500 s500;
 	s500.DocFile();
 	s500.TaoMang_500(s500.dauvao500,s500.n);
 	cout << "n = 500\n";
    ms500.ThoiGianThucHien(s500.dauvao500,s500.n);
    hs500.ThoiGianThucHien(s500.dauvao500,s500.n);
    
	return 0;

}