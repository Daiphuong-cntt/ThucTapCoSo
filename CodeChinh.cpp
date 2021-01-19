#include <iostream>
#include <fstream>
#include <ctime>
#include <unistd.h>

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
	public: void inmang(int arr[],int n)
    {
        for (int i = 0 ; i < n ; i++) 
        cout << arr[i] << " "; 
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
		double d = (double)(end - star-1) / CLOCKS_PER_SEC;
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
int main()
{
	Source100 s100_1, s100_2;
	s100_1.LayMangFile100("D:\\dauvao100.txt", s100_1.dulieu100);
	s100_2.LayMangFile100("D:\\dauvao100.txt", s100_2.dulieu100);
	
	Source250 s250_1, s250_2;
	s250_1.LayMangFile250("D:\\dauvao250.txt", s250_1.dulieu250);
	s250_2.LayMangFile250("D:\\dauvao250.txt", s250_2.dulieu250);
	
	Source500 s500_1, s500_2;
	s500_1.LayMangFile500("D:\\dauvao500.txt",s500_1.dulieu500);
	s500_2.LayMangFile500("D:\\dauvao500.txt",s500_2.dulieu500);
	
	MergeSort ms100, ms250, ms500;
	HeapSort hs100, hs250, hs500;
	
	// hien thi
	cout << "Size\t\t100\t250\t500";
	
	cout << "\nMerge Sort\t" << ms100.t_MergeSort(s100_1.dulieu100,s100_1.n) << "\t" << ms250.t_MergeSort(s250_1.dulieu250,s250_1.n) << "\t" << ms500.t_MergeSort(s500_1.dulieu500,s500_1.n);
	cout << "\nHeap Sort\t"  << hs100.t_HeapSort(s100_2.dulieu100,s100_2.n)  << "\t" << hs250.t_HeapSort(s250_2.dulieu250,s250_2.n)  << "\t" << hs500.t_HeapSort(s500_2.dulieu500,s500_2.n);
    return 0;
}