#include<iostream>
#include <bits/stdc++.h> 
#include <ctime>
#include <cstdio>
#include<fstream> 
#include <time.h>
#include <cstdlib>
#include<string>
#include <unistd.h>
using namespace std;
int time_delay=500;
class Source
{
public:
    Source()
    {

    }
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
};
class Source100:
 public Source{
    public:
    int dulieu100[100];
    int n= 100;
    Source100():Source()
    {
    }
    void laymangfile()
    {
        fstream fsFile;
        fsFile.open("D:\\Thuctapcoso\\dauvao100.txt", ios::in);
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
                this->dulieu100[i]=tam;
                i++;
            }
        }
 
        fsFile.close();
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
    int n= 250;
    Source250():Source()
    {
    }
    void laymangfile()
    {
        fstream fsFile;
        fsFile.open("D:\\Thuctapcoso\\dauvao250.txt", ios::in);
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
                this->dulieu250[i]=tam;
                i++;
            }
        }
 
        fsFile.close();
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
    int n= 500;
    Source500():Source()
    {
    }
     void laymangfile()
    {
        fstream fsFile;
        fsFile.open("D:\\Thuctapcoso\\dauvao500.txt", ios::in);
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
                this->dulieu500[i]=tam;
                i++;
            }
        }
 
        fsFile.close();
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
};
class SelectionSort: public Sort {
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

int main()
{
	SelectionSort ss100, ss250, ss500;
    TreeSort ts100, ts250, ts500;
    
    
    Source100 s;
    Source100 s100_1,s100_2;
    s100_1.laymangfile();
    s100_1.taomang(s100_1.dulieu100,s100_1.n);
    s100_2.laymangfile();
    s100_2.taomang(s100_2.dulieu100,s100_2.n);
    
    Source250 s250_1,s250_2;
    s250_1.laymangfile();
    s250_1.taomang(s250_1.dulieu250,s250_1.n);
    s250_2.laymangfile();
    s250_2.taomang(s250_2.dulieu250,s250_2.n);
    
    Source500 s500_1,s500_2;
    s500_1.laymangfile();
    s500_1.taomang(s500_1.dulieu500,s500_1.n);
    s500_2.laymangfile();
    s500_2.taomang(s500_2.dulieu500,s500_2.n);


	ss100.selectionSort(s100_1.dulieu100,s100_1.n);
	ss250.selectionSort(s250_1.dulieu250,s250_1.n);
	ss500.selectionSort(s500_1.dulieu500,s500_1.n);
	cout << "\nsize\t\t100\t250\t500";
	for (int i=0;i<10;i++)
	{
	cout<<"\n----------------------------------------------------";
	cout << "\nSelection Sort\t" << ss100.t_SelectionSort(s100_1.dulieu100,s100_1.n) << "\t" << ss250.t_SelectionSort(s250_1.dulieu250,s250_1.n) << "\t" << ss500.t_SelectionSort(s500_1.dulieu500,s500_1.n);
	cout << "\nTree Sort\t" << ts100.t_TreeSort(s100_1.dulieu100,s100_1.n) << "\t" << ts250.t_TreeSort(s250_1.dulieu250,s250_1.n) << "\t" << ts500.t_TreeSort(s500_1.dulieu500,s500_1.n);
	}
     getchar();
}


