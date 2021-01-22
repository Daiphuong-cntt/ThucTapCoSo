#include<iostream>
#include <bits/stdc++.h> 
#include <ctime>
#include <cstdio>
#include<fstream> 
#include <time.h>
#include <cstdlib>
#include<string>
#include<conio.h>
#include <unistd.h>
#include<graphics.h>
using namespace std;
class Source
{
public:
    void xuatmang(int arr[],int n)
    {
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<"\n";
        }
    }
    void taoarr(int arr[],int n)
    {
        srand(time(NULL));
        for(int i=0;i<n;i++)
        {
            arr[i]=rand();
        }
    }
    void laymangfile(char* s,int arr[])
    {
        fstream fsFile;
        fsFile.open(s, ios::in);
        if (fsFile.eof())
        {
            cout << "Read done";
        }
        else
        {
  		    int tam ;
            int i = 0;
            while (fsFile>>tam)
            {
                //cout<<tam<<"\n";
                arr[i]=tam;
                i++;
            }
        }
 
        fsFile.close();
    }
};
class Source100: public Source{
    public:
    int dulieu100[100];
    int n=100;
    void laymangfile(char *s,int arr[]){
        Source::laymangfile(s,arr);
    }
    void taomang(int dl[],int n)
    {
        Source::taoarr(dl,n);
    }
    void xuatmang(int arr[],int n)
    {
        Source::xuatmang(arr,n);
    }

};
class Source250:public Source{
    public:
    int dulieu250[250];
    int n=250;
   	void laymangfile(char *s,int arr[]){
        Source::laymangfile(s,arr);
    }
    void taomang(int dl[],int n)
    {
        Source::taoarr(dl,n);
    }
    void xuatmang(int arr[],int n)
    {
        Source::xuatmang(arr,n);
    }
};
class Source500: public Source{
    public:
     int dulieu500[500];
    int n=500;
    void laymangfile(char *s,int arr[]){
        Source::laymangfile(s,arr);
    }
    void taomang(int dl[],int n)
    {
        Source::taoarr(dl,n);
    }
   void xuatmang(int arr[],int n)
    {
        Source::xuatmang(arr,n);
    }
};
class Sort{
public:

    void inmang(int arr[],int n)
    {
        for (int i = 0; i < n; i++) 
        	cout << arr[i] << " "; 
    }
    void hinhchunhat(int x1,int y1,int x2,int y2)
    {
	    line(x1,y1,x1,y2);
	    line(x1,y2,x2,y2);
	    line(x2,y2,x2,y1);
	    line(x2,y1,x1,y1);  
    } 
//in ra man hinh day so theo do hoa
void screen(int arr[], int n)
{
	int xstart=0,ystart=0;
	for(int i=0;i<n;i++)
	{
		hinhchunhat(xstart+i*800/n,	0,	xstart+(i+1)*800/n,	arr[i]/100);
	}
} 
};
class radix: public Sort{
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

    //sap xep day so
    void countSort(int arr[], int n, int exp) 
    { 
        int output[n];  
        int i, count[10] = { 0 }; 
  		//Phan cac so vao cac khu vuc count dua vao so do la so nao
        for (i = 0; i < n; i++)
        { 
            count[(arr[i] / exp) % 10]++;
            
        } 
        for (i = 1; i < 10; i++)
        { 
            count[i] += count[i - 1];
        } 
  
    	//ghep cac so lai vao mang ouput
        for (i = n - 1; i >= 0; i--) { 
            output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
            count[(arr[i] / exp) % 10]--; 
        } 
  
    	//dua mang output vao lai mang arr
        for (i = 0; i < n; i++) 
        {
            arr[i] = output[i];
        }
    } 
	void countSort_dohoa(int arr[], int n, int exp) 
{ 
    int output[n];  
    int i, count[10] = { 0 }; 
  
    for (i = 0; i < n; i++) 
        count[(arr[i] / exp) % 10]++; 
  
    for (i = 1; i < 10; i++)
	{ 
        count[i] += count[i - 1];
	}
  
    
    for (i = n - 1; i >= 0; i--) { 
        output[count[(arr[i] / exp) % 10] - 1] = arr[i]; 
        count[(arr[i] / exp) % 10]--;
		cleardevice(); 
	    Sort::screen(output,n);
        //delay(10); 
    } 
    for (i = 0; i < n; i++) 
        arr[i] = output[i];
        cleardevice(); 
	    Sort::screen(arr,n);
        delay(1);
        
}
void radixsort_dohoa(int arr[],int n)
{
	cleardevice();
	//clock_t begin = clock(); 
	//initwindow(800,1000);
        // Tim so lon nhat de lay so chu so nhieu nhat
        int m = getMax(arr, n); 
  
        // Thuc hien sap xep theo vi tri chu so, exp la vi tri chu so, i la so hien tai 
        for (int exp = 1; m / exp > 0; exp *= 10)
	    { 
            countSort_dohoa(arr, n, exp);
       
	    }
	    
      //   clock_t end = clock();	
         //cout<<begin<<"\t"<<end<<endl;
        // return (float)((end-begin)/CLOCKS_PER_SEC)*1000;
    
}
    float radixsort(int arr[], int n) 
    {
        //auto start = high_resolution_clock::now();
		clock_t t,t2; 
        // Tim so lon nhat de lay so chu so nhieu nhat
        t = clock();
        int m = getMax(arr, n); 
  
        // Thuc hien sap xep theo vi tri chu so, exp la vi tri chu so, i la so hien tai 
        for (int exp = 1; m / exp > 0; exp *= 10)
	    { 
            countSort(arr, n, exp);
       
	    }
	     sleep(1);
         t2=clock();
        
         float time_taken = ((float)t)/CLOCKS_PER_SEC; // in seconds
         float time_taken2 = ((float)t2)/CLOCKS_PER_SEC;
        
         return (((float)time_taken2-time_taken-1)/CLOCKS_PER_SEC)*1000;
    } 
  
    // In mang sau khi sap xep 
    void inmang(int arr[], int n)
    { 
        Sort::inmang(arr,n);
    }

};
class insert:public Sort{
    public:
    float insertSort(int arr[], int n)  
    {
		clock_t t1,t2; 
        t1 = clock(); 
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
		      
    	}
        sleep(1);
        t2 = clock();
        float time_taken1 = ((float)t1)/CLOCKS_PER_SEC; // in seconds
         float time_taken2 = ((float)t2)/CLOCKS_PER_SEC;
        
         return (((float)time_taken2-time_taken1-1)/CLOCKS_PER_SEC)*1000;
    }  
    void insertSort_dohoa(int arr[], int n)  
{  
    int i, key, j; 
	//initwindow(800,1000);
	cleardevice(); 
	//clock_t begin = clock();
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
        cleardevice();
		screen(arr,n);
        delay(1);
          
    }
    
	
  
}
    // ham in mang 
    void inmang(int arr[], int n)
        { 
            Sort::inmang(arr,n);
        }
};
class SelectionSort: public Sort 
	{
	// Ham doi cho hai so nguyen
	public: void swap(int* xp, int* yp)
    {
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
    }
// Hàm selection sort
	public: void selectionSort(int arr[], int n)
    {
        int i, j, min_idx;

        // di chuyen ranh gioi cua mang da sap xep va chua sap xep
        for (i = 0; i < n - 1; i++)
        {
            // tim phan tu nho nhat trong mang chua sap xep
            min_idx = i;
            for (j = i + 1; j < n; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;

            // doi cho phan tu nho nhat voi phan tu dau tien
            swap(&arr[min_idx], &arr[i]);
        }
    }

public: void selectionSort_dohoa(int arr[], int n)
    {
        int i, j, min_idx;

        // di chuyen ranh gioi cua mang da sap xep va chua sap xep
        for (i = 0; i < n - 1; i++)
        {
            // tim phan tu nho nhat trong mang chua sap xep
            min_idx = i;
            for (j = i + 1; j < n; j++)
                if (arr[j] < arr[min_idx])
                    min_idx = j;

            // doi cho phan tu nho nhat voi phan tu dau tien
            swap(&arr[min_idx], &arr[i]);
            cleardevice(); 
	    Sort::screen(arr,n);
        delay(1);
        }
        
    }
    /* ham xuat mang */
	public:  void printArray(int arr[], int size)
    {
        Sort::inmang(arr,size);
    }
	double t_SelectionSort(int arr[],int n)
	{
		clock_t star = clock();
	
		selectionSort(arr,n);
		//	printArray(arr,n);
		sleep(1);
		clock_t end = clock();
		double d = (double)((end-star)-1)/CLOCKS_PER_SEC;
		return d;
	}
};


class TreeSort: public Sort {
	public: int key;
    TreeSort* left, * right;

public: TreeSort* newNode(int item) {
    TreeSort* temp = new TreeSort;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
public:
    Node() {

    }

public: void storeSorted(TreeSort* root, int arr[], int& i) {
          if (root != NULL) {
              storeSorted(root->left, arr, i);
              arr[i++] = root->key;
              storeSorted(root->right, arr, i);
          }
      }

//	Mot chuc nang tien ích de chèn mot
//      Nút voi khóa nhat dinh
public: TreeSort* insert(TreeSort* node, int key) {
        //Neu cây trong == null, tra ve mot Node moi 
          if (node == NULL) return newNode(key);

          
          if (key < node->key)
              node->left = insert(node->left, key);
          else if (key > node->key)
              node->right = insert(node->right, key);

          
          return node;
      }

      // Hàm này sap xep arr [0..n-1] bang cách su dung Tree Sort
public:  void treeSort(int arr[], int n) {
          struct TreeSort* root = NULL;

          // xay dung
          root = insert(root, arr[0]);
          for (int i = 1; i < n; i++)
              root = insert(root, arr[i]);

          // luu tru truyen tai
          int i = 0;
          storeSorted(root, arr, i);
      }
    void inmang(int arr[],int n)
    {
    	Sort::inmang(arr,n);
	}
	double t_TreeSort(int arr[],int n)
	{
		clock_t star = clock();
	//inmang(arr,n);
		treeSort(arr,n);
		sleep(1);
		clock_t end = clock();
		double d = (double)((end-star)-1)/CLOCKS_PER_SEC;
		return d;
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
	void merge_dohoa(int arr[], int l, int m, int r,int n)
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
	        cleardevice(); 
	    Sort::screen(arr,n);
        delay(1);
	    }
	    // sao chep cac phan tu con lai vao mang neu co
	    while (i < n1)
		{
	        arr[k] = L[i];
	        i++;
	        k++;
	        cleardevice(); 
	    Sort::screen(arr,n);
        delay(1);
	    }
	    while (j < n2)
		{
	        arr[k] = R[j];
	        j++;
	        k++;
	        cleardevice(); 
	    Sort::screen(arr,n);
        delay(1);
	    }
	}
	// Ham de qui sap xep chinh
	void mergeSort_dohoa(int arr[], int l, int r,int n)
	{
	    if(l<r)
		{	
			int m = ( l + r ) / 2;
			// de qui tach mang
		    mergeSort_dohoa(arr, l, m,n);
		    mergeSort_dohoa(arr, m+1, r,n);
		    // tron code 
		    merge_dohoa(arr, l, m, r,n);
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
	void heapSort_dohoa(int arr[], int n)
	{
		// Tao mot dong (Sap xep lai mang)
		for (int i = n / 2 - 1; i >= 0; i--)
		{
			heapify(arr, n, i);
			cleardevice();
					Sort::screen(arr,n);
					delay(1);
		}
		for (int i = n - 1; i >= 0; i--)
		{
			// Di chuyen root ve cuoi cung
			swap(arr[0], arr[i]);
			// goi ham heapify
			heapify(arr, i, 0);
			cleardevice();
					Sort::screen(arr,n);
					delay(1);
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
class QuickSort: public Sort
{	public :
	void HoanVi(int& x, int& y)
	{
		int temp = x;
		x = y;
		y = temp;
	}
		void InMang(int arr[], int n)
	{
		cout << "\nQuick Sort:\n";
		Sort::inmang(arr, n);
	}


	void quickSort(int a[], int left, int right)
	{
		int i, j, x;
		if (left >= right)
		{
			return;
		}
		x = a[(left + right) / 2];
		i = left;
		j = right;
		while (i < j)
		{
			while (a[i] > x)
			{
				i++;
			}
			while (a[j] < x)
			{
				j--;
			}
			if (i <= j)
			{
				HoanVi(a[i], a[j]);
				i++; j--;
			}
		}
		quickSort(a, left, j);
		quickSort(a, i, right);
		
	}
	
void quickSort_dohoa(int a[], int left, int right,int n)
	{
		int i, j, x;
		if (left >= right)
		{
			return;
		}
		x = a[(left + right) / 2];
		i = left;
		j = right;
		while (i < j)
		{
			while (a[i] > x)
			{
				i++;
			}
			while (a[j] < x)
			{
				j--;
			}
			if (i <= j)
			{
				HoanVi(a[i], a[j]);
				cleardevice(); 
	    		Sort::screen(a,n);
	    		delay(1);
				i++; j--;
			}
		}
		
		quickSort_dohoa(a, left, j,n);
		quickSort_dohoa(a, i, right,n);
	delay(1);
	}

	
   double t_QuickSort (int arr[], int n)
	{
			int j = 1000;
		clock_t start1 = clock();
		

		quickSort(arr, 0,n - 1);
		sleep(1);
		clock_t finish1 = clock();
		double duration1 = (double)(finish1-1 - start1) / (CLOCKS_PER_SEC);
		return duration1;
	}
};



class BubbleSort : public Sort
{
	public:
			void HoanVi(int& x, int& y)
	{
		int temp = x;
		x = y;
		y = temp;
	}
		void bubbleSort(int arr[],int n)
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = n - 1; j > i; j--)
			{
				if (arr[j] > arr[j - 1])
				{
					HoanVi(arr[j], arr[j - 1]);
				}
			}
		}
	}
 
 void bubbleSort_dohoa(int arr[],int n)
	{
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = n - 1; j > i; j--)
			{
				if (arr[j] > arr[j - 1])
				{
					HoanVi(arr[j], arr[j - 1]);
					cleardevice();
					Sort::screen(arr,n);
					delay(1);
				}
			}
		}
		
	}
	
	void InMang (int arr[], int n)
	{
		cout << "\nBubble Sort:\n";
		Sort::inmang(arr, n);
	}
	// tinh thoi gian thuc hien thuat toan HeapSort
	double t_BubbleSort(int arr[], int n)
	{

		clock_t start2 = clock();

		bubbleSort(arr, n);
	sleep(1);
		clock_t finish2 = clock();
		double duration2 = (double)(finish2 - start2-1) / CLOCKS_PER_SEC;
		return duration2;
	}
};
class CoutingSort : public Sort {

public: void CountSort(int arr[], int n) {

	
    int arr1[40000];
    int count_arr[40000];
    int x = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > x)
            x = arr[i];
    }

    for (int i = 0; i <= x; ++i) {
        count_arr[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count_arr[arr[i]]++;
    }

    for (int i = 1; i <= x; i++) {
        count_arr[i] += count_arr[i - 1];
    }


    for (int i = n - 1; i >= 0; i--) {
        arr1[count_arr[arr[i]] - 1] = arr[i];
        count_arr[arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = arr1[i];
    }
}

public: void CountSort_dohoa(int arr[], int n) {

	
    int arr1[40000];
    int count_arr[40000];
    int x = arr[0];
	cleardevice();
	Sort::screen(arr,n);
	delay(1);
    for (int i = 1; i < n; i++) {
        if (arr[i] > x)
            x = arr[i];
    }

    for (int i = 0; i <= x; ++i) {
        count_arr[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count_arr[arr[i]]++;
      
    }
	
    for (int i = 1; i <= x; i++) {
        count_arr[i] += count_arr[i - 1];
        
    }
	

    for (int i = n - 1; i >= 0; i--) {
        arr1[count_arr[arr[i]] - 1] = arr[i];
        count_arr[arr[i]]--;
        cleardevice();
					Sort::screen(arr1,n);
					delay(1);
    }
	
    for (int i = 0; i < n; i++) {
        arr[i] = arr1[i];
    }
    cleardevice();
					Sort::screen(arr,n);
					delay(1);
					
}


public:  void printArray(int arr[], int n)
{
    Sort::inmang(arr, n);
}
public: 	double ThoiGianThucHien(int arr[], int n)
{

    clock_t star = clock();
    
    CountSort(arr,n);
    sleep(1);
    clock_t end = clock();
    
    double d = (double)(end - star-1) / (CLOCKS_PER_SEC );
    return d;
}
};
class timSort : public Sort {
const int RUN = 32;

	public: void insertionSort(int arr[], int left, int right)
	{
    	for (int i = left + 1; i <= right; i++)
    	{
        	int temp = arr[i];
        	int j = i - 1;
        	while (j >= left && arr[j] > temp)
        	{
            	arr[j + 1] = arr[j];
            	j--;
        	}
        	arr[j + 1] = temp;
    	}
	}
	public: void insertionSort_dohoa(int arr[], int left, int right,int n)
	{
    	for (int i = left + 1; i <= right; i++)
    	{
        	int temp = arr[i];
        	int j = i - 1;
        	while (j >= left && arr[j] > temp)
        	{
            	arr[j + 1] = arr[j];
            	j--;
        	}
        	arr[j + 1] = temp;
        	 cleardevice();
					Sort::screen(arr,n);
					delay(1);
    	}
	}
	//  Chuc nang tron tron cac run da sap xep lai voi nhau
	public:void merge(int arr[], int l, int m, int r)
	{

    	// Mang ban dau duoc chia lam hai mang trai va phai 
    	// len1 => chieu dai mang trai && len2 => chieu dai mang phai 
    	int len1 = m - l + 1, len2 = r - m;
   
    	int left[len1], right[len2];
    	for (int i = 0; i < len1; i++)
        	left[i] = arr[l + i];
    	for (int i = 0; i < len2; i++)
        	right[i] = arr[m + 1 + i];

    	int i = 0;
    	int j = 0;
    	int k = l;

		//Sau khi so sanh, ta tron 2 mang nay vao mot mang lon hon
    
    	while (i < len1 && j < len2)
    	{
        	if (left[i] <= right[j])
        	{
            	arr[k] = left[i];
            	i++;
        	}
        	else
        	{
            	arr[k] = right[j];
            	j++;
        	}
        	k++;
        	
    	}

		//Sao nhung phan tu con lai ben trai, neu co
    
    	while (i < len1)
    	{
        	arr[k] = left[i];
        	k++;
        	i++;
        	
    	}

    	//Sao nhung phan tu con lai ben phai, neu co 
    	while (j < len2)
    	{
        	arr[k] = right[j];
        	k++;
        	j++;
        
   		}
	}

	public:void merge_dohoa(int arr[], int l, int m, int r,int n)
	{

    	// Mang ban dau duoc chia lam hai mang trai va phai 
    	// len1 => chieu dai mang trai && len2 => chieu dai mang phai 
    	int len1 = m - l + 1, len2 = r - m;
   
    	int left[len1], right[len2];
    	for (int i = 0; i < len1; i++)
        	left[i] = arr[l + i];
    	for (int i = 0; i < len2; i++)
        	right[i] = arr[m + 1 + i];

    	int i = 0;
    	int j = 0;
    	int k = l;

		//Sau khi so sanh, ta tron 2 mang nay vao mot mang lon hon
    
    	while (i < len1 && j < len2)
    	{
        	if (left[i] <= right[j])
        	{
            	arr[k] = left[i];
            	i++;
        	}
        	else
        	{
            	arr[k] = right[j];
            	j++;
        	}
        	k++;
        	
    	}

		//Sao nhung phan tu con lai ben trai, neu co
    
    	while (i < len1)
    	{
        	arr[k] = left[i];
        	k++;
        	i++;
        	cleardevice();
					Sort::screen(arr,n);
					delay(1);
    	}

    	//Sao nhung phan tu con lai ben phai, neu co 
    	while (j < len2)
    	{
        	arr[k] = right[j];
        	k++;
        	j++;
        	cleardevice();
					Sort::screen(arr,n);
					delay(10);
   		}
	}
	// Lap lai ham Timsort de sap xep arr[0..n-1] ( tuong tu voi sap xep tron)
 
	public:void Sort(int arr[], int n)
	{
	

    	// Sap xep tung mang con voi kich thuoc RUN 
    	for (int i = 0; i < n; i += RUN)
        	insertionSort(arr, i, min((i + 31),
            	(n - 1)));
		//Bat dau tron tu kich thuoc RUN ( hoac 32)
		//No se tron den kich thuoc 64, sau do la 128, den 256 ....
    
    	for (int size = RUN; size < n;
        	size = 2 * size)
    	{
			//Chon diem bat dau cua mang ben trai.Ta bat dau tron arr[left..left+2*size-1]
		 
        	for (int left = 0; left < n;
            	left += 2 * size)
        	{
        		//Tim diem ket thuc cua mang ben trai
				//mid+1 la diem bat dau cua mang ben phai
             
            	int mid = left + size - 1;
            	int right = min((left + 2 * size - 1),
                	(n - 1));

            	// tron nhung mang con arr[left.....mid] &  arr[mid+1....right] 
            	merge(arr, left, mid, right);
        	}
    	}
	}

// Lap lai ham Timsort de sap xep arr[0..n-1] ( tuong tu voi sap xep tron)
 
	public:void Sort_dohoa(int arr[], int n)
	{
	

    	// Sap xep tung mang con voi kich thuoc RUN 
    	for (int i = 0; i < n; i += RUN)
        	insertionSort_dohoa(arr, i, min((i + 31),(n - 1)),n);
		//Bat dau tron tu kich thuoc RUN ( hoac 32)
		//No se tron den kich thuoc 64, sau do la 128, den 256 ....
    
    	for (int size = RUN; size < n;
        	size = 2 * size)
    	{
			//Chon diem bat dau cua mang ben trai.Ta bat dau tron arr[left..left+2*size-1]
		 
        	for (int left = 0; left < n;
            	left += 2 * size)
        	{
        		//Tim diem ket thuc cua mang ben trai
				//mid+1 la diem bat dau cua mang ben phai
             
            	int mid = left + size - 1;
            	int right = min((left + 2 * size - 1),
                	(n - 1));

            	// tron nhung mang con arr[left.....mid] &  arr[mid+1....right] 
            	merge_dohoa(arr, left, mid, right,n);
        	}
    	}
	}
	public:  void printArray(int arr[], int n)
	{
    	Sort::inmang(arr, n);
	}
	public: 	double ThoiGianThucHien(int arr[], int n)
	{

    	clock_t star = clock();
    	Sort(arr,n);
    	sleep(1);
    	clock_t end = clock();
     
    	double d = (double)(end - star-1) / (CLOCKS_PER_SEC );
    	return d;
	}

};
void laymang(Source100 &s100,Source250 &s250,Source500 &s500)
{
s100.laymangfile("D:\\Thuctapcoso\\ThucTapCoSo\\dauvao100.txt",s100.dulieu100);
    //s100.taomang(s100.dulieu100,s100.n);
    s250.laymangfile("D:\\Thuctapcoso\\ThucTapCoSo\\dauvao250.txt",s250.dulieu250);
    //s250.taomang(s250.dulieu250,s250.n);
	s500.laymangfile("D:\\Thuctapcoso\\ThucTapCoSo\\dauvao500.txt",s500.dulieu500);	
}
int main()
{
	initwindow(800,1000);
	Source100 s100;
    Source250 s250;
    Source500 s500;
    radix ra100,ra250,ra500;
    insert ins100,ins250,ins500;
    
	int choose;
	menu:
	//laymang(s100,s250,s500);
	cout<<"---Chuong trinh so sanh thoi gian cua cac thuat toan sap xep--"<<endl;
	cout<<"--------------------------------------------------------------"<<endl;
	cout<<"1.Merge Sort & Heap Sort"<<endl;
	cout<<"2.Radix Sort & Insert Sort"<<endl;
	cout<<"3.Bubble Sort & Quick Sort"<<endl;
	cout<<"4.Selection Sort & Tree Sort"<<endl;
	cout<<"5.Counting Sort & Tim Sort"<<endl;
	cout<<"0. Thoat chuong trinh"<<endl;
	cout<<"--------------------------------------------------------------"<<endl;
	cout<<"Nhap lua chon cua ban:"<<endl;
	cout<<">>";cin>>choose;
	switch(choose)
	{
		case 0: return -1;
		break;
		case 1: 
		{
			MergeSort ms100, ms250, ms500;
			HeapSort hs100, hs250, hs500;
			double sumMS100=0, sumMS250=0, sumMS500=0;
			double sumHS100=0, sumHS250=0, sumHS500=0;
			cout << "Size\t\t100\t250\t500";
			for(int i= 0;i<10;i++)
			{
				laymang(s100,s250,s500);
			//cout << "\nMerge Sort\t" << ms100.t_MergeSort(s100_1.dulieu100,s100_1.n) << "\t" << ms250.t_MergeSort(s250_1.dulieu250,s250_1.n) << "\t" << ms500.t_MergeSort(s500_1.dulieu500,s500_1.n);
			//cout << "\nHeap Sort\t"  << hs100.t_HeapSort(s100_2.dulieu100,s100_2.n)  << "\t" << hs250.t_HeapSort(s250_2.dulieu250,s250_2.n)  << "\t" << hs500.t_HeapSort(s500_2.dulieu500,s500_2.n);
    		sumMS100 = sumMS100 + ms100.t_MergeSort(s100.dulieu100,s100.n);
			sumMS250 = sumMS250 + ms250.t_MergeSort(s250.dulieu250,s250.n);
			sumMS500 = sumMS500 + ms500.t_MergeSort(s500.dulieu500,s500.n);
			laymang(s100,s250,s500);
			sumHS100 = sumHS100 + hs100.t_HeapSort(s100.dulieu100,s100.n);
			sumHS250 = sumHS250 + hs250.t_HeapSort(s250.dulieu250,s250.n);
			sumHS500 = sumHS500 + hs500.t_HeapSort(s500.dulieu500,s500.n);
			}
		cout << "\nMerge Sort :\t" << sumMS100/10 << "\t" << sumMS250/10 << "\t" << sumMS500/10;
		cout << "\nHeap Sort :\t" << sumHS100/10 << "\t" << sumHS250/10 << "\t" << sumHS500/10;
		int lc;
   		cout<<"\nBan co muon bieu dien do hoa khong?(1:Co/0:Khong)"<<endl;
   		cout<<">>";cin>>lc;
   		if(lc==1)
   		{
   			laymang(s100,s250,s500);
   			ms100.mergeSort_dohoa(s100.dulieu100,0,s100.n-1,s100.n);
   			ms250.mergeSort_dohoa(s250.dulieu250,0,s250.n-1,s250.n);
   			ms500.mergeSort_dohoa(s500.dulieu500,0,s500.n-1,s500.n);
   			laymang(s100,s250,s500);
   			hs100.heapSort_dohoa(s100.dulieu100,s100.n);
   			hs250.heapSort_dohoa(s250.dulieu250,s250.n);
   			hs500.heapSort_dohoa(s500.dulieu500,s500.n);
   		}
		break;
		}
		case 2: 
		{
			radix ra100,ra250,ra500;
    		insert ins100,ins250,ins500;
    		double sumRD100=0, sumRD250=0, sumRD500=0;
			double sumIN100=0, sumIN250=0, sumIN500=0;
			cout<<"size\t\t100\t\t250\t\t500"<<endl;
    		for(int i=1;i<10;i++)
			{
				laymang(s100,s250,s500);
				sumRD100 +=ra100.radixsort(s100.dulieu100,s100.n);
				sumRD250 +=ra250.radixsort(s250.dulieu250,s250.n);
				sumRD500 +=ra500.radixsort(s500.dulieu500,s500.n);
				laymang(s100,s250,s500);
				sumIN100+=ins100.insertSort(s100.dulieu100,s100.n);
				sumIN250+=ins250.insertSort(s250.dulieu250,s250.n);
				sumIN500+=ins500.insertSort(s500.dulieu500,s500.n);
    	
			}
	
			printf("Radix Sort\t%f\t%f\t%f\n",sumRD100/10,sumRD250/10,sumRD500/10);
   			printf("insert Sort\t%f\t%f\t%f",sumIN100/10,sumIN250/10,sumIN500/10);
   			int lc;
   			cout<<"\nBan co muon bieu dien do hoa khong?(1:Co/0:Khong)"<<endl;
   			cout<<">>";cin>>lc;
   			if(lc==1)
   			{
   				laymang(s100,s250,s500);
   				ra100.radixsort_dohoa(s100.dulieu100,s100.n);
   				ra250.radixsort_dohoa(s250.dulieu250,s250.n);
   				ra500.radixsort_dohoa(s500.dulieu500,s500.n);
   				laymang(s100,s250,s500);
   				ins100.insertSort_dohoa(s100.dulieu100,s100.n);
   				ins250.insertSort_dohoa(s250.dulieu250,s250.n);
   				ins500.insertSort_dohoa(s500.dulieu500,s500.n);
		   	}
			break;
		}
		case 3: 
		{
			QuickSort qs100, qs250, qs500;
			BubbleSort bs100, bs250, bs500;
			double sqs100=0, sqs250=0, sqs500=0;
			double sbs100=0, sbs250=0, sbs500=0;
			// hien thi
			cout << "Size\t\t100\t250\t500";
			//	cout << "\nQuick Sort\t" << qs100.t_QuickSort(s100_1.dulieu100,s100_1.n) << "\t" << qs250.t_QuickSort(s250_1.dulieu250,s250_1.n) << "\t" << qs500.t_QuickSort(s500_1.dulieu500,s500_1.n);
			//cout << "\nbubble Sort\t"  << hs100.t_BubbleSort(s100_2.dulieu100,s100_2.n)  << "\t" << hs250.t_BubbleSort(s250_2.dulieu250,s250_2.n)  << "\t" << hs500.t_BubbleSort(s500_2.dulieu500,s500_2.n);
			for(int i=0;i<=10;i++)
			{	
				laymang(s100,s250,s500);
				sqs100 = sqs100 + qs100.t_QuickSort(s100.dulieu100,s100.n);
				sqs250 = sqs250 + qs250.t_QuickSort(s250.dulieu250,s250.n);
				sqs500 = sqs500 + qs500.t_QuickSort(s500.dulieu500,s500.n);
				laymang(s100,s250,s500);
				sbs100 = sbs100 + bs100.t_BubbleSort(s100.dulieu100,s100.n);
				sbs250 = sbs250 + bs250.t_BubbleSort(s250.dulieu250,s250.n);
				sbs500 = sbs500 + bs500.t_BubbleSort(s500.dulieu500,s500.n);
			}
			cout << "\nQuick Sort :\t" << sqs100/10 << "\t" << sqs250/10 << "\t" << sqs500/10;
			cout << "\nBubble Sort :\t" << sbs100/10 << "\t" << sbs250/10 << "\t" << sbs500/10;	
			int lc;
			cout<<"\nBan co muon bieu dien do hoa khong?(1:Co/0:Khong)"<<endl;
   			cout<<">>";cin>>lc;
   			if(lc==1)
   			{
   				laymang(s100,s250,s500);
   				bs100.bubbleSort_dohoa(s100.dulieu100,s100.n);
   				bs250.bubbleSort_dohoa(s250.dulieu250,s250.n);
   				bs500.bubbleSort_dohoa(s500.dulieu500,s500.n);
   				laymang(s100,s250,s500);
   				qs100.quickSort_dohoa(s100.dulieu100,0,s100.n-1,s100.n);
				qs250.quickSort_dohoa(s250.dulieu250,0,s250.n-1,s250.n);
				qs500.quickSort_dohoa(s500.dulieu500,0,s500.n-1,s500.n);
   			
   			
		   	}
			break;
		}
		case 4: 
		{
			SelectionSort ss100, ss250, ss500;
    		TreeSort ts100, ts250, ts500;
    		ss100.selectionSort(s100.dulieu100,s100.n);
			ss250.selectionSort(s250.dulieu250,s250.n);
			ss500.selectionSort(s500.dulieu500,s500.n);
	
			double sumSS100=0, sumSS250=0, sumSS500=0;
			double sumTS100=0, sumTS250=0, sumTS500=0;
	
			cout << "\nsize\t\t100\t250\t500";
			for (int i=0;i<10;i++)
			{
				//	cout<<"\n----------------------------------------------------";
				//	cout << "\nSelection Sort\t" << ss100.t_SelectionSort(s100_1.dulieu100,s100_1.n) << "\t" << ss250.t_SelectionSort(s250_1.dulieu250,s250_1.n) << "\t" << ss500.t_SelectionSort(s500_1.dulieu500,s500_1.n);
				//	cout << "\nTree Sort\t" << ts100.t_TreeSort(s100_1.dulieu100,s100_1.n) << "\t" << ts250.t_TreeSort(s250_1.dulieu250,s250_1.n) << "\t" << ts500.t_TreeSort(s500_1.dulieu500,s500_1.n);
				sumSS100 = sumSS100 + ss100.t_SelectionSort(s100.dulieu100,s100.n);
				sumSS250 = sumSS250 + ss250.t_SelectionSort(s250.dulieu250,s250.n);
				sumSS500 = sumSS500 + ss500.t_SelectionSort(s500.dulieu500,s500.n);
	
				sumTS100 = sumTS100 + ts100.t_TreeSort(s100.dulieu100,s100.n);
				sumTS250 = sumTS250 + ts250.t_TreeSort(s250.dulieu250,s250.n);
				sumTS500 = sumTS500 + ts500.t_TreeSort(s500.dulieu500,s500.n);
			}
			cout << "\nSelect Sort:\t" << sumSS100/10 << "\t" << sumSS250/10 << "\t" << sumSS500/10;
			cout << "\nTree Sort:\t" << sumTS100/10 << "\t" << sumTS250/10 << "\t" << sumTS500/10;
			int lc;
			cout<<"\nBan co muon bieu dien do hoa khong?(1:Co/0:Khong)"<<endl;
   			cout<<">>";cin>>lc;
   			if(lc==1)
   			{
   				laymang(s100,s250,s500);
				ss100.selectionSort_dohoa(s100.dulieu100,s100.n);
				ss250.selectionSort_dohoa(s250.dulieu250,s250.n);
				ss500.selectionSort_dohoa(s500.dulieu500,s500.n);
   			}
			break;
		}
		case 5: 
		{
			timSort tsort100, tsort250, tsort500;
    		CoutingSort csort100, csort250, csort500;
    		double sumTimS100=0, sumTimS250=0, sumTimS500=0;
			double sumCountS100=0, sumCountS250=0, sumCountS500=0;
			cout << "\nsize\t\t100\t250\t500";  
			for(int i= 0;i<10;i++){
				// tinh thoi gian trung binh sau 10 lan thuc hien thuat toan
    			sumTimS100 = sumTimS100 + tsort100.ThoiGianThucHien(s100.dulieu100, s100.n);
				sumTimS250 = sumTimS250 + tsort250.ThoiGianThucHien(s250.dulieu250, s250.n);
				sumTimS500 = sumTimS500 + tsort500.ThoiGianThucHien(s500.dulieu500, s500.n);
		
				sumCountS100 = sumCountS100 + csort100.ThoiGianThucHien(s100.dulieu100, s100.n);
				sumCountS250 = sumCountS250 + csort250.ThoiGianThucHien(s250.dulieu250, s100.n);
				sumCountS500 = sumCountS500 + csort500.ThoiGianThucHien(s500.dulieu500,s500.n);
			}
			cout << "\nTim Sort :\t" << sumTimS100/10 << "\t" << sumTimS250/10 << "\t" << sumTimS500/10;
			cout << "\nCounting Sort :\t" << sumCountS100/10 << "\t" << sumCountS250/10 << "\t" << sumCountS500/10;
			int lc;
			cout<<"\nBan co muon bieu dien do hoa khong?(1:Co/0:Khong)"<<endl;
   			cout<<">>";cin>>lc;
   			if(lc==1)
   			{
   				laymang(s100,s250,s500);
				csort100.CountSort_dohoa(s100.dulieu100, s100.n);
				csort250.CountSort_dohoa(s250.dulieu250,s250.n)	;
				csort500.CountSort_dohoa(s500.dulieu500,s500.n);
   				laymang(s100,s250,s500);
   				tsort100.Sort_dohoa(s100.dulieu100, s100.n);
   				tsort250.Sort_dohoa(s250.dulieu250, s250.n);
   				tsort500.Sort_dohoa(s500.dulieu500, s500.n);
   				
   			}
		break;
		}
		default :
  		cout <<"CHUONG TRINH KHONG CO CHUC NANG NAY !!";
		
	}
	do{
      cout<<"\nbam ENTER de ve menu";
      break;
  	}while(1);
  	fflush(stdin);
	getchar();
  	system("cls");
 
  goto menu;
}
